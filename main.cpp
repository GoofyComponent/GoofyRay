#include <iostream>
#include <vector>
#include "Scene.hpp"
#include "Camera.hpp"
#include "Sphere.hpp"
#include "Color.hpp"
#include "Image.hpp"
#include "Object.hpp"
#include "Light.hpp"

int main()
{
    // Couleurs des objets
    Color colorLeft(1, 0, 0);    // Rouge
    Color colorMiddle(0, 0, 1);  // Bleu
    Color colorRight(0, 1, 0);   // Vert

    // Création des sphères
    Sphere sphereLeft(Vector3(3.5, 0, 5), 0.5, colorRight);  
    Sphere sphereMiddle(Vector3(0, 0, 5), 0.5, colorMiddle); 
    Sphere sphereRight(Vector3(-3.5, 0, 5), 0.5, colorLeft);

    std::vector<Object *> objects = {&sphereLeft, &sphereMiddle, &sphereRight};

    // Dimensions de l'image et configuration de la caméra
    int imageWidth = 1024;
    int imageHeight = 1024;
    Camera camera(Vector3(0, 0, 0), Vector3(0, 0, 1), imageWidth, imageHeight);

    // Définir une seule source de lumière blanche, intense et positionnée au-dessus des sphères à gauche
    Light light(Vector3(3.5, 5, 5), Color(1, 1, 1), 1);
    std::vector<Light> lights = {light};

    // Initialisation de la scène avec la caméra, les objets et la lumière
    Scene scene(camera, objects, lights);

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
            Color pixelColor = scene.traceRay(ray, 0); // Profondeur de réflexion initiale à 0

            // Définir la couleur du pixel dans l'image
            image.SetPixel(x, y, pixelColor);
        }
    }

    // Sauvegarder l'image dans un fichier PNG
    image.WriteFile("../../../output.png");

    std::cout << "Image rendue et sauvegardée en tant que 'output.png'." << std::endl;
    return 0;
}
