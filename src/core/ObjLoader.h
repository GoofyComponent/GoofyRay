// ObjLoader.hpp
#ifndef OBJLOADER_HPP
#define OBJLOADER_HPP

#include "Scene.hpp"

void loadObjFile(const std::string &filename, Scene &scene, const Color &color, double reflectivity,
                 const Vector3 &position = Vector3(0, 0, 0),
                 const Vector3 &rotation = Vector3(0, 0, 0),
                 const Vector3 &scale = Vector3(1, 1, 1));

#endif
