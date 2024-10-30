#pragma once
#include "../raymath/Vector3.h"
#include "../raymath/Ray.hpp"

/**
 * @class Camera
 * @brief Représente une caméra qui génère des rayons en fonction de la résolution de l'image et des pixels.
 */
class Camera {
public:
    Camera(const Vector3& position, const Vector3& lookAt, int imageWidth, int imageHeight);

    Ray generateRay(int x, int y) const;

    const Vector3& getPosition() const;
    const Vector3& getDirection() const;

private:
    Vector3 m_position;          
    Vector3 m_direction;         
    Vector3 m_horizontal;        
    Vector3 m_vertical;          
    Vector3 m_lowerLeftCorner;   
    int m_imageWidth;           
    int m_imageHeight;
};
