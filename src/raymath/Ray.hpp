#pragma once

#include "Vector3.h"

class Ray {
private:
    Vector3 origin;
    Vector3 direction;

public:
    Ray(Vector3 origin, Vector3 direction);

    Vector3 Origin() const;
    Vector3 Direction() const;

    Vector3 At(double scale) const;
};
