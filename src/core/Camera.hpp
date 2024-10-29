#pragma once

#include "../raymath/Vector3.h"
#include "../raymath/Ray.hpp"
#include <vector>

class Camera {
public:
    Camera(); // Constructeur par défaut
    Camera(Vector3 position, Vector3 direction, float viewportWidth, float viewportHeight, unsigned int imageWidth, unsigned int imageHeight, float focalLength);

    // Génère un rayon pour un pixel donné
    Ray generateRay(unsigned int x, unsigned int y) const;

    // Accesseurs et mutateurs
    void setPosition(const Vector3& newPosition);
    void setDirection(const Vector3& newDirection);

    Vector3 getPosition() const;
    Vector3 getDirection() const;

private:
    Vector3 position;
    Vector3 direction;
    float viewportWidth;
    float viewportHeight;
    float focalLength;
    unsigned int imageWidth;
    unsigned int imageHeight;
};


