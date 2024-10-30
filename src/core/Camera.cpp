#include "Camera.hpp"
#include <cmath>

// Définit M_PI pour les systèmes qui ne le définissent pas (Windows)
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

// Constructeur
Camera::Camera(const Vector3& position, const Vector3& lookAt, const Vector3& up, double fov, int imageWidth, int imageHeight)
    : m_position(position), m_fov(fov), m_imageWidth(imageWidth), m_imageHeight(imageHeight) {
    double aspectRatio = static_cast<double>(imageWidth) / imageHeight;
    double theta = fov * M_PI / 180.0;  // Conversion du FOV en radians
    double viewportHeight = 2.0 * tan(theta / 2);
    double viewportWidth = aspectRatio * viewportHeight;

    m_direction = (lookAt - position).normalized();
    Vector3 right = m_direction.cross(up).normalized();
    Vector3 trueUp = right.cross(m_direction);

    m_horizontal = right * viewportWidth;
    m_vertical = trueUp * viewportHeight;
    m_lowerLeftCorner = m_position - m_horizontal / 2 - m_vertical / 2 - m_direction;
}

// Génère un rayon pour le pixel (x, y)
Ray Camera::generateRay(int x, int y) const {
    double u = static_cast<double>(x) / (m_imageWidth - 1);
    double v = static_cast<double>(y) / (m_imageHeight - 1);
    Vector3 direction = m_lowerLeftCorner + m_horizontal * u + m_vertical * v - m_position;
    return Ray(m_position, direction);
}

// Getters
const Vector3& Camera::getPosition() const {
    return m_position;
}

const Vector3& Camera::getDirection() const {
    return m_direction;
}
