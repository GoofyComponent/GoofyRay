#pragma once
#include "../raymath/Vector3.h"
#include "../raymath/Ray.hpp"

/**
 * @class Camera
 * @brief Représente une caméra qui génère des rayons en fonction de la résolution de l'image et des pixels.
 */
class Camera {
public:
    Camera(const Vector3& position, const Vector3& lookAt, const Vector3& up, double fov, int imageWidth, int imageHeight);

    // Génère un rayon pour le pixel (x, y) avec la résolution donnée
    Ray generateRay(int x, int y) const;

    // Getters
    const Vector3& getPosition() const;
    const Vector3& getDirection() const;

private:
    Vector3 m_position;
    Vector3 m_direction;
    Vector3 m_horizontal;
    Vector3 m_vertical;
    Vector3 m_lowerLeftCorner;
    double m_fov;  // Champ de vision (Field of View)
    int m_imageWidth;  // Largeur de l'image
    int m_imageHeight; // Hauteur de l'image
};
