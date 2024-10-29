#include "Camera.hpp"
#include <cmath>
#include "Ray.hpp"

// Constructor for the Camera class
Camera::Camera(const Vector3& position, const Vector3& depthEnd, int width, int height)
    : position(position), depthEnd(depthEnd), width(width), height(height) {}

// Generates all rays from the camera
std::vector<Ray> Camera::getAllRays() const {
    std::vector<Ray> rays;
    Vector3 direction = (depthEnd).normalized();

    // Loop through each pixel on the screen
    for (int i = 0; i < height; ++i) {
        float horizontalOffset = (i - height / 2.0f) * std::tan(width / 2.0f) / (height / 2.0f);
        Vector3 adjustedDirection = direction + Vector3(horizontalOffset, 0, 0);  // Horizontal adjustement

        rays.push_back(Ray(position, adjustedDirection.normalized()));  // Creates the ray with the adjusted direction
    }
    return rays;
}