/*
 Each input line is one independent integer expression of at most200
bytes. Decimal literals are0..1000000. Support whitespace, unary +/-, binary
+,-,*,/ and parentheses. Intermediate results must lie in[-10^12,10^12]. Integer
division truncates toward zero. Print the value or an explicit error; continue
with subsequent lines. Empty input produces no output; an empty line is invalid.

GRAMMAR: expression = term { ('+'|'-') term }
term = factor { ('*'|'/') factor }
factor = number | '(' expression ')' | ('+'|'-') factor
The grammar teaches precedence before the parser uses it. Repetition is evaluated
left-to-right, so8/4/2 is1. Recursive factors explain unary signs and nesting.

STATE: Parser::position names the next unread byte. Each returned unique_ptr owns
one complete expression subtree. Parsing a term before '+' is why multiplication
binds more tightly than addition. Baseline repeated string splitting tends to
mishandle nesting and unary signs; explicit grammar removes that ambiguity.

2+3*4 builds +(2,*(3,4)). Postorder evaluates3*4=12,then2+12=14.
(2+3)*4 instead builds *(+(2,3),4) and produces20. -7/2 produces -3.

Each grammar production consumes exactly its legal token sequence.
Child trees represent its operands; postorder applies the parent only after both
operand results are valid. Full consumption rejects trailing junk. Bound checks
happen before multiplication, so overflow cannot precede the diagnostic.

O(L) parsing/evaluation time, O(L) AST storage and recursion depth in the
worst case; the200-byte limit keeps nested input and destruction bounded.

Unary '-' is not a missing left operand. Division by zero is checked
before division. Owned partial trees clean up on syntax errors. This is an integer
language, not floating-point C++ or a general-purpose compiler.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <optional>
#include <utility>
#include <memory>
#include <cstdlib>
#include <cctype>
#include <cstddef>

struct Expression {
    char operation;
    long long literal = 0;
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;

    explicit Expression(char op)
        : operation(op) {
    }
};

using Tree = std::unique_ptr<Expression>;

class Parser {
    const std::string& text;
    std::size_t position = 0;

    void whitespace() {
        while (position < text.size() && std::isspace(static_cast<unsigned char>(text[position]))) {
            ++position;
        }
    }

    Tree factor() {
        whitespace();
        if (position == text.size()) {
            return nullptr;
        }
        char ch = text[position];
        if (ch == '+' || ch == '-') {
            ++position;
            auto child = factor();
            if (!child) {
                return nullptr;
            }
            if (ch == '+') {
                return child;
            }
            auto root = std::make_unique<Expression>('~');
            root->left = std::move(child); // '~' is the internal unary-negation tag.
            return root;
        }
        if (ch == '(') {
            ++position;
            auto root = expression();
            whitespace();
            if (!root || position == text.size() || text[position] != ')') {
                return nullptr;
            }
            ++position;
            return root;
        }
        if (ch < '0' || ch > '9') {
            return nullptr;
        }
        long long value = 0;
        while (position < text.size() && text[position] >= '0' && text[position] <= '9') {
            int digit = text[position] - '0';
            if (value > (1000000 - digit) / 10) {
                return nullptr; // Reject before multiplying an oversized literal.
            }
            value = value * 10 + digit;
            ++position;
        }
        auto root = std::make_unique<Expression>('n');
        root->literal = value;
        return root;
    }

    Tree term() {
        auto left = factor();
        if (!left) {
            return nullptr;
        }
        while (true) {
            whitespace();
            if (position == text.size() || (text[position] != '*' && text[position] != '/')) {
                return left;
            }
            char op = text[position];
            ++position;
            auto right = factor();
            if (!right) {
                return nullptr;
            }
            auto root = std::make_unique<Expression>(op);
            root->left = std::move(left);
            root->right = std::move(right);
            left = std::move(root); // Fold left to preserve left associativity.
        }
    }

    Tree expression() {
        auto left = term();
        if (!left) {
            return nullptr;
        }
        while (true) {
            whitespace();
            if (position == text.size() || (text[position] != '+' && text[position] != '-')) {
                return left;
            }
            char op = text[position];
            ++position;
            auto right = term();
            if (!right) {
                return nullptr;
            }
            auto root = std::make_unique<Expression>(op);
            root->left = std::move(left);
            root->right = std::move(right);
            left = std::move(root);
        }
    }

public:
    explicit Parser(const std::string& source)
        : text(source) {
    }

    Tree parse() {
        if (text.size() > 200) {
            return nullptr;
        }
        auto root = expression();
        whitespace();
        if (position != text.size()) {
            return nullptr;
        }
        return root;
    }
};

constexpr long long RESULT_LIMIT = 1000000000000LL;

std::optional<long long> evaluateTree(const Expression* root, std::string& error) {
    if (root->operation == 'n') {
        return root->literal;
    }
    auto left = evaluateTree(root->left.get(), error);
    if (!left) {
        return std::nullopt;
    }
    if (root->operation == '~') {
        return -*left; // Every child result is already within the symmetric bound.
    }
    auto right = evaluateTree(root->right.get(), error);
    if (!right) {
        return std::nullopt;
    }
    long long value = 0;
    if (root->operation == '+') {
        value = *left + *right; // At most2*10^12, safely within long long.
    } else if (root->operation == '-') {
        value = *left - *right;
    } else if (root->operation == '*') {
        if (*right != 0 && std::abs(*left) > RESULT_LIMIT / std::abs(*right)) {
            error = "result out of range";
            return std::nullopt;
        }
        value = *left * *right;
    } else {
        if (*right == 0) {
            error = "division by zero";
            return std::nullopt;
        }
        value = *left / *right;
    }
    if (value < -RESULT_LIMIT || value > RESULT_LIMIT) {
        error = "result out of range";
        return std::nullopt;
    }
    return value;
}

struct Result {
    std::optional<long long> value;
    std::string error;
};

Result evaluate(const std::string& source) {
    Parser parser(source);
    auto root = parser.parse();
    if (!root) {
        return {std::nullopt, "invalid expression"};
    }
    std::string error;
    auto value = evaluateTree(root.get(), error);
    return {value, error};
}

int main() {
    assert(evaluate("2+3*4").value == 14);
    assert(evaluate("(2+3)*4").value == 20);
    assert(evaluate("-7/2").value == -3);
    assert(evaluate("8/4/2").value == 1);
    assert(evaluate("1/(2-2)").error == "division by zero");
    assert(!evaluate("2(3)").value);
    std::string line;
    while (std::getline(std::cin, line)) {
        auto result = evaluate(line);
        if (result.value) {
            std::cout << *result.value << '\n';
        } else {
            std::cout << "error: " << result.error << '\n';
        }
    }
    return 0;
}
