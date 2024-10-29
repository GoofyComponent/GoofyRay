#include "Polygon.hpp"

/**
 * @brief Default constructor for a unit polygon with a black color.
 */
Polygon::Polygon() : vertices(), color(Color()) {}

/**
 * @brief Constructs a polygon with a specified list of vertices and color.
 * @param iVertices List of vertices defining the polygon.
 * @param iColor Color of the polygon.
 */
Polygon::Polygon(const std::vector<Vector3> &iVertices, const Color &iColor)
    : vertices(iVertices), color(iColor) {}

/**
 * @brief Destructor for the polygon.
 */
Polygon::~Polygon() {}

/**
 * @brief Gets the vertices of the polygon.
 * @return A vector of vertices defining the polygon.
 */
const std::vector<Vector3> &Polygon::getVertices() const
{
    return vertices;
}

/**
 * @brief Gets the color of the polygon.
 * @return Color of the polygon.
 */
Color Polygon::getColor() const
{
    return color;
}

/**
 * @brief Sets the color of the polygon.
 * @param iColor New color of the polygon.
 */
void Polygon::setColor(const Color &iColor)
{
    color = iColor;
}

/**
 * @brief Checks if a ray intersects with the polygon.
 * @param iRay The ray to check for intersection.
 * @return Returns a vector of point of intersection for each face of the polygon, otherwise returns std::nullopt.
 */
std::optional<Vector3> Polygon::intersects(const Ray &iRay) const
{
    if (vertices.size() < 3)
    {
        return std::nullopt;
    }

    std::vector<Vector3> intersectionPoints;

    // Loop over each triangle in the polygon (assuming a fan structure)
    for (size_t i = 1; i < vertices.size() - 1; ++i)
    {
        Vector3 v0 = vertices[0];
        Vector3 v1 = vertices[i];
        Vector3 v2 = vertices[i + 1];

        // Calculate edges of the triangle
        Vector3 edge1 = Vector3(v1.x - v0.x, v1.y - v0.y, v1.z - v0.z);
        Vector3 edge2 = Vector3(v2.x - v0.x, v2.y - v0.y, v2.z - v0.z);

        // Calculate the determinant using cross product
        Vector3 h = iRay.Direction.cross(edge2);
        float a = edge1 * h;

        // If a is close to 0, the ray is parallel to this triangle
        if (std::fabs(a) < std::numeric_limits<float>::epsilon())
            continue;

        float f = 1.0 / a;
        Vector3 s = Vector3(iRay.Origin.x - v0.x, iRay.Origin.y - v0.y, iRay.Origin.z - v0.z);
        float u = f * s * h;

        // Check if intersection is outside the triangle
        if (u < 0.0 || u > 1.0)
            continue;

        Vector3 q = s.cross(edge1);
        float v = f * iRay.Direction * q;

        // Check if intersection is outside the triangle
        if (v < 0.0 || u + v > 1.0)
            continue;

        // Calculate the distance t along the ray to the intersection point
        float t = f * edge2 * q;

        // Intersection occurs if t > 0 (in front of the ray's origin)
        if (t > std::numeric_limits<float>::epsilon())
        {
            Vector3 intersectionPoint = Vector3(
                iRay.Origin.x + iRay.Direction.x * t,
                iRay.Origin.y + iRay.Direction.y * t,
                iRay.Origin.z + iRay.Direction.z * t);
            intersectionPoints.push_back(intersectionPoint);
        }
    }

    // If there are intersection points, return them; otherwise, return std::nullopt
    if (!intersectionPoints.empty())
    {
        return intersectionPoints;
    }
    else
    {
        return std::nullopt;
    }
}

/**
 * @brief Overriding the output stream operator for Polygon.
 *
 * This function outputs the polygon's vertices and color to an output stream.
 *
 * @param _stream The output stream.
 * @param polygon The Polygon object to output.
 * @return std::ostream& A reference to the output stream.
 */
std::ostream &operator<<(std::ostream &_stream, const Polygon &polygon)
{
    _stream << "Polygon with " << polygon.vertices.size() << " vertices:\n";
    for (const auto &vertex : polygon.vertices)
    {
        _stream << vertex << " ";
    }
    _stream << "\nColor: " << polygon.color;
    return _stream;
}
