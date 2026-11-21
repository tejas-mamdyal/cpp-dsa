/*
TRANSLATE A FORMULA INTO STEPS
Route: Reinforcement | Prerequisites: None; read 00-start-here first.

Pseudocode: read width and height; multiply them; display the product. Named variables
connect the formula to the problem.

O(1) time/space.

Units matter: lengths in centimetres produce square centimetres.
*/
#include <iostream>

int main() {
    int width = 0;
    int height = 0;
    std::cin >> width >> height;
    int area = width * height; // Separate processing from input/output.
    std::cout << area << '\n';
}
