#pragma once

#include <vector>
#include "../object/Object.hpp"
#include "../raymath/Color.hpp"
#include "../raymath/Light.h"
#include "../raymath/Ray.hpp"
#include "Camera.hpp"


class Scene {
public:
    Scene(const Camera &camera, const std::vector<Object *> &objects);

    const Camera& getCamera() const;
    const std::vector<Object*>& getObjects() const;
    const Color& getBackground() const;

    void setCamera(const Camera &camera);
    void setObjects(const std::vector<Object *> &objects);
    void setBackground(const Color &color);

    Color traceRay(const Ray &ray, int depth);
    void addLight(const Light &light);

private:
    Camera m_camera;
    std::vector<Object *> m_objects;
    Color m_background; // Couleur de fond par défaut (bleu ciel)
    std::vector<Light> m_lights;
};
