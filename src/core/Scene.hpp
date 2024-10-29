#ifndef SCENE_HPP
#define SCENE_HPP

#include "Camera.hpp"
#include "../core/Light.hpp"
#include "../rayimage/Image.hpp"
#include <vector>

class Scene {
public:
    Scene(unsigned int imageWidth, unsigned int imageHeight, const Camera& camera );

    void setCamera(const Camera& camera);
    void addLight(const Light& light);
    void render();

    const Image& getImage() const { return m_image; }

private:
    Camera m_camera;
    Image m_image;
    std::vector<Light> m_lights;
    bool hasCamera = false;
};

#endif
