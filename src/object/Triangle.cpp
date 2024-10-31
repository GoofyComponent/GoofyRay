// Triangle.cpp
#include "Triangle.h"
#include <cmath>

Triangle::Triangle(const Vector3 &v0, const Vector3 &v1, const Vector3 &v2, const Color &color, double reflectivity) :
    Object(color, reflectivity), m_v0(v0), m_v1(v1), m_v2(v2) {
    m_normal = ((v1 - v0).cross(v2 - v0)).normalized();
    // m_reflectivity = reflectivity;
    // m_color = color;
}

std::optional<double> Triangle::intersects(const Ray &ray) const {
    // Calcul de l'intersection par la méthode de Möller–Trumbore
    Vector3 edge1 = m_v1 - m_v0;
    Vector3 edge2 = m_v2 - m_v0;
    Vector3 h = ray.Direction().cross(edge2);
    double a = edge1 * h;

    if (fabs(a) < 1e-8)
        return std::nullopt; // Rayon parallèle au triangle

    double f = 1.0 / a;
    Vector3 s = ray.Origin() - m_v0;
    double u = f * s * h;

    if (u < 0.0 || u > 1.0)
        return std::nullopt;

    Vector3 q = s.cross(edge1);
    double v = f * ray.Direction() * q;

    if (v < 0.0 || u + v > 1.0)
        return std::nullopt;

    double t = f * edge2 * q;
    if (t > 1e-8)
        return t; // Intersection

    return std::nullopt;
}

bool Triangle::hit(const Ray &ray, double t_min, double t_max, hit_record &rec) const {
    auto t = intersects(ray);
    if (!t || *t < t_min || *t > t_max)
        return false;

    rec.t = *t;
    rec.position = ray.At(rec.t);
    rec.normal = m_normal;
    rec.color = getColor();
    rec.reflectivity = m_reflectivity;

    return true;
}

Color Triangle::getColor() const { return m_color; }

void Triangle::setColor(const Color &iColor) { m_color = iColor; }

void Triangle::setReflectivity(double iReflectivity) { m_reflectivity = iReflectivity; }

double Triangle::getReflectivity() { return m_reflectivity; }


