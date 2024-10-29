#pragma once
#include "Object.hpp"
#include "../raymath/Color.hpp"
#include "../raymath/Vector3.h"

class Sphere : public Object {
public:
    Sphere(Vector3 center, double radius, Color color);

    // Implémentations des méthodes virtuelles
    std::optional<std::vector<Vector3>> intersects(const Ray &ray) const override;
    Color getColor() const override;

private:
    Vector3 m_center;
    double m_radius;
    Color m_color;
};