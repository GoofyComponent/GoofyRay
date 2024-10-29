#pragma once

#include "Vector3.hpp"
#include "Ray.hpp"
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
     * @brief Default constructor that creates a plane with a normal vector pointing up and a distance of 0.
     */
    Plane();

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
     * @brief Checks if a ray intersects with the plane.
     * @param ray The ray to check for intersection.
     * @return Distance to the intersection point if it exists, otherwise std::nullopt.
     */
    std::optional<float> intersect(const Ray &ray) const override;

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
