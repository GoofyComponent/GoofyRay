#pragma once
#include "../raymath/Ray.hpp"
#include "../raymath/Color.hpp"
#include <optional>
#include <vector>

class Object {
public:
    virtual ~Object() = default;

    // Méthode virtuelle pure pour l'intersection
    virtual std::optional<std::vector<Vector3>> intersects(const Ray &ray) const = 0;

    // Méthode virtuelle pure pour obtenir la couleur
    virtual Color getColor() const = 0;
};
