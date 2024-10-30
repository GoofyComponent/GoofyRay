#include "Light.hpp"

Light::Light(const Vector3 &position, const Color &color, float intensity)
    : m_position(position), m_color(color), m_intensity(intensity) {}

const Vector3 &Light::getPosition() const { return m_position; }
const Color &Light::getColor() const { return m_color; }
float Light::getIntensity() const { return m_intensity; }
