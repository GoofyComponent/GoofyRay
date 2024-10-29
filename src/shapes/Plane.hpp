#pragma once

#include "../raymath/Vector3.h"
#include "../raymath/Ray.hpp"
#include "Hittable.hpp"

/**
 * @class Plane
 * @brief Represents a 3D plane with a normal vector and a distance from the origin.
 */
class Plane : public Hittable
{
private:
    Vector3 normal;
    float d;

public:
    /**
     * @brief Constructs a plane with a specified normal vector and distance from the origin.
     * @param normal Normal vector of the plane.
     * @param distance Distance from the origin.
     */
    Plane(const Vector3 &normal, float distance);

    /**
     * @brief Constructs a plane from a point on the plane and the normal vector.
     * @param point A point on the plane.
     * @param normal Normal vector of the plane.
     */
    Plane(const Vector3 &point, const Vector3 &normal);

    /**
     * @brief Gets the normal vector of the plane.
     * @return Vector3 The normal vector of the plane.
     */
    Vector3 Normal() const;

    /**
     * @brief Gets the distance from the origin of the plane.
     * @return float The distance from the origin of the plane.
     */
    float Distance() const;

    /**
     * @brief Checks if a ray intersects with the plane.
     * @param ray The ray to check for intersection.
     * @return Distance to the intersection point if it exists, otherwise std::nullopt.
     */
    std::optional<std::vector<Vector3>> intersects(const Ray &ray) const override;

    /**
     * @brief Overriding the output stream operator for Plane.
     *
     * This function outputs the plane's vertices and color to an output stream.
     *
     * @param _stream The output stream.
     * @param plane The Plane object to output.
     * @return std::ostream& A reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &_stream, const Plane &plane);
};
