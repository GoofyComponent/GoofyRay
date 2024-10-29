#include "Scene.hpp"
#include <stdexcept>
#include <algorithm> // Pour std::max et std::min

Scene::Scene(unsigned int imageWidth, unsigned int imageHeight, const Camera &camera)
    : m_image(imageWidth, imageHeight), m_camera(camera) {}

void Scene::setCamera(const Camera &camera)
{
    m_camera = camera;
    hasCamera = true;
}

void Scene::addLight(const Light& light) {
    m_lights.push_back(light);
}

void Scene::render() {
    unsigned int width = m_image.getWidth();
    unsigned int height = m_image.getHeight();

    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
            // Générer un rayon de la caméra pour chaque pixel
            Ray ray = m_camera.generateRay(x, y);

            // Initialiser la couleur du pixel (fond noir par défaut)
            Color pixelColor(0, 0, 0);

            // Calculer la contribution de chaque source de lumière
            for (const Light& light : m_lights) {
                // Calculer la direction vers la lumière
                Vector3 lightDirection = light.getPosition() - ray.Origin();
                float distance = lightDirection.length();

                // Distance maximale d'atténuation, ajustable
                const float maxDistance = 15.0f;
                float intensity = std::max(0.0f, 1.0f - (distance / maxDistance));

                // Appliquer l'intensité à la couleur de la lumière
                Color lightContribution = light.getColor() * intensity;

                // Additionner la contribution de la lumière au pixel
                pixelColor = pixelColor + lightContribution;
            }

            // Limiter les valeurs de la couleur entre 0 et 1 pour chaque canal
            pixelColor = Color(std::min(pixelColor.R(), 1.0f),
                               std::min(pixelColor.G(), 1.0f),
                               std::min(pixelColor.B(), 1.0f));

            // Définir la couleur calculée pour le pixel
            m_image.SetPixel(x, y, pixelColor);
        }
    }
}
