#include "Scene.hpp"

Scene::Scene(const Camera &camera, const std::vector<Object *> &objects, const std::vector<Light> &lights)
    : m_camera(camera), m_objects(objects), m_background(Color(0.53f, 0.81f, 0.98f)), m_lights(lights) {}


    Color Scene::calculateLighting(const Vector3 &point, const Vector3 &normal, const Vector3 &viewDir, const Color &objectColor) const {
    Color ambient(0.1f, 0.1f, 0.1f);  // Éclairage ambiant fixe
    Color finalColor = ambient * objectColor;  // Commence avec l'ambiant

    for (const Light &light : m_lights) {
        Vector3 lightDir = (light.getPosition() - point).normalized();

        // Éclairage diffus
        float diff = std::max(0.0f, normal * lightDir);
        Color diffuse = objectColor * light.getColor() * diff * light.getIntensity();

        // Éclairage spéculaire
        Vector3 reflectDir = (2 * (normal * lightDir) * normal - lightDir).normalized();
        float spec = std::pow(std::max(0.0f, viewDir * reflectDir), 32);
        Color specular = light.getColor() * spec * light.getIntensity();

        finalColor = finalColor + diffuse + specular;
    }

    return finalColor;
}

// Getter pour la caméra
const Camera &Scene::getCamera() const
{
    return m_camera;
}

// Getter pour les objets
const std::vector<Object *> &Scene::getObjects() const
{
    return m_objects;
}

// Getter pour la couleur de fond
const Color &Scene::getBackground() const
{
    return m_background;
}

// Setter pour la caméra
void Scene::setCamera(const Camera &camera)
{
    m_camera = camera;
}

// Setter pour les objets
void Scene::setObjects(const std::vector<Object *> &objects)
{
    m_objects = objects;
}

// Setter pour la couleur de fond
void Scene::setBackground(const Color &color)
{
    m_background = color;
}

Color Scene::traceRay(const Ray &ray, int depth) const {
    if (depth > m_maxDepth) return m_background;

    double closestDistance = std::numeric_limits<double>::max();
    const Object *closestObject = nullptr;
    Vector3 hitPoint;
    Vector3 normal;

    for (const Object *object : m_objects) {
        std::optional<Vector3> intersection = object->intersects(ray);
        if (intersection.has_value()) {
            double distance = (intersection.value() - ray.Origin()).length();
            if (distance < closestDistance) {
                closestDistance = distance;
                closestObject = object;
                hitPoint = intersection.value();
                normal = object->getNormal(hitPoint);  // Assure que chaque objet implémente getNormal
            }
        }
    }

    // Si aucun objet n'est intersecté, retourne la couleur de fond
    if (!closestObject) return m_background;

    // Éclairage en utilisant la couleur de l'objet le plus proche
    Vector3 viewDir = -ray.Direction();
    Color localColor = calculateLighting(hitPoint, normal, viewDir, closestObject->getColor());

    // Calcul du rayon réfléchi
    Vector3 reflectDir = ray.Direction() - 2 * (ray.Direction() * normal) * normal;
    Ray reflectRay(hitPoint, reflectDir);

    // Couleur de réflexion
    Color reflectColor = traceRay(reflectRay, depth + 1);

    // Combiner la couleur locale et la couleur de réflexion
    return localColor + reflectColor * 0.5;  // Ajuste le coefficient pour l'intensité de réflexion
}
