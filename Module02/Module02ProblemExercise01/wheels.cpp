#include "parts.cpp"
using namespace std;

class Wheels : public Part {
protected:
    double diameter;
    double wearPercentage;

public:

    // Constructors
    Wheels() : Part(), diameter(0.0), wearPercentage(0.0) {}
    
    // Parameterized Constructor
    Wheels(const string &name, const string &manufacturer, double diameter, double wearPercentage)
        : Part(), diameter(diameter), wearPercentage(wearPercentage) {
        this->name = name;
        this->manufacturer = manufacturer;
    }

    // Destructor
    ~Wheels() override {}

    // Copy Constructor
    Wheels(const Wheels &other) : Part(other), diameter(other.diameter), wearPercentage(other.wearPercentage) {}
    
    // Assignment Operator
    Wheels& operator=(const Wheels &other) {
        if (this != &other) {
            Part::operator=(other);
            diameter = other.diameter;
            wearPercentage = other.wearPercentage;
        }
        return *this;
    }

    // Member Functions
    double getWearPercentage() const {
        return wearPercentage;
    }

    // Wear down the wheels
    void wearDown() {
        if (wearPercentage < 100.0) {
            wearPercentage += 1.0;
        }
    }
    void print() override {
        cout << "Wheel Name: " << name << ", Manufacturer: " << manufacturer << ", Diameter: " << diameter << ", Wear Percentage: " << wearPercentage << "%" << endl;
    }
};