#pragma once

#include "../raymath/Vector3.h"
#include "../raymath/Color.hpp"

class Light {
public:
    Light(Vector3 position, Color color);

    Vector3 getPosition() const;
    Color getColor() const;

    void setPosition(const Vector3& newPosition);
    void setColor(const Color& newColor);

private:
    Vector3 position;
    Color color;
};
