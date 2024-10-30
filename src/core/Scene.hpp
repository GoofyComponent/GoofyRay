#pragma once

#include <vector>
#include "Camera.hpp"
#include "../raymath/Color.hpp"
#include "../raymath/Ray.hpp"
#include "../object/Object.hpp"

class Scene
{
public:
    Scene(const Camera &camera, const std::vector<Object *> &objects);

    // Getters
    const Camera &getCamera() const;
    const std::vector<Object *> &getObjects() const;
    const Color &getBackground() const;

    // Setters
    void setCamera(const Camera &camera);
    void setObjects(const std::vector<Object *> &objects);
    void setBackground(const Color &color);

    // Méthode pour tracer un rayon dans la scène
    Color traceRay(const Ray &ray) const;

private:
    Camera m_camera;
    std::vector<Object *> m_objects;
    Color m_background; // Couleur de fond par défaut (bleu ciel)
};
