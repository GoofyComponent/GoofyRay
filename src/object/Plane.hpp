#pragma once

#include "../raymath/Ray.hpp"
#include "../raymath/Vector3.h"
#include "Object.hpp"


class Plane : public Object {
    Vector3 normal;
    float d;

public:

    Plane(const Vector3 &normal, float distance, const Color &iColor, double iReflection);
    Vector3 Normal() const;

    float Distance() const;


    std::optional<double> intersects(const Ray &ray) const override;


    bool hit(const Ray &r, double t_min, double t_max, hit_record &rec) const override;

    Color getColor() const override;
    void setColor(const Color &iColor) override;
    void setReflectivity(double iReflectivity) override;
    double getReflectivity() override;
};
