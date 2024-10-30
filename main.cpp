#include <iostream>
#include <vector>
#include "Camera.hpp"
#include "Color.hpp"
#include "Image.hpp"
#include "Object.hpp"
#include "Scene.hpp"
#include "Sphere.hpp"

int imageWidth = 800;
int imageHeight = 400;

int main() {
    // Couleurs distinctes pour chaque sphère
    Color red(1, 0, 0); // Rouge pour la sphère de gauche
    Color Blue(0, 0, 1); // Bleu pour la sphère du milieu
    Color green(0, 1, 0); // Vert pour la sphère de droite

    Sphere sphereLeft(Vector3(2.5, 0, -5), 1, green, .45);
    Sphere sphereMiddle(Vector3(0, 0, -5), 1, Blue, .60);
    Sphere sphereRight(Vector3(-2.5, 0, -5), 1, red, 0.5);

    Light light(Vector3(0, 0, -1), Color(1, 1, 1), 1);
    std::vector<Object *> objects = {&sphereLeft, &sphereMiddle, &sphereRight};

    Camera camera(Vector3(0, 0, 0), Vector3(0, 0, -1), Vector3(0, 1, 0), 60.0, imageWidth, imageHeight);

    Scene scene(camera, objects);
    scene.addLight(light);
    scene.setBackground(Color(0.03f, 0.01f, 0.08f));

    Image image(imageWidth, imageHeight, scene.getBackground()); // Fond bleu ciel

    auto start = std::chrono::high_resolution_clock::now();

    // Boucle sur chaque pixel de l'image
    for (unsigned int y = 0; y < imageHeight; ++y) {
        for (unsigned int x = 0; x < imageWidth; ++x) {
            Ray ray = camera.generateRay(x, y);
            Color pixelColor = scene.traceRay(ray, 5);
            image.SetPixel(x, y, pixelColor);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Temps de rendu : " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;

    image.WriteFile("../../../output.png");
    std::cout << "Image rendue et sauvegardée en tant que 'output.png'." << std::endl;
}
