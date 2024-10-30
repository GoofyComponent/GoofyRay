#include <iostream>
#include <vector>
#include "Scene.hpp"
#include "Camera.hpp"
#include "Sphere.hpp"
#include "Color.hpp"
#include "Image.hpp"
#include "Object.hpp"

int main() {
    // Couleurs distinctes pour chaque sphère
    Color colorLeft(1, 0, 0);     // Rouge pour la sphère de gauche
    Color colorMiddle(0, 0, 1);   // Bleu pour la sphère du milieu
    Color colorRight(0, 1, 0);    // Vert pour la sphère de droite

    // Créer les sphères du plus grand au plus petit avec des positions en Z pour la profondeur
    Sphere sphereLeft(Vector3(2.5, 0, -7), 1, colorRight);   // Encore plus loin
    Sphere sphereMiddle(Vector3(0, 0, -6), 1, colorMiddle);   // Un peu plus loin
    Sphere sphereRight(Vector3(-2.5, 0, -5), 1, colorLeft);    // Position la plus proche
    

    std::vector<Object*> objects = { &sphereLeft, &sphereMiddle, &sphereRight };

    // Caméra avec un angle de vue ajusté pour capturer l'ensemble
    int imageWidth = 800;
    int imageHeight = 600;
    Camera camera(Vector3(0, 0, 0), Vector3(0, 0, -1), Vector3(0, 1, 0), 60.0, imageWidth, imageHeight);

    // Créer la scène avec la caméra et les objets sans lumière ni plan
    Scene scene(camera, objects);

    // Définir le fond bleu ciel pour la scène
    scene.setBackground(Color(0.53f, 0.81f, 0.98f));

    // Initialiser une image pour le rendu final
    Image image(imageWidth, imageHeight, scene.getBackground()); // Fond bleu ciel

    // Boucle sur chaque pixel de l'image
    for (unsigned int y = 0; y < imageHeight; ++y) {
        for (unsigned int x = 0; x < imageWidth; ++x) {
            // Calculer la direction du rayon pour le pixel (x, y)
            Ray ray = camera.generateRay(x, y);

            // Tracer le rayon dans la scène et obtenir la couleur du pixel
            Color pixelColor = scene.traceRay(ray);

            // Définir la couleur du pixel dans l'image
            image.SetPixel(x, y, pixelColor);
        }
    }

    // Sauvegarder l'image dans un fichier PNG
    image.WriteFile("../../../output.png");

    std::cout << "Image rendue et sauvegardée en tant que 'output.png'." << std::endl;
    return 0;
}
