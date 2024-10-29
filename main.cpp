#include "Camera.hpp"
#include "Ray.hpp"
#include <iostream>

int main() {
    // Define the camera origin and direction
    Vector3 origin(0.0f, 0.0f, 0.0f);
    Vector3 direction(0.0f, 0.0f, -1.0f);

    // Define the camera width and aspect ratio
    float width = 1080.0f;
    float aspect_ratio = 16.0f / 9.0f;

    // Instantiate the camera
    Camera camera(origin, direction, width, aspect_ratio);

    // Get the view grid
    int resolution_x = 1080;
    int resolution_y = 720;
    std::vector<std::vector<Ray>> viewGrid = camera.getViewGrid(resolution_x, resolution_y);

    // Print the rays
    for (int y = 0; y < std::min(3, resolution_y); ++y) {
        for (int x = 0; x < std::min(3, resolution_x); ++x) {
            const Ray& ray = viewGrid[y][x];
            std::cout << "Ray [" << y << "][" << x << "] - Origin: ("
                      << ray.Origin().x << ", " << ray.Origin().y << ", " << ray.Origin().z << ") "
                      << "Direction: (" << ray.Direction().x << ", " << ray.Direction().y << ", " << ray.Direction().z << ")"
                      << std::endl;
        }
    }

    return 0;
}
