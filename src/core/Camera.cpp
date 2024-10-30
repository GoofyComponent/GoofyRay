#include "Camera.hpp"

Camera::Camera(const Vector3& position, const Vector3& lookAt, int imageWidth, int imageHeight)
    : m_position(position), m_imageWidth(imageWidth), m_imageHeight(imageHeight) {
    
    m_direction = (lookAt - position).normalized();

    double aspectRatio = static_cast<double>(imageWidth) / imageHeight;
    double viewportHeight = 2.0;
    double viewportWidth = aspectRatio * viewportHeight;

    m_horizontal = Vector3(viewportWidth, 0, 0);
    m_vertical = Vector3(0, viewportHeight, 0);
    m_lowerLeftCorner = m_position - m_horizontal / 2 - m_vertical / 2 - m_direction;
}

Ray Camera::generateRay(int x, int y) const {
    double u = static_cast<double>(x) / (m_imageWidth - 1);
    double v = static_cast<double>(y) / (m_imageHeight - 1);
    Vector3 direction = m_lowerLeftCorner + m_horizontal * u + m_vertical * v - m_position;
    return Ray(m_position, direction);
}

const Vector3& Camera::getPosition() const {
    return m_position;
}

const Vector3& Camera::getDirection() const {
    return m_direction;
}
