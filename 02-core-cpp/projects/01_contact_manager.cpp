/*
PERSISTENT CONTACT MANAGER
Prerequisites: records/classes, maps, quoted fields, file streams and validation.
Contract: one command per line. ADD/UPDATE id "name" "phone", FIND/DELETE id,
LIST, SAVE, LOAD, QUIT. IDs are 1..1000000; name length 1..80, phone 1..32;
at most 1000 records. Quoted text may contain spaces and escaped quotes.
Storage is build/contacts.txt; create build before running. SAVE overwrites.
An unknown command, invalid record, duplicate ADD or absent UPDATE/DELETE is an
error: diagnostic on stderr, exit 1. FIND absence prints NOT FOUND. EOF ends normally.
LOAD rejects malformed/duplicate records and commits only a completely valid file.
Trace: ADD 2 "Ada Lovelace" "123" -> ADDED; SAVE -> SAVED; DELETE 2 -> DELETED;
LOAD -> LOADED; FIND 2 -> 2 "Ada Lovelace" "123".
Model validation, command interpretation and persistence are separate functions.
map gives deterministic ascending-ID listing and O(log n) CRUD. Save/load perform
O(total text + n log n) work; memory is O(total stored text). Temporary loading
uses another O(total stored text) allocation. Direct SAVE is not crash-atomic.
Practice: add a phone-format policy, atomic replacement and search-by-name.
*/
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <utility>

struct Contact {
    int id = 0;
    std::string name;
    std::string phone;
};

bool valid(const Contact& contact) {
    return contact.id >= 1 && contact.id <= 1000000 && !contact.name.empty()
           && contact.name.size() <= 80 && !contact.phone.empty() && contact.phone.size() <= 32;
}

bool finished(std::istringstream& input) {
    char extra = ' ';
    return !(input >> extra);
}

bool readContact(std::istringstream& input, Contact& contact) {
    return static_cast<bool>(input >> contact.id >> std::quoted(contact.name)
                             >> std::quoted(contact.phone))
           && valid(contact) && finished(input);
}

void writeContact(std::ostream& output, const Contact& contact) {
    output << contact.id << ' ' << std::quoted(contact.name) << ' ' << std::quoted(contact.phone)
           << '\n';
}

bool save(const std::map<int, Contact>& contacts) {
    std::ofstream output("build/contacts.txt");
    if (!output) {
        return false;
    }
    for (const auto& entry : contacts) {
        writeContact(output, entry.second);
    }
    output.close();
    return static_cast<bool>(output);
}

bool load(std::map<int, Contact>& contacts) {
    std::ifstream input("build/contacts.txt");
    if (!input) {
        return false;
    }
    std::map<int, Contact> candidate;
    std::string line;
    while (std::getline(input, line)) {
        Contact contact;
        std::istringstream record(line);
        if (!readContact(record, contact) || candidate.size() == 1000
            || !candidate.emplace(contact.id, contact).second) {
            return false;
        }
    }
    if (!input.eof()) {
        return false;
    }
    // The old collection remains untouched until the whole file is valid.
    contacts = std::move(candidate);
    return true;
}

bool execute(const std::string& line, std::map<int, Contact>& contacts, bool& quit) {
    std::istringstream input(line);
    std::string command;
    if (!(input >> command)) {
        return false;
    }
    if (command == "ADD" || command == "UPDATE") {
        Contact contact;
        if (!readContact(input, contact)) {
            return false;
        }
        auto found = contacts.find(contact.id);
        if (command == "ADD") {
            if (found != contacts.end() || contacts.size() == 1000) {
                return false;
            }
            contacts.emplace(contact.id, contact);
            std::cout << "ADDED\n";
        } else {
            if (found == contacts.end()) {
                return false;
            }
            found->second = contact;
            std::cout << "UPDATED\n";
        }
        return true;
    }
    if (command == "FIND" || command == "DELETE") {
        int id = 0;
        if (!(input >> id) || id < 1 || id > 1000000 || !finished(input)) {
            return false;
        }
        auto found = contacts.find(id);
        if (command == "FIND") {
            if (found == contacts.end()) {
                std::cout << "NOT FOUND\n";
            } else {
                writeContact(std::cout, found->second);
            }
        } else {
            if (found == contacts.end()) {
                return false;
            }
            contacts.erase(found);
            std::cout << "DELETED\n";
        }
        return true;
    }
    if (!finished(input)) {
        return false;
    }
    if (command == "LIST") {
        for (const auto& entry : contacts) {
            writeContact(std::cout, entry.second);
        }
    } else if (command == "SAVE") {
        if (!save(contacts)) {
            return false;
        }
        std::cout << "SAVED\n";
    } else if (command == "LOAD") {
        if (!load(contacts)) {
            return false;
        }
        std::cout << "LOADED\n";
    } else if (command == "QUIT") {
        quit = true;
    } else {
        return false;
    }
    return true;
}

int main() {
    std::map<int, Contact> contacts;
    std::string line;
    bool quit = false;
    while (!quit && std::getline(std::cin, line)) {
        if (!execute(line, contacts, quit)) {
            std::cerr << "Invalid command, record or storage operation.\n";
            return 1;
        }
    }
    if (std::cin.bad()) {
        std::cerr << "Input read failed.\n";
        return 1;
    }
    return 0;
}
