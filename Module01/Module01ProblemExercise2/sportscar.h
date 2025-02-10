#ifndef SPORTSCAR_H
#define SPORTSCAR_H

#include "car.h"

class SportsCar : public Car {
private:
    float topSpeed; // Top speed in km/h

public:
    // Constructors
    SportsCar();
    SportsCar(const std::string& carName, const std::string& carModel, float carYear, float tSpeed);

    // Override drive() to include sports car details
    virtual void drive() const override;

    // Destructor
    virtual ~SportsCar();
};

#endif // SPORTSCAR_H
