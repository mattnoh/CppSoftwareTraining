#include "car.h"

// Default constructor
Car::Car() : name("Unnamed"), model("Unspecified"), year(0.0f) {
    std::cout << "[Car] Default constructor called." << std::endl;
}

// Parameterized constructor
Car::Car(const std::string& carName, const std::string& carModel, float carYear)
    : name(carName), model(carModel), year(carYear) {
    std::cout << "[Car] Parameterized constructor called: " << name << ", " << model << ", " << year << std::endl;
}

// Copy constructor
Car::Car(const Car& other) : name(other.name), model(other.model), year(other.year) {
    std::cout << "[Car] Copy constructor called." << std::endl;
}

// Copy assignment operator
Car& Car::operator=(const Car& other) {
    if (this != &other) {
        name = other.name;
        model = other.model;
        year = other.year;
    }
    std::cout << "[Car] Copy assignment operator called." << std::endl;
    return *this;
}

// Virtual destructor
Car::~Car() {
    std::cout << "[Car] Destructor called for: " << name << std::endl;
}

// drive() method: basic implementation
void Car::drive() const {
    std::cout << "[Car] Driving: " << name << " " << model << " (" << year << ")" << std::endl;
}
