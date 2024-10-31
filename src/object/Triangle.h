// Triangle.hpp
#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <optional>
#include "../raymath/Color.hpp"
#include "../raymath/Ray.hpp"
#include "Object.hpp"

class Triangle : public Object {
public:
    Triangle(const Vector3 &v0, const Vector3 &v1, const Vector3 &v2, const Color &color, double reflectivity);

    std::optional<double> intersects(const Ray &ray) const override;
    bool hit(const Ray &ray, double t_min, double t_max, hit_record &rec) const override;

    Color getColor() const override;
    void setColor(const Color &iColor) override;
    void setReflectivity(double iReflectivity) override;
    double getReflectivity() override;

private:
    Vector3 m_v0, m_v1, m_v2;
    Vector3 m_normal;
};

#endif
