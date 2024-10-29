#include "Plane.hpp"

/**
 * @brief Default constructor that creates a plane with a normal vector pointing up and a distance of 0.
 */
Plane::Plane()
    : normal(Vector3(0, 1, 0)), d(0)
{
}

/**
 * @brief Constructs a plane with a specified normal vector and distance from the origin.
 * @param normal Normal vector of the plane.
 * @param distance Distance from the origin.
 */
Plane::Plane(const Vector3 &normal, float distance)
{
    this->normal.normalized();
}

/**
 * @brief Constructs a plane from a point on the plane and the normal vector.
 * @param point A point on the plane.
 * @param normal Normal vector of the plane.
 */
Plane::Plane(const Vector3 &point, const Vector3 &normal)
{
    this->normal.normalized();
    d = -this->normal * point;
}

/**
 * @brief Checks if a ray intersects with the plane.
 * @param ray The ray to check for intersection.
 * @return Distance to the intersection point if it exists, otherwise std::nullopt.
 */
std::optional<float> Plane::intersect(const Ray &ray) const
{
    float denom = normal * ray.direction;
    if (denom > -1e-6)
    {
        // The ray is parallel to the plane (denom == 0)
        // OR The angle between the the incoming ray and the normal is > 90°
        //    meaning the plane is behind us

        return std::nullopt;
    }

    float t = -(normal * ray.origin) + d / denom;

    Vector3 diff = plane.c - ray.o;
    float num = diff.dot(plane.n);

    float t = num / denom;

    Vector3 p = ray.o + ray.d * t;

    return p;
}

/**
 * @brief Overriding the output stream operator for Plane.
 *
 * This function outputs the plane's vertices and color to an output stream.
 *
 * @param _stream The output stream.
 * @param plane The Plane object to output.
 * @return std::ostream& A reference to the output stream.
 */
std::ostream &operator<<(std::ostream &_stream, const Plane &plane)
{
    _stream << "Plane with normal: " << plane.normal << " and distance: " << plane.d;
    return _stream;
}