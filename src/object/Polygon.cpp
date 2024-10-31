#include "Polygon.hpp"


Polygon::Polygon(const std::vector<Vector3> &iVertices, const Color &iColor, double reflectivity) :
    vertices(iVertices), Object(iColor, reflectivity) {}

Polygon::~Polygon() = default;

const std::vector<Vector3> &Polygon::Vertices() const { return vertices; }

Color Polygon::getColor() const { return color; }

void Polygon::setColor(const Color &iColor) { color = iColor; }

std::optional<double> Polygon::intersects(const Ray &iRay) const {
    if (vertices.size() < 3) {
        return std::nullopt;
    }

    std::optional<double> closestDistance;
    double closestT = std::numeric_limits<double>::max();

    // Loop over each triangle in the polygon (assuming a fan structure)
    for (size_t i = 1; i < vertices.size() - 1; ++i) {
        Vector3 v0 = vertices[0];
        Vector3 v1 = vertices[i];
        Vector3 v2 = vertices[i + 1];

        // Calculate edges of the triangle
        Vector3 edge1 = v1 - v0;
        Vector3 edge2 = v2 - v0;

        // Calculate the determinant using cross product
        Vector3 h = iRay.Direction().cross(edge2);
        double a = edge1 * h;

        // If a is close to 0, the ray is parallel to this triangle
        if (std::fabs(a) < std::numeric_limits<double>::epsilon())
            continue;

        double f = 1.0 / a;
        Vector3 s = iRay.Origin() - v0;
        double u = f * (s * h);

        // Check if intersection is outside the triangle
        if (u < 0.0 || u > 1.0)
            continue;

        Vector3 q = s.cross(edge1);
        double v = f * (iRay.Direction() * q);

        // Check if intersection is outside the triangle
        if (v < 0.0 || u + v > 1.0)
            continue;

        double t = f * (edge2 * q);

        if (t > std::numeric_limits<double>::epsilon() && t < closestT) {
            closestT = t;
            closestDistance = t;
        }
    }

    return closestDistance;
}

std::ostream &operator<<(std::ostream &_stream, const Polygon &polygon) {
    _stream << "Polygon with " << polygon.vertices.size() << " vertices:\n";
    for (const Vector3 &vertex: polygon.vertices) {
        _stream << vertex << " ";
    }
    _stream << "\nColor: " << polygon.color;
    return _stream;
}
