#include "Scene.hpp"

Scene::Scene(const Camera &camera, const std::vector<Object *> &objects)
    : m_camera(camera), m_objects(objects), m_background(Color(0.53f, 0.81f, 0.98f)) {}

// Getter pour la caméra
const Camera &Scene::getCamera() const
{
    return m_camera;
}

// Getter pour les objets
const std::vector<Object *> &Scene::getobjects() const
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
void Scene::setobjects(const std::vector<Object *> &objects)
{
    m_objects = objects;
}

// Setter pour la couleur de fond
void Scene::setBackground(const Color &color)
{
    m_background = color;
}

// Méthode pour tracer un rayon dans la scène
Color Scene::traceRay(const Ray &ray) const
{
    double closestDistance = std::numeric_limits<double>::max();
    Object *closestobject = nullptr;
    Vector3 hitPoint;

    for (const auto &object : m_objects)
    {
        if (auto intersection = object->intersects(ray))
        {
            if (intersection.has_value())
            {
                double distance = (intersection.value() - ray.Origin()).length();
                if (distance < closestDistance)
                {
                    closestDistance = distance;
                    closestobject = object;
                    hitPoint = intersection.value();
                }
            }
        }
    }

    // Si aucun objet n'est intersecté, retourner la couleur de fond
    if (!closestobject)
        return m_background;

    // Retourne la couleur de l'objet le plus proche
    return closestobject->getColor();
}
