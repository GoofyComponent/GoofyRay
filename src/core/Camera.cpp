// Camera.cpp
#include "Camera.hpp"

Camera::Camera(const Vector3& origin, const Vector3& direction, float width, float aspect_ratio)
    : m_origin(origin), m_direction(direction.normalized()), m_width(width), m_aspect_ratio(aspect_ratio) {}

const Vector3& Camera::getOrigin() const {
    return m_origin;
}

const Vector3& Camera::getDirection() const {
    return m_direction;
}

float Camera::getWidth() const {
    return m_width;
}

float Camera::getAspectRatio() const {
    return m_aspect_ratio;
}

void Camera::setOrigin(const Vector3& origin) {
    m_origin = origin;
}

void Camera::setDirection(const Vector3& direction) {
    m_direction = direction.normalized();
}

void Camera::setWidth(float width) {
    m_width = width;
}

void Camera::setAspectRatio(float aspect_ratio) {
    m_aspect_ratio = aspect_ratio;
}

std::vector<std::vector<Ray>> Camera::getViewGrid(int resolution_x, int resolution_y) const {

    float height = m_width / m_aspect_ratio; // Calculating the height of the view grid

    // Calculating the horizontal and vertical vectors
    Vector3 horizontal = Vector3(0, 1, 0) - m_direction;
    horizontal = horizontal.normalized() * m_width;
    Vector3 vertical = horizontal - m_direction;
    vertical = vertical.normalized() * height;

    // Lower left corner of the view grid
    Vector3 lower_left_corner = m_origin + m_direction - (horizontal * 0.5f) - (vertical * 0.5f);

    std::vector<std::vector<Ray>> view_grid;

    // Loop through the resolution to create the view grid
    for (int y = 0; y < resolution_y; ++y) {
        std::vector<Ray> row;
        for (int x = 0; x < resolution_x; ++x) {
            float u = static_cast<float>(x) / (resolution_x - 1);
            float v = static_cast<float>(y) / (resolution_y - 1);

            Vector3 direction = lower_left_corner + horizontal * u + vertical * v - m_origin;
            Ray ray(m_origin, direction.normalized());
            row.push_back(ray);  // Add each ray to the row
        }
        view_grid.push_back(row);  // Add each row to the view grid
    }


    return view_grid;
}
