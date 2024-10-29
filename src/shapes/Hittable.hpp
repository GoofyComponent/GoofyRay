#pragma once

#include "../raymath/Color.hpp"
#include "../raymath/Vector3.h"
#include "../raymath/Ray.hpp"
#include <vector>

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
