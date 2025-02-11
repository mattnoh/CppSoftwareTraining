#include "parts.cpp"
using namespace std;

class Brakes : public Part {
public:
    // Constructors
    Brakes() : Part() {}

    // Parameterized Constructor
    Brakes(const string &name, const string &manufacturer)
        : Part() {
        this->name = name;
        this->manufacturer = manufacturer;
    }

    // Destructor
    ~Brakes() override {}

    // Copy Constructor
    Brakes(const Brakes &other) : Part(other) {}

    // Assignment Operator
    Brakes& operator=(const Brakes &other) {
        if (this != &other) {
            Part::operator=(other);
        }
        return *this;
    }

    // Member Functions
    void print() override {
        cout << "Brakes Name: " << name << ", Manufacturer: " << manufacturer << endl;
    }
    
    void activate() {
        cout << "Brakes activated!" << endl;
    }
};