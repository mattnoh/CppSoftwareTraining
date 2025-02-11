#ifndef PARTS_CPP
#define PARTS_CPP

#include <iostream>
using namespace std;

class Part {
protected:
    string name;
    string manufacturer;

public:
    Part() : name(""), manufacturer("") {}
    virtual ~Part() {}
    Part(const Part &other) : name(other.name), manufacturer(other.manufacturer) {}
    Part& operator=(const Part &other) {
        if (this == &other) {
            return *this;
        }
        name = other.name;
        manufacturer = other.manufacturer;
        return *this;
    }
    virtual void print() = 0;
};

#endif // PARTS_CPP