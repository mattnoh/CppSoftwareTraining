#include <iostream>
#include <string>

class Car {
private:
    std::string name;
    std::string model;
    float year;

public:
    // Default constructor
    Car() : name("Unnamed"), model("unspecified"), year(0.0f) {
        std::cout << "Default constructor called." << std::endl;
    }

    // Parameterized constructor
    Car(std::string carName, std::string carModel, float carYear) 
        : name(carName), model(carModel), year(carYear) {
        std::cout << "Parameterized constructor called: " 
                  << name << ", " << model << ", " << year << std::endl;
    }

    // Copy constructor
    Car(const Car& car) : name(car.name), model(car.model), year(car.year) {
        std::cout << "Copy constructor called for: " 
                  << name << ", " << model << ", " << year << std::endl;
    }

    // Copy assignment operator
    Car& operator=(const Car& rhs) {
        std::cout << "Copy assignment operator called." << std::endl;
        if (this != &rhs) { // Avoid self-assignment
            name = rhs.name;
            model = rhs.model;
            year = rhs.year;
        }
        return *this;
    }

    // Destructor
    virtual ~Car() {
        std::cout << "Destructor called for: " << name << std::endl;
    }

    // Getters
    std::string getName() const { return name; }
    std::string getModel() const { return model; }
    float getYear() const { return year; }

    // Setters
    void setName(const std::string& carName) { name = carName; }
    void setModel(const std::string& carModel) { model = carModel; }
    void setYear(float carYear) { year = carYear; }

    // Drive method to print car details
    virtual void drive() const {
        std::cout << "Driving " << name << " " << model << " " << year << std::endl;
    }
};

class SportsCar : public Car {
private:
    float TSpeed; // Member variable for top speed

public:
    // Default constructor
    SportsCar() : Car(), TSpeed(0.0) {
        std::cout << "Default constructor for SportsCar called." << std::endl;
    }

    // Parameterized constructor
    SportsCar(std::string carName, std::string carModel, float carYear, float topspeed) 
        : Car(carName, carModel, carYear), TSpeed(topspeed) {
        std::cout << "Parameterized constructor for SportsCar called: "
                  << carName << ", " << carModel << ", " << carYear << ", " << topspeed << " km/h" << std::endl;
    }

    // Drive method
    void drive() const override {
        Car::drive(); // Call base class drive method
        std::cout << "Top Speed: " << TSpeed << " km/h" << std::endl;
    }
};

// Main function to demonstrate the Car and SportsCar classes
int main() {
    // Create car objects
    Car car1("Hyundai", "Sonata", 2020); // Parameterized constructor
    car1.drive();

    // Create SportsCar object
    SportsCar sportscar1("BMW", "E36", 1993, 250.0);
    sportscar1.drive();

    return 0;
}
