#include "Ray.hpp"

Ray::Ray(Vector3 origin, Vector3 direction) : origin(origin), direction(direction) {}

Vector3 Ray::Origin() const
{
    return origin;
}

Vector3 Ray::Direction() const
{
    return direction;
}

Vector3 Ray::At(double scale) const
{
    return origin + direction * scale;
}