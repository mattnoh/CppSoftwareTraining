#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>

class Car {
private:
    std::string name;
    std::string model;
    float year;

public:
    // Constructors
    Car();
    Car(const std::string& carName, const std::string& carModel, float carYear);

    // Copy constructor and assignment operator if needed
    Car(const Car& other);
    Car& operator=(const Car& other);

    // Virtual destructor for proper cleanup
    virtual ~Car();

    // Inline getters and setters for brevity
    std::string getName() const { return name; }
    void setName(const std::string& carName) { name = carName; }
    std::string getModel() const { return model; }
    void setModel(const std::string& carModel) { model = carModel; }
    float getYear() const { return year; }
    void setYear(float carYear) { year = carYear; }

    // Virtual drive method to support polymorphism
    virtual void drive() const;
};

#endif // CAR_H
