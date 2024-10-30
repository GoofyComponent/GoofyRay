#include "Sphere.hpp"
#include <cmath>

Sphere::Sphere(Vector3 center, double radius, Color color, double reflectivity)
    : m_center(center), m_radius(radius), m_color(color), m_reflectivity(reflectivity) {}

// Renvoie la couleur de la sphère
Color Sphere::getColor() const { return m_color; }

// Détecte l'intersection avec un rayon
std::optional<std::vector<Vector3>> Sphere::intersects(const Ray &ray) const {
    Vector3 oc = ray.Origin() - m_center;
    double a = ray.Direction() * ray.Direction();
    double b = 2.0 * (oc * ray.Direction());
    double c = oc * oc - m_radius * m_radius;
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double t1 = (-b - std::sqrt(discriminant)) / (2.0 * a);
        double t2 = (-b + std::sqrt(discriminant)) / (2.0 * a);
        return std::vector<Vector3>{ray.At(t1), ray.At(t2)};
    }
    return std::nullopt;
}

// Renvoie la distance de l'intersection la plus proche
std::optional<double> Sphere::intersect(const Ray &ray) const {
    auto points = intersects(ray);

    // Si l'intersection n'existe pas, renvoie std::nullopt
    if (!points || points->empty()) return std::nullopt;

    // Calcul des distances pour chaque point d'intersection
    std::vector<double> distances;
    for (const auto& point : *points) {
        double distance = (point - ray.Origin()).length();
        distances.push_back(distance);
    }

    // Renvoie la distance la plus proche
    return *std::min_element(distances.begin(), distances.end());
}

bool Sphere::hit(const Ray &r, double t_min, double t_max, hit_record &rec) const {
    auto distance = intersect(r);

    // Vérifie si une intersection valide existe dans la plage t_min et t_max
    if (!distance || *distance < t_min || *distance > t_max) {
        return false;
    }

    rec.t = *distance;
    rec.position = r.At(rec.t);
    Vector3 outward_normal = (rec.position - m_center) / m_radius;
    rec.set_face_normal(r, outward_normal);
    rec.color = m_color;
    rec.reflectivity = m_reflectivity;  // Ajoute la réflectivité


    return true;
}

Sphere::~Sphere() = default;


