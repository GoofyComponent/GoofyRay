#pragma once

#include "Color.hpp"
#include "Vector3.h"
#include "Ray.hpp"
#include <vector>
#include <iostream>

/**
 * @class Hittable
 * @brief Represents a 3D hittable object that can be intersected by a ray.
 */
class Hittable
{

public:
    virtual ~Hittable() = default;

    virtual std::optional<std::vector<Vector3>> intersects(const Ray &iRay) const = 0;
};
