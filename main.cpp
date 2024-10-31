#include <Plane.hpp>
#include <iostream>
#include <vector>
#include <chrono>
#include <random>

#include "Camera.hpp"
#include "Color.hpp"
#include "Image.hpp"
#include "Object.hpp"
#include "Scene.hpp"
#include "Sphere.hpp"
#include "Input.hpp"

// Function prototypes
void renderTemplateScene();
void addRandomSphere(std::vector<Object *> &objects);
void addConfiguredSphere(std::vector<Object *> &objects);
Color chooseColor(const std::string &elementName);

// Preset colors and names
const std::vector<std::pair<Color, std::string>> presetColors = {
    {Color(1, 0, 0), "Red"},
    {Color(0, 1, 0), "Green"},
    {Color(0, 0, 1), "Blue"},
    {Color(1, 1, 0), "Yellow"},
    {Color(1, 0, 1), "Magenta"},
    {Color(0, 1, 1), "Cyan"},
    {Color(1, 0.5, 0), "Orange"},
    {Color(0.5, 0, 0.5), "Purple"}
};

int main() {
    int imageWidth = Input::getInt("Enter image width (or press Enter for 1024): ", 1024);
    int imageHeight = Input::getInt("Enter image height (or press Enter for 1024): ", 1024);

    if (Input::promptTemplateChoice()) {
        renderTemplateScene();
        return 0;
    }

    // Choose color for the plane
    Color planeColor = chooseColor("plane");

    Vector3 cameraPosition(0, 0, 0);
    Vector3 cameraDirection(0, 0, -1);
    Plane plane(Vector3(0, 1, 0), Vector3(0, 1, 0), planeColor, 0);

    Light light(Vector3(0, 40, 30), Color(1, 1, 1), 1);
    Camera camera(cameraPosition, cameraDirection, imageWidth, imageHeight);

    std::vector<Object *> objects;
    objects.push_back(&plane);

    // User choice for configuring or randomizing spheres
    do {
        std::cout << "Choose an option:\n1. Configure a sphere\n2. Add a random sphere\n3. Stop\n";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            addConfiguredSphere(objects);
        } else if (choice == 2) {
            addRandomSphere(objects);
        } else {
            break;
        }
    } while (true);


    Scene scene(camera, objects);

    // Choose color for the background
    Color backgroundColor = chooseColor("background");
    scene.addLight(light);
    scene.setBackground(backgroundColor);

    Image image(imageWidth, imageHeight, scene.getBackground());
    auto start = std::chrono::high_resolution_clock::now();

    for (unsigned int y = 0; y < imageHeight; ++y) {
        for (unsigned int x = 0; x < imageWidth; ++x) {
            Ray ray = camera.generateRay(x, y);
            Color pixelColor = scene.traceRay(ray, 3); // Depth of 3 for richer reflections
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

    std::vector<Object *> objects = {&sphereLeft, &sphereMiddle, &sphereRight, &plane};
    Scene scene(camera, objects);

    scene.addLight(light);
    scene.setBackground(Color(0.03f, 0.0f, 0.08f));

    Image image(imageWidth, imageHeight, scene.getBackground());

    auto start = std::chrono::high_resolution_clock::now();

    for (unsigned int y = 0; y < imageHeight; ++y) {
        for (unsigned int x = 0; x < imageWidth; ++x) {
            Ray ray = camera.generateRay(x, y);
            Color pixelColor = scene.traceRay(ray, 3); // Depth of 3
            image.SetPixel(x, y, pixelColor);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Render time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;

    image.WriteFile("../../../output.png");
    std::cout << "Image rendered and saved as 'output.png'." << std::endl;
}

void addRandomSphere(std::vector<Object *> &objects) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<float> xDist(-8.0, 8.0); // X range -8 to 8
    std::uniform_real_distribution<float> yDist(-3.0, 3.0);  // Y range -3 to 3
    std::uniform_real_distribution<float> zDist(-15.0, -5.0); // Z range farther away, -15 to -5
    std::uniform_real_distribution<float> radiusDist(0.5, 2.0); // Slightly larger radius, 0.5 to 2.0
    std::uniform_int_distribution<int> colorIndexDist(0, presetColors.size() - 1); // Random preset color

    float x = xDist(gen);
    float y = yDist(gen);
    float z = zDist(gen);
    float radius = radiusDist(gen);
    Color randomColor = presetColors[colorIndexDist(gen)].first;

    Sphere *sphere = new Sphere(Vector3(x, y, z), radius, randomColor);
    objects.push_back(sphere);
}

void addConfiguredSphere(std::vector<Object *> &objects) {
    float x, y, z, radius;
    int colorChoice;
    Color sphereColor;

    Input::getVector3("Enter sphere position (x y z): ", x, y, z);
    radius = Input::getFloat("Enter sphere radius: ");
    sphereColor = chooseColor("sphere");

    Sphere *sphere = new Sphere(Vector3(x, y, z), radius, sphereColor);
    objects.push_back(sphere);
}

// Function to choose a color from presets or a custom entry
Color chooseColor(const std::string &elementName) {
    int colorChoice;
    Color chosenColor;

    std::cout << "Choose a color preset or enter a custom color for the " << elementName << ":\n";
    for (size_t i = 0; i < presetColors.size(); ++i) {
        std::cout << i + 1 << ". " << presetColors[i].second 
                  << " (" << presetColors[i].first.r << ", " 
                  << presetColors[i].first.g << ", " 
                  << presetColors[i].first.b << ")\n";
    }
    std::cout << presetColors.size() + 1 << ". Custom color\n";
    std::cin >> colorChoice;

    if (colorChoice > 0 && colorChoice <= presetColors.size()) {
        chosenColor = presetColors[colorChoice - 1].first;
    } else {
        float r, g, b;
        Input::getColor("Enter custom color (r g b, values 0 to 1): ", r, g, b);
        chosenColor = Color(r, g, b);
    }

    return chosenColor;
}
