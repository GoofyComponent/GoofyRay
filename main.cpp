#include "Scene.hpp"
#include "Camera.hpp"
#include "Light.hpp"
#include "Vector3.h"
#include "Color.hpp"

int main() {
    // Paramètres de l'image
    unsigned int imageWidth = 800;
    unsigned int imageHeight = 600;

    // Création de la scène

    // Création et configuration de la caméra
    Vector3 cameraPosition(0, 0, 0);          // Position de la caméra à l'origine
    Vector3 cameraDirection(0, 0, 1);        // La caméra regarde vers -Z
    float viewportWidth = 2.0f;               // Largeur du champ de vision
    float viewportHeight = 1.5f;              // Hauteur du champ de vision
    float focalLength = 1.0f;                 // Distance focale
    Camera camera(cameraPosition, cameraDirection, viewportWidth, viewportHeight, imageWidth, imageHeight, focalLength);
    
    // Associer la caméra à la scène
    // scene.setCamera(camera);
    Scene scene(imageWidth, imageHeight, camera);


    // Création d'une source de lumière
    Vector3 lightPosition(5, 5, -10);         // Position de la lumière
    Color lightColor(1.0, 1.0, 1.0);          // Lumière blanche
    Light light(lightPosition, lightColor);
    
    // Ajouter la lumière à la scène
    scene.addLight(light);

    // Lancer le rendu de la scène
    scene.render();

    // Sauvegarder l'image rendue dans un fichier PNG
    scene.getImage().WriteFile("../../../output.png");

    // Indiquer que le rendu est terminé
    std::cout << "Rendu terminé. Image sauvegardée sous 'output.png'" << std::endl;

    return 0;
}
