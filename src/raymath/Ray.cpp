#include "Ray.hpp"

// Constructor that initializes the direction
Ray::Ray(Vector3 origin, Vector3 direction) : origin(origin){
    this->direction = direction.normalized();
}

// Accessor methods
Vector3 Ray::Origin() const {
    return origin;
}

Vector3 Ray::Direction() const {
    return direction;
}

// At method to get a point along the ray
Vector3 Ray::At(double scale) const {
    return origin + (direction * scale);
}
