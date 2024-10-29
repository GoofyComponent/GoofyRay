#include "Camera.hpp"
#include "Ray.hpp"
#include <iostream>
#include "Sphere.hpp"
#include "Image.hpp"

int main() {
    
    Vector3 origin = Vector3(0, 0, 0);
    float radius = 100;

    Color color = Color(1, 0, 0);
    Sphere sphere = Sphere(origin, radius, color);
    sphere.setOrigin(Vector3(400, 400, 0));
    
    Image image = Image(800, 800, Color(0, 0, 0));

    image.DrawSphere(sphere);
    // image.WriteFile("../../../output.png");


    
    return 0;
}
