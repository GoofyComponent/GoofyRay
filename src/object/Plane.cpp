#include "Plane.hpp"


Plane::Plane(const Vector3 &normal, float distance, const Color &iColor, double iReflection) :
    normal(normal.normalized()), d(distance), Object(iColor, iReflection) {}

Vector3 Plane::Normal() const { return normal; }


float Plane::Distance() const { return d; }


std::optional<double> Plane::intersects(const Ray &ray) const {
    float denom = normal * ray.Direction();

    if (std::abs(denom) < 1e-6) {
        return std::nullopt;
    }

    float t = -(normal * ray.Origin() + d) / denom;

    if (t < 0) {
        return std::nullopt;
    }

    return t;
}


bool Plane::hit(const Ray &r, double t_min, double t_max, hit_record &rec) const {
    auto distance = intersects(r);

    if (!distance || *distance < t_min || *distance > t_max) {
        return false;
    }

    rec.t = *distance;
    rec.position = r.At(rec.t);
    rec.normal = normal; // La normale du plan est constante
    rec.set_face_normal(r, normal);
    rec.color = getColor();
    rec.reflectivity = 34;

    return true;
}

Color Plane::getColor() const { return m_color; }

void Plane::setColor(const Color &iColor) { m_color = iColor; }

void Plane::setReflectivity(double iReflectivity) { m_reflectivity = iReflectivity; }

double Plane::getReflectivity() { return m_reflectivity; }