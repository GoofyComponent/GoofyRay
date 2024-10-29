#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <vector>
#include "Vector3.h"
#include "Ray.hpp"

class Camera {
public:
    // Constructor to initialize the camera with position, width, vector, and height
    Camera(const Vector3& position, const Vector3& depthEnd, int width, int height);

    // Function to get all rays from the camera
    std::vector<Ray> getAllRays() const;

private:
    Vector3 position;
    Vector3 depthEnd;
    int width;      // Width of the camera
    int height;       // Height of the camera view

    // Function to calculate the direction of a ray given x and y coordinates
    Vector3 calculateRayDirection(int x, int y) const;
};

#endif
