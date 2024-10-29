#pragma once
#include "Vector3.h"

class Ray
{
private:
    Vector3 origin;
    Vector3 direction;

public:
    // Constructor that normalizes the direction to ensure unit length
    Ray(Vector3 origin, Vector3 direction);

    // Accessor methods
    Vector3 Origin() const;
    Vector3 Direction() const;

    // Method to get a point at a specific distance along the ray
    Vector3 At(double scale) const;
};
