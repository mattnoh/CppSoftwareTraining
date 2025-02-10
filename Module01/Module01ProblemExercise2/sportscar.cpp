#include "sportscar.h"

// Default constructor
SportsCar::SportsCar() : Car(), topSpeed(0.0f) {
    std::cout << "[SportsCar] Default constructor called." << std::endl;
}

// Parameterized constructor
SportsCar::SportsCar(const std::string& carName, const std::string& carModel, float carYear, float tSpeed)
    : Car(carName, carModel, carYear), topSpeed(tSpeed) {
    std::cout << "[SportsCar] Parameterized constructor called: " << carName << ", " << carModel 
              << ", " << carYear << ", Top Speed: " << topSpeed << " km/h" << std::endl;
}

// Overridden drive() method
void SportsCar::drive() const {
    // Call the base class drive() to display generic information
    Car::drive();
    // Then display sports car-specific information
    std::cout << "[SportsCar] Top Speed: " << topSpeed << " km/h" << std::endl;
}

// Destructor
SportsCar::~SportsCar() {
    std::cout << "[SportsCar] Destructor called." << std::endl;
}
