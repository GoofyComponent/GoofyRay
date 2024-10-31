#include <Plane.hpp>
#include <iostream>
#include <vector>
#include <chrono>

#include "Camera.hpp"
#include "Color.hpp"
#include "Image.hpp"
#include "Object.hpp"
#include "Scene.hpp"
#include "Sphere.hpp"
#include "Input.hpp"

// Function prototype to ensure renderTemplateScene is recognized
void renderTemplateScene();

int main() {
    int imageWidth = Input::getInt("Enter image width (or press Enter for 1024): ", 1024);
    int imageHeight = Input::getInt("Enter image height (or press Enter for 1024): ", 1024);

    if (Input::promptTemplateChoice()) {
        renderTemplateScene();
        return 0;
    }

    float pr, pg, pb;
    Input::getColor("Enter Plane color RGB (0-1): ", pr, pg, pb);

    Vector3 cameraPosition(0, 0, 0);
    Vector3 cameraDirection(0, 0, 1);
    Plane plane(Vector3(0, 1, 0), Vector3(0, 1, 0), Color(pr, pg, pb), 0);

    Light light(Vector3(0, 40, 30), Color(1, 1, 1), 1);
    Camera camera(cameraPosition, cameraDirection, imageWidth, imageHeight);

    std::vector<Object *> objects;

    do {
        std::cout << "Choose an object to create:\n1. Sphere\n2. Stop\n";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            float x, y, z, r, g, b, radius;
            Input::getVector3("Enter sphere position (x y z): ", x, y, z);
            radius = Input::getFloat("Enter sphere radius: ");
            Input::getColor("Enter sphere color (r g b, values 0 to 1): ", r, g, b);

            Sphere *sphere = new Sphere(Vector3(x, y, z), radius, Color(r, g, b));
            objects.push_back(sphere);
        } else {
            break;
        }
    } while (true);

    Scene scene(camera, objects);

    float br, bg, bb;
    Input::getColor("Enter background color RGB (0-1): ", br, bg, bb);

    scene.addLight(light);
    scene.setBackground(Color(br, bg, bb));

    Image image(imageWidth, imageHeight, scene.getBackground());
    auto start = std::chrono::high_resolution_clock::now();

    for (unsigned int y = 0; y < imageHeight; ++y) {
        for (unsigned int x = 0; x < imageWidth; ++x) {
            Ray ray = camera.generateRay(x, y);
            Color pixelColor = scene.traceRay(ray, 2);
            image.SetPixel(x, y, pixelColor);
        }
    }

    image.WriteFile("../../../output.png");
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Render time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;
}

void renderTemplateScene() {
    int imageWidth = 1024;
    int imageHeight = 1024;

    Color red(1, 0, 0);
    Color blue(0, 0, 1);
    Color green(0, 1, 0);
    Color yellow(1, 1, 0);

    Sphere sphereLeft(Vector3(2.5, 0, -5), 1, green);
    Sphere sphereMiddle(Vector3(0, 0, -8), 1, blue);
    Sphere sphereRight(Vector3(-2.5, 0, -10), 1, red);
    Plane plane(Vector3(0, 1, 0), Vector3(0, 1, 0), yellow, 0);

    Light light(Vector3(0, 40, 30), Color(1, 1, 1), 1);

    Camera camera(Vector3(0, 0, 0), Vector3(0, 0, -1), imageWidth, imageHeight);

    std::vector<Object *> objects = {&sphereLeft, &sphereMiddle, &sphereRight};
    Scene scene(camera, objects);

    scene.addLight(light);
    scene.setBackground(Color(0.03f, 0.0f, 0.08f));

    Image image(imageWidth, imageHeight, scene.getBackground());

    auto start = std::chrono::high_resolution_clock::now();

    for (unsigned int y = 0; y < imageHeight; ++y) {
        for (unsigned int x = 0; x < imageWidth; ++x) {
            Ray ray = camera.generateRay(x, y);
            Color pixelColor = scene.traceRay(ray ,2);
            image.SetPixel(x, y, pixelColor);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Render time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;

    image.WriteFile("../../../output.png");
    std::cout << "Image rendered and saved as 'output.png'." << std::endl;
}
