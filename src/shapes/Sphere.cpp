#include "Sphere.hpp"

/**
 * @brief Default constructor for a unit sphere at the origin with a black color.
 */
Sphere::Sphere() : x(0), y(0), z(0), radius(1), color(Color()) {}

/**
 * @brief Constructs a sphere with a specified center, radius, and color.
 * @param iX X-coordinate of the center.
 * @param iY Y-coordinate of the center.
 * @param iZ Z-coordinate of the center.
 * @param iRadius Radius of the sphere.
 * @param iColor Color of the sphere.
 */
Sphere::Sphere(float iX, float iY, float iZ, float iRadius, const Color &iColor)
    : x(iX), y(iY), z(iZ), radius(iRadius), color(iColor) {}

/**
 * @brief Destructor for the sphere.
 */
Sphere::~Sphere() {}

/**
 * @brief Gets the X-coordinate of the center.
 * @return X-coordinate of the center.
 */
float Sphere::getX() const
{
    return x;
}

/**
 * @brief Gets the Y-coordinate of the center.
 * @return Y-coordinate of the center.
 */
float Sphere::getY() const
{
    return y;
}

/**
 * @brief Gets the Z-coordinate of the center.
 * @return Z-coordinate of the center.
 */
float Sphere::getZ() const
{
    return z;
}

/**
 * @brief Gets the radius of the sphere.
 * @return Radius of the sphere.
 */
float Sphere::getRadius() const
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
std::optional<Vector3> Sphere::intersects(const Ray &iRay) const
{
    c = Vector3(x, y, z);

    oc = c - iRay.Origin;

    // Calculate the dot product which is just a float
    dotProd = (oc.x * iRay.Direction.x) + (oc.y * iRay.Direction.y) + (oc.z * iRay.Direction.z);

    // Multiply the dot product with the ray's direction vector
    op = dotProd *iRay.Direction = (dotProd * iRay.Direction.x, dotProd * iRay.Direction.y, dotProd * iRay.Direction.z);

    p = iRay.Origin + op;

    // Displacement vector from c to p
    cp = p - c;

    // calculate the length of a vector using pythagorus !
    distance = cp.length();

    // No intersection if the distance from between P and C
    // is greater than the radius of our sphere!
    if (distance < radius)
    {
        return std::nullopt;
    }

    a = Math.sqrt(radius * radius - distance * distance);

    p1 = p + (a * -iRay.Direction);

    return p1
}

/**
 * @brief Sets the center of the sphere.
 * @param iX New X-coordinate of the center.
 * @param iY New Y-coordinate of the center.
 * @param iZ New Z-coordinate of the center.
 */
void Sphere::setCenter(float iX, float iY, float iZ)
{
    x = iX;
    y = iY;
    z = iZ;
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
 * @brief Overriding the output stream operator for Sphere.
 *
 * This function outputs the sphere's center coordinates, radius, and color to an output stream.
 *
 * @param _stream The output stream.
 * @param sphere The Sphere object to output.
 * @return std::ostream& A reference to the output stream.
 */
std::ostream &operator<<(std::ostream &_stream, const Sphere &sphere)
{
    _stream << "Sphere(Center: (" << sphere.x << ", " << sphere.y << ", " << sphere.z
            << "), Radius: " << sphere.radius
            << ", Color: " << sphere.color << ")";
    return _stream;
}
