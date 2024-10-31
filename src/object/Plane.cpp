#include "Plane.hpp"

Plane::Plane(const Vector3 &iPosition, const Vector3 &iNormal, const Color &iColor, double iReflection) :
    Object(iColor, iReflection), position(iPosition), normal(iNormal) {}

Plane::~Plane() = default;

Vector3 Plane::Normal() const { return normal; }

Vector3 Plane::Position() const { return position; }

std::optional<double> Plane::intersects(const Ray &ray) const {
    float denom = ray.Direction() * normal;

    if (std::abs(denom) < 1e-6) {
        return std::nullopt;
    }

    float num = (position - ray.Origin()) * normal;
    double t = num / denom;

    if (t < 0) {
        return std::nullopt;
    }

    return t;
}


bool Plane::hit(const Ray &r, double t_min, double t_max, hit_record &rec) const {
    auto distance = intersects(r);

    // Vérifie si une intersection valide existe dans la plage t_min et t_max
    if (!distance) {
        return false;
    }

    rec.t = *distance;
    rec.position = position;
    rec.color = getColor();
    rec.reflectivity = m_reflectivity;
    rec.normal = (normal * r.Direction() < 0) ? normal : -normal;

    return true;
}

Color Plane::getColor() const { return m_color; }

void Plane::setColor(const Color &iColor) { m_color = iColor; }

void Plane::setReflectivity(double iReflectivity) { m_reflectivity = iReflectivity; }

double Plane::getReflectivity() { return m_reflectivity; }