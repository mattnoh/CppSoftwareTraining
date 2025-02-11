#include <iostream>
#include "parts.cpp"
using namespace std;

class Engine : public Part {
protected:
    string horsepower;

public:

    // Constructors
    Engine() : Part(), horsepower("") {}
    
    // Parameterized Constructor
    Engine(const string &name, const string &manufacturer, const string &horsepower)
        : Part(), horsepower(horsepower) {
        this->name = name;
        this->manufacturer = manufacturer;
    }

    // Destructor
    ~Engine() override {}
    
    // Copy Constructor
    Engine(const Engine &other) : Part(other), horsepower(other.horsepower) {}
    Engine& operator=(const Engine &other) {
        if (this != &other) {
            Part::operator=(other);
            horsepower = other.horsepower;
        }
        return *this;
    }

    // Member Functions
    void print() override {
        cout << "Engine Name: " << name << ", Manufacturer: " << manufacturer << ", Horsepower: " << horsepower << endl;
    }
};