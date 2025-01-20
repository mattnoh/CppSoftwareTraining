#include <iostream>
#include <string>

class Car {
private:
    std::string name; 
    float Year;      

public:
    // Default constructor
    Car() : name("Unnamed"), Year(0.0f) {
        std::cout << "Default constructor called: " << name << ", Year: " << Year << std::endl;
    }

    // Parameterized constructor
    Car(const std::string& carname, float carYear) : name(carname), Year(carYear) {
        std::cout << "Parameterized constructor called: " << name << ", Year: " << Year << std::endl;
    }

    // Copy constructor
    Car(const Car& src) : name(src.name), Year(src.Year) {
        std::cout << "Copy constructor called: " << name << ", Year: " << Year << std::endl;
    }

    // Copy assignment operator
    Car& operator=(const Car& rhs) {
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &rhs) { // Avoid self-assignment
            name = rhs.name;
            Year = rhs.Year;
        }
        return *this;
    }

    // Destructor
    ~Car() {
        std::cout << "Destructor called for: " << name << std::endl;
    }

    // Getter for name
    std::string getname() const { return name; }

    // Getter for Year
    float getYear() const { return Year; }

    // Setter for name
    void setname(const std::string& carname) { name = carname; }

    // Setter for Year
    void setYear(float carYear) { Year = carYear; }
};

// Main function to demonstrate the Car class
int main() {
    // Default constructor
    Car car1;

    // Parameterized constructor
    Car car2("BMW", 300.0f);

    // Copy constructor
    Car car3(car2);

    // Using copy assignment operator
    car1 = car2;

    // Modify and display car1
    car1.setname("Tesla");
    car1.setYear(200.0f);

    std::cout << "Car1: " << car1.getname() << ", Year: " << car1.getYear() << std::endl;
    std::cout << "Car2: " << car2.getname() << ", Year: " << car2.getYear() << std::endl;
    std::cout << "Car3: " << car3.getname() << ", Year: " << car3.getYear() << std::endl;

    return 0;
}
