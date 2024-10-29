#include "Sphere.hpp"

/**
 * @brief Constructs a sphere with a specified center, radius, and color.
 * @param iOrigin Center of the sphere.
 * @param iRadius Radius of the sphere.
 * @param iColor Color of the sphere.
 */
Sphere::Sphere(Vector3 iOrigin, float iRadius, const Color &iColor)
    : origin(iOrigin), radius(iRadius), color(iColor) {}

/**
 * @brief Destructor for the sphere.
 */
Sphere::~Sphere() {}

/**
 * @brief Gets the center of the sphere.
 * @return Center of the sphere.
 */
Vector3 Sphere::Origin() const
{
    return origin;
};

/**
 * @brief Gets the radius of the sphere.
 * @return Radius of the sphere.
 */
float Sphere::Radius() const
{
    return radius;
}

/**
 * @brief Gets the color of the sphere.
 * @return Color of the sphere.
 */
Color Sphere::getColor() const
{
    return color;
}

/**
 * @brief Checks if a ray intersects with the sphere.
 * @param iRay The ray to check for intersection.
 * @return Returns the point of intersection if the ray intersects with the sphere, otherwise returns std::nullopt.
 */
std::optional<std::vector<Vector3>> Sphere::intersects(const Ray &iRay) const
{

    Vector3 oc = origin - iRay.Origin();

    // Calculate the dot product which is just a float
    Vector3 dotProd = oc * iRay.Direction();

    // Multiply the dot product with the ray's direction vector
    Vector3 op = dotProd * iRay.Direction();

    Vector3 p = iRay.Origin() + op;

    // Displacement vector from c to p
    Vector3 cp = p - origin;

    // calculate the length of a vector using pythagorus !
    double distance = cp.length();

    // No intersection if the distance from between P and C
    // is greater than the radius of our sphere!
    if (distance > radius)
    {
        return std::nullopt;
    }

    double a = std::sqrt(radius * radius - distance * distance);

    Vector3 p1 = p + ((-iRay.Direction()) * a);

    std::vector<Vector3> intersectionPoints;
    intersectionPoints.push_back(p1);

    return intersectionPoints;
}

/**
 * @brief Sets the center of the sphere.
 * @param iOrigin New center of the sphere.
 */
void Sphere::setOrigin(Vector3 iOrigin)
{
    origin = iOrigin;
}

/**
 * @brief Sets the radius of the sphere.
 * @param iRadius New radius of the sphere.
 */
void Sphere::setRadius(float iRadius)
{
    radius = iRadius;
}

/**
 * @brief Sets the color of the sphere.
 * @param iColor New color of the sphere.
 */
void Sphere::setColor(const Color &iColor)
{
    color = iColor;
}

/**
 * @brief Overloaded stream insertion operator to output the sphere's properties.
 * @param _stream The output stream.
 * @param sphere The sphere to output.
 * @return The output stream.
 */
std::ostream &operator<<(std::ostream &_stream, const Sphere &sphere)
{
    _stream << "Sphere: " << std::endl;
    _stream << "Center: " << sphere.Origin() << std::endl;
    _stream << "Radius: " << sphere.Radius() << std::endl;
    _stream << "Color: " << sphere.getColor() << std::endl;
    return _stream;
}