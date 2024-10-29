#include "Light.hpp"

Light::Light(Vector3 position, Color color) : position(position), color(color) {}

Vector3 Light::getPosition() const { return position; }
Color Light::getColor() const { return color; }

void Light::setPosition(const Vector3& newPosition) { position = newPosition; }
void Light::setColor(const Color& newColor) { color = newColor; }
