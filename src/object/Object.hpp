#pragma once
#include <optional>
#include "../raymath/Color.hpp"
#include "../raymath/Ray.hpp"

struct hit_record {
    Vector3 position;
    Vector3 normal;
    double t{};
    bool front_face{};
    Color color;
    double reflectivity;
};

class Object {
protected:
    double m_reflectivity;
    Color m_color;

public:
    Object(Color color, double reflectivity = 1.0) : m_color(color), m_reflectivity(reflectivity) {}

    virtual ~Object() = default;

    virtual std::optional<double> intersects(const Ray &ray) const = 0;

    virtual bool hit(const Ray &r, double t_min, double t_max, hit_record &rec) const = 0;

    virtual Color getColor() const = 0;
    virtual void setColor(const Color &iColor) = 0;

    virtual void setReflectivity(double iReflectivity) = 0;

    virtual double getReflectivity() = 0;
};
