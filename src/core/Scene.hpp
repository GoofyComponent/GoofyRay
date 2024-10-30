#pragma once

#include <vector>
#include "Camera.hpp"
#include "../raymath/Color.hpp"
#include "../raymath/Ray.hpp"
#include "../object/Object.hpp"
#include "../raymath/Light.hpp"


class Scene
{
public:
    Scene(const Camera &camera, const std::vector<Object *> &objects, const std::vector<Light> &lights = {});
    
    const std::vector<Light> &getLights() const;
    void setLights(const std::vector<Light> &lights);

    // Fonction pour calculer l'éclairage en fonction des lumières
    Color calculateLighting(const Vector3 &point, const Vector3 &normal, const Vector3 &viewDir, const Color &objectColor) const;

    // Getters
    const Camera &getCamera() const;
    const std::vector<Object *> &getObjects() const;
    const Color &getBackground() const;

    // Setters
    void setCamera(const Camera &camera);
    void setObjects(const std::vector<Object *> &objects);
    void setBackground(const Color &color);

    // Méthode pour tracer un rayon dans la scène
    Color traceRay(const Ray &ray, int depth) const;

private:
    Camera m_camera;
    std::vector<Object *> m_objects;
    Color m_background; // Couleur de fond par défaut (bleu ciel)
    std::vector<Light> m_lights;
    int m_maxDepth = 3; // Profondeur maximale pour les réflexions
};
