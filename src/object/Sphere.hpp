#pragma once
#include "../raymath/Color.hpp"
#include "../raymath/Vector3.h"
#include "Object.hpp"

class Sphere : public Object {
public:
    Sphere(Vector3 center, double radius, Color color, double reflectivity = 0.0);

    ~Sphere() override;

    std::optional<double> intersects(const Ray &ray) const override;


    bool hit(const Ray &r, double t_min, double t_max, hit_record &rec) const override;

    Vector3 Origin() const;


    float Radius() const;


    void setOrigin(Vector3 iOrigin);


    void setRadius(float iRadius);

    Color getColor() const override;

    void setColor(const Color &iColor) override;

    friend std::ostream &operator<<(std::ostream &_stream, const Sphere &sphere);

    void setReflectivity(double iReflectivity) override;

    double getReflectivity() override;

private:
    Vector3 origin;
    float radius;
};
