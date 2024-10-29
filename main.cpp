#include <iostream>
#include "Vector3.h"
#include "Ray.hpp"

int main() {
    Vector3 position, depthEnd;
    int width;
    int height;

    std::cout << "Enter position (x y z): ";
    std::cin >> position.x >> position.y >> position.z;

    std::cout << "Enter depth end (x y z): ";
    std::cin >> depthEnd.x >> depthEnd.y >> depthEnd.z;

    std::cout << "Enter width: ";
    std::cin >> width;

    std::cout << "Enter height: ";
    std::cin >> height;

    auto const vector1 = Vector3(0, 0, 0);     // Origin of the ray
    auto const vector2 = Vector3(1, 1, 0);     // Direction of the ray

    std::cout << "Vector1 (Origin): " << vector1 << std::endl;
    std::cout << "Vector2 (Direction): " << vector2 << std::endl;

    Ray const ray = Ray(vector1, vector2);

    std::cout << "Ray origin: " << ray.Origin() << std::endl;
    std::cout << "Ray direction (normalized): " << ray.Direction() << std::endl;
    std::cout << "Ray at distance 10: " << ray.At(10) << std::endl; // point at 10 units from origin along direction

    // Output the user inputs
    std::cout << "Position: " << position << std::endl;
    std::cout << "Depth End: " << depthEnd << std::endl;
    std::cout << "width: " << width << std::endl;
    std::cout << "Height: " << height << std::endl;

    return 0;
}
