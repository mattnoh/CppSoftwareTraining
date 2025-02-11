#include <iostream>
#include "engine.cpp"
#include "wheels.cpp"
#include "brakes.cpp"
using namespace std;

class Car {
private:
    Engine* engine_;
    Wheels* wheels_;
    Brakes* brakes_;

public:
    // Constructors
    Car() {
        engine_ = new Engine("V8", "Ford", "450 HP");
        wheels_ = new Wheels[4];
        for (int i = 0; i < 4; ++i) {
            wheels_[i] = Wheels("Roads", "Michelin", 18.0, 10.0 * (i + 1)); // Example wear percentages: 10%, 20%, 30%, 40%
        }
        brakes_ = new Brakes("Standard Brakes", "Brembo");
    }

    // Copy Constructor
    Car(const Car& other) {
        engine_ = new Engine(*other.engine_);
        wheels_ = new Wheels[4];
        for (int i = 0; i < 4; ++i) {
            wheels_[i] = other.wheels_[i];
        }
        brakes_ = new Brakes(*other.brakes_);
    }

    // Assignment Operator
    Car& operator=(const Car& other) {
        if (this != &other) {
            *engine_ = *other.engine_;
            for (int i = 0; i < 4; ++i) {
                wheels_[i] = other.wheels_[i];
            }
            *brakes_ = *other.brakes_;
        }
        return *this;
    }

    // Destructor
    ~Car() {
        delete engine_;
        delete[] wheels_;
        delete brakes_;
    }

    // Member Functions
    void printParts() {
        engine_->print();
        brakes_->print();
        double totalWearPercentage = 0.0;
        for (int i = 0; i < 4; ++i) {
            totalWearPercentage += wheels_[i].getWearPercentage();
        }
        double averageWearPercentage = totalWearPercentage / 4.0;
        cout << "Average Wheel Wear Percentage: " << averageWearPercentage << "%" << endl;
    }

    void activateBrakes() {
        brakes_->activate();
        for (int i = 0; i < 4; ++i) {
            wheels_[i].wearDown();
        }
    }

    // Getters
    Engine* getEngine() const {
        return engine_;
    }
    Wheels* getWheels() const {
        return wheels_;
    }
    Brakes* getBrakes() const {
        return brakes_;
    }
};