#include "Sphere.hpp"
#include <cmath>

Sphere::Sphere(Vector3 center, double radius, Color color)
    : m_center(center), m_radius(radius), m_color(color) {}

// Renvoie la couleur de la sphère
Color Sphere::getColor() const {
    return m_color;
}

// Détecte l'intersection avec un rayon
std::optional<std::vector<Vector3>> Sphere::intersects(const Ray& ray) const {
    Vector3 oc = ray.Origin() - m_center;
    double a = ray.Direction() * ray.Direction();
    double b = 2.0 * (oc * ray.Direction());
    double c = oc * oc - m_radius * m_radius;
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double t1 = (-b - std::sqrt(discriminant)) / (2.0 * a);
        double t2 = (-b + std::sqrt(discriminant)) / (2.0 * a);
        return std::vector<Vector3>{ ray.At(t1), ray.At(t2) };
    }
    return std::nullopt;
}
