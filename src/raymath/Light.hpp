// src/raymath/Light.hpp
#pragma once

#include "Vector3.h"
#include "Color.hpp"

class Light {
public:
    Light(const Vector3 &position, const Color &color, float intensity);

    const Vector3 &getPosition() const;
    const Color &getColor() const;
    float getIntensity() const;

private:
    Vector3 m_position;
    Color m_color;
    float m_intensity;
};
