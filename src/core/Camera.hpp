#pragma once

#include "../raymath/Vector3.h"
#include "../raymath/Ray.hpp"
#include <vector>

class Camera {
public:
    Camera(const Vector3& origin, const Vector3& direction, float width, float aspect_ratio);

    // Getters
    const Vector3& getOrigin() const;
    const Vector3& getDirection() const;
    float getWidth() const;
    float getAspectRatio() const;

    // Setters
    void setOrigin(const Vector3& origin);
    void setDirection(const Vector3& direction);
    void setWidth(float width);
    void setAspectRatio(float aspect_ratio);

    // Method to get a 2D grid of Rays
    std::vector<std::vector<Ray>> getViewGrid(int resolution_x, int resolution_y) const;

private:
    Vector3 m_origin;
    Vector3 m_direction;
    float m_width;
    float m_aspect_ratio;
};
