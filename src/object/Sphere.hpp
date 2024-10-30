#pragma once
#include "../raymath/Color.hpp"
#include "../raymath/Vector3.h"
#include "Object.hpp"

class Sphere : public Object {
public:
    Sphere(Vector3 center, double radius, Color color, double reflectivity = 0.0);

    ~Sphere() override;

    std::optional<std::vector<Vector3>> intersects(const Ray &ray) const override;

    Color getColor() const override;

    std::optional<double> intersect(const Ray &iRay) const override;

    bool hit(const Ray &r, double t_min, double t_max, hit_record &rec) const override;

private:
    Vector3 m_center;
    double m_radius;
    Color m_color;
    double m_reflectivity;
};
