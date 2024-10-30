#pragma once

#include "../raymath/Color.hpp"
#include "../raymath/Vector3.h"
#include "../raymath/Ray.hpp"
#include <vector>

/**
 * @class Object
 * @brief Represents a 3D object object that can be intersected by a ray.
 */
class Object
{
public:
    virtual ~Object() = default;

    virtual std::optional<Vector3> intersects(const Ray &iRay) const = 0;

    virtual Color getColor() const = 0;

    virtual Vector3 getNormal(const Vector3 &point) const = 0;
};
