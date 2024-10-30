#include "Plane.hpp"

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
 * @brief Gets the normal vector of the plane.
 * @return Vector3 The normal vector of the plane.
 */
Vector3 Plane::Normal() const
{
    return normal;
}

/**
 * @brief Gets the distance from the origin of the plane.
 * @return float The distance from the origin of the plane.
 */
float Plane::Distance() const
{
    return d;
}

/**
 * @brief Checks if a ray intersects with the plane.
 * @param ray The ray to check for intersection.
 * @return Intersection point if it exists, otherwise std::nullopt.
 */
std::optional<Vector3> Plane::intersects(const Ray &ray) const
{
    float denom = normal * ray.Direction();
    if (denom > -1e-6)
    {
        // The ray is parallel to the plane (denom == 0)
        // OR The angle between the the incoming ray and the normal is > 90°
        //    meaning the plane is behind us

        return std::nullopt;
    }

    float t = -(normal * ray.Origin()) + d / denom;

    Vector3 diff = normal - ray.Origin();
    float num = diff * normal;

    float t2 = num / denom;

    Vector3 p = ray.Origin() + ray.Direction() * t2;

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