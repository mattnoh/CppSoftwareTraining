#include "car.cpp"
using namespace std;

int main() {
    Car myCar;
    char input;

    while (true) {
        cout << "Press 'b' to activate brakes, 'p' to print car parts, 'q' to quit: ";
        cin >> input;

        if (input == 'b') {
            myCar.activateBrakes();
        } else if (input == 'p') {
            myCar.printParts();
        } else if (input == 'q') {
            break;
        } else {
            cout << "Invalid input. Please try again." << endl;
        }
    }

    return 0;
}
