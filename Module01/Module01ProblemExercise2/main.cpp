#include "car.h"
#include "sportscar.h"
#include <iostream>
#include <vector>

int main() {
    // Create a vector to store Car pointers
    std::vector<Car*> carFleet;

    // Create a regular Car object
    Car* regularCar = new Car("Toyota", "Camry", 2018);
    carFleet.push_back(regularCar);

    // Create a SportsCar object
    SportsCar* mySportsCar = new SportsCar("Ferrari", "488", 2020, 330.0f);
    carFleet.push_back(mySportsCar);

    // Demonstrate polymorphism: call drive() on each object
    std::cout << "\n--- Driving the Car Fleet ---\n";
    for (const auto& car : carFleet) {
        car->drive();
        std::cout << std::endl;
    }

    // Clean up: delete dynamically allocated objects
    for (auto car : carFleet) {
        delete car;
    }
    carFleet.clear();

    std::cout << "\nProgram finished. All cars cleaned up." << std::endl;
    return 0;
}
