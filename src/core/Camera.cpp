#include "Camera.hpp"

// Constructeur avec tous les paramètres
Camera::Camera(Vector3 position, Vector3 direction, float viewportWidth, float viewportHeight, unsigned int imageWidth, unsigned int imageHeight, float focalLength)
    : position(position), direction(direction.normalized()), viewportWidth(viewportWidth), viewportHeight(viewportHeight), imageWidth(imageWidth), imageHeight(imageHeight), focalLength(focalLength) {}

Ray Camera::generateRay(unsigned int x, unsigned int y) const
{
    float pixelWidth = viewportWidth / imageWidth;
    float pixelHeight = viewportHeight / imageHeight;

    float u = (x + 0.5f) * pixelWidth - (viewportWidth / 2.0f);
    float v = (y + 0.5f) * pixelHeight - (viewportHeight / 2.0f);

    Vector3 pixelPosition = position + direction * focalLength + Vector3(u, v, 0);
    return Ray(position, pixelPosition - position);
}

void Camera::setPosition(const Vector3& newPosition) { position = newPosition; }
void Camera::setDirection(const Vector3& newDirection) { direction = newDirection.normalized(); }
Vector3 Camera::getPosition() const { return position; }
Vector3 Camera::getDirection() const { return direction; }