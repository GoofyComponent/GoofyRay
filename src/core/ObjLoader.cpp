#include "../core/ObjLoader.h"
#include <cmath>
#include "../tinyobjloader/tiny_obj_loader.h"
#include "../object/Triangle.h"

// Fonction pour appliquer une rotation simple autour de l'axe Y (extension possible pour X et Z)
Vector3 rotateY(const Vector3 &point, double angle) {
    double cosA = std::cos(angle);
    double sinA = std::sin(angle);
    return Vector3(point.x * cosA + point.z * sinA, point.y, -point.x * sinA + point.z * cosA);
}

void loadObjFile(const std::string &filename, Scene &scene, const Color &color, double reflectivity,
                 const Vector3 &position, const Vector3 &rotation, const Vector3 &scale) {
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::string warn, err;

    if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, filename.c_str())) {
        std::cerr << "Erreur chargement .obj: " << err << std::endl;
        return;
    }

    for (const auto &shape : shapes) {
        for (size_t i = 0; i < shape.mesh.indices.size(); i += 3) {
            tinyobj::index_t idx0 = shape.mesh.indices[i];
            tinyobj::index_t idx1 = shape.mesh.indices[i + 1];
            tinyobj::index_t idx2 = shape.mesh.indices[i + 2];

            Vector3 v0(
                attrib.vertices[3 * idx0.vertex_index + 0],
                attrib.vertices[3 * idx0.vertex_index + 1],
                attrib.vertices[3 * idx0.vertex_index + 2]
            );
            Vector3 v1(
                attrib.vertices[3 * idx1.vertex_index + 0],
                attrib.vertices[3 * idx1.vertex_index + 1],
                attrib.vertices[3 * idx1.vertex_index + 2]
            );
            Vector3 v2(
                attrib.vertices[3 * idx2.vertex_index + 0],
                attrib.vertices[3 * idx2.vertex_index + 1],
                attrib.vertices[3 * idx2.vertex_index + 2]
            );

            // Appliquer l'échelle
            v0 = Vector3(v0.x * scale.x, v0.y * scale.y, v0.z * scale.z);
            v1 = Vector3(v1.x * scale.x, v1.y * scale.y, v1.z * scale.z);
            v2 = Vector3(v2.x * scale.x, v2.y * scale.y, v2.z * scale.z);

            // Appliquer la rotation (exemple uniquement avec l'axe Y ici)
            v0 = rotateY(v0, rotation.y);
            v1 = rotateY(v1, rotation.y);
            v2 = rotateY(v2, rotation.y);

            // Appliquer la translation
            v0 = v0 + position;
            v1 = v1 + position;
            v2 = v2 + position;

            Triangle *triangle = new Triangle(v0, v1, v2, color, reflectivity);
            scene.addObject(triangle);
        }
    }
}
