#include <iostream>
#include <vector>
#include "Scene.hpp"
#include "Camera.hpp"
#include "Sphere.hpp"
#include "Color.hpp"
#include "Image.hpp"
#include "Object.hpp"

int main()
{
    Color colorLeft(1, 0, 0);
    Color colorMiddle(0, 0, 1);
    Color colorRight(0, 1, 0);

    Sphere sphereLeft(Vector3(3.5, 0, 5), 0.5, colorRight);  
    Sphere sphereMiddle(Vector3(0, 0, 5), 0.5, colorMiddle); 
    Sphere sphereRight(Vector3(-3.5, 0, 5), 0.5, colorLeft);

    std::vector<Object *> objects = {&sphereLeft, &sphereMiddle, &sphereRight};

    int imageWidth = 1024;
    int imageHeight = 1024;
    Camera camera(Vector3(0, 0, 0), Vector3(0, 0, 1), imageWidth, imageHeight);

    Scene scene(camera, objects);

    // Définir le fond bleu ciel pour la scène
    scene.setBackground(Color(0.53f, 0.81f, 0.98f));

    // Initialiser une image pour le rendu final
    Image image(imageWidth, imageHeight, scene.getBackground()); // Fond bleu ciel

    // Boucle sur chaque pixel de l'image
    for (unsigned int y = 0; y < imageHeight; ++y)
    {
        for (unsigned int x = 0; x < imageWidth; ++x)
        {
            // Calculer la direction du rayon pour le pixel (x, y)
            Ray ray = camera.generateRay(x, y);

            // Tracer le rayon dans la scène et obtenir la couleur du pixel
            Color pixelColor = scene.traceRay(ray);

            // Définir la couleur du pixel dans l'image
            image.SetPixel(x, y, pixelColor);
        }
    }

    image.WriteFile("../../../output.png");

    std::cout << "Image rendue et sauvegardée en tant que 'output.png'." << std::endl;
    return 0;
}
