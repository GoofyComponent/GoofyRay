#include <Plane.hpp>
#include <iostream>
#include <vector>
#include "Camera.hpp"
#include "Color.hpp"
#include "Image.hpp"
#include "Object.hpp"
#include "Scene.hpp"
#include "Sphere.hpp"

int imageWidth = 1800;
int imageHeight = 1900;

int main() {
    Color red(1, 0, 0);
    Color blue(0, 0, 1);
    Color green(0, 1, 0);
    Color yellow(1, 1, 0);

    Sphere sphereLeft(Vector3(2.5, 0, 5), 1, green, 0);
    Sphere sphereMiddle(Vector3(0, 0, 8), 1, blue, 0);
    Sphere sphereRight(Vector3(-2.5, 0, 10), 1, red, 0);
    Plane plane(Vector3(0, 1, 0), Vector3(0, 1, 0), yellow, 0);

    Light light(Vector3(0, 40, 30), Color(1, 1, 1), 1);
    std::vector<Object *> objects = {&plane, &sphereLeft, &sphereMiddle, &sphereRight};

    Camera camera(Vector3(0, 0, 0), Vector3(0, 0, 1), imageWidth, imageHeight);

    Scene scene(camera, objects);
    scene.addLight(light);
    scene.addLight(light2);
    scene.setBackground(Color(.03f, 0.0f, 0.08f));

    Image image(imageWidth, imageHeight, scene.getBackground()); // Fond bleu ciel

    auto start = std::chrono::high_resolution_clock::now();

    for (unsigned int y = 0; y < imageHeight; ++y) {
        for (unsigned int x = 0; x < imageWidth; ++x) {
            Ray ray = camera.generateRay(x, y);
            Color pixelColor = scene.traceRay(ray, 2);
            image.SetPixel(x, y, pixelColor);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Temps de rendu : " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;

    image.WriteFile("../../../output.png");
    std::cout << "Image rendue et sauvegardée en tant que 'output.png'." << std::endl;
}
