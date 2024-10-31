#include "Scene.hpp"

Scene::Scene(const Camera &camera, const std::vector<Object *> &objects) :
    m_camera(camera), m_objects(objects), m_background(Color(0.53f, 0.81f, 0.98f)) {}

// Getter pour la caméra
const Camera &Scene::getCamera() const { return m_camera; }

// Getter pour les objets
const std::vector<Object *> &Scene::getObjects() const { return m_objects; }

// Getter pour la couleur de fond
const Color &Scene::getBackground() const { return m_background; }

// Setter pour la caméra
void Scene::setCamera(const Camera &camera) { m_camera = camera; }

// Setter pour les objets
void Scene::setObjects(const std::vector<Object *> &objects) { m_objects = objects; }

// Setter pour la couleur de fond
void Scene::setBackground(const Color &color) { m_background = color; }

// Méthode pour tracer un rayon dans la scène
// Méthode pour tracer un rayon dans la scène avec un éclairage Phong
Color Scene::traceRay(const Ray &ray, int depth = 5) {
    if (depth <= 0) {
        return {0, 0, 0}; // Retourne noir si la profondeur maximale est atteinte
    }

    hit_record closestHit;
    bool hasHit = false;

    for (const auto &object: m_objects) {
        hit_record tempHit;
        if (object->hit(ray, 0.0001, 10000, tempHit)) {
            hasHit = true;
            closestHit = tempHit;
        }
    }

    if (!hasHit)
        return m_background;

    Color ambientColor = closestHit.color * 0.1; // composante ambiante
    Color diffuseColor(0, 0, 0);
    Color specularColor(0, 0, 0);

    for (const auto &light: m_lights) {
        Vector3 lightDir = (light.position - closestHit.position).normalized();
        double lightIntensity = light.intensity;

        double diffuseFactor = std::max(0.0, static_cast<double>(closestHit.normal * lightDir));
        diffuseColor += closestHit.color * light.color * (diffuseFactor * lightIntensity);

        Vector3 viewDir = (m_camera.getPosition() - closestHit.position).normalized();
        Vector3 reflectDir = -(2 * (closestHit.normal * lightDir) * closestHit.normal - lightDir).normalized();
        double specularFactor =
                std::pow(std::max(0.0, static_cast<double>(viewDir * reflectDir)), 32); // Shininess = 32
        specularColor += light.color * (specularFactor * lightIntensity);
    }

    Color phongColor = ambientColor + diffuseColor + specularColor;

    if (closestHit.reflectivity > 0) {
        Vector3 reflectionDir = ray.Direction() - 2 * (ray.Direction() * closestHit.normal) * closestHit.normal;
        Vector3 offsetPosition = closestHit.position + closestHit.normal * 1e-4; // éviter l'auto-intersection
        Ray reflectedRay(offsetPosition, reflectionDir.normalized());
        Color reflectedColor = traceRay(reflectedRay, depth - 1);

        phongColor = phongColor * (1 - closestHit.reflectivity) + reflectedColor * closestHit.reflectivity;
    }

    return phongColor;
}
void Scene::addLight(const Light &light) { m_lights.push_back(light);}
