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
Color Scene::traceRay(const Ray &ray, int depth = 5) {
    if (depth <= 0) {
        return {0, 0, 0}; // Retourne noir si la profondeur maximale est atteinte
    }

    double closestDistance = std::numeric_limits<double>::max();
    hit_record closestHit; // Le hit_record pour l'objet le plus proche
    bool hasHit = false;

    for (const auto &object: m_objects) {
        hit_record tempHit;

        if (object->hit(ray, 0.001, closestDistance, tempHit)) {
            hasHit = true;
            closestDistance = tempHit.t;
            closestHit = tempHit;
        }
    }

    if (!hasHit)
        return m_background;

    Color illuminatedColor(0, 0, 0);

    for (const auto &light: m_lights) {
        Vector3 lightDir = (light.position - closestHit.position).normalized();
        double lightIntensity = std::max(0.0, static_cast<double>(closestHit.normal * lightDir)) * light.intensity;

        // Ajoute la couleur de la lumière influencée par l'intensité et la couleur de l'objet
        illuminatedColor += closestHit.color * light.color * lightIntensity;
    }

    if (closestHit.reflectivity > 0) {
        // Direction de la réflexion
        const Vector3 reflectionDirection =
                ray.Direction() - 2 * (ray.Direction() * closestHit.normal) * closestHit.normal;
        Vector3 offsetPosition = closestHit.position + closestHit.normal * 1e-4;
        const Ray reflectedRay(offsetPosition, reflectionDirection.normalized());
        const Color reflectedColor = traceRay(reflectedRay, depth - 1);
        illuminatedColor = illuminatedColor * (1 - closestHit.reflectivity) + reflectedColor * closestHit.reflectivity;
    }

    return illuminatedColor;
}

void Scene::addLight(const Light &light) { m_lights.push_back(light);}
