#pragma once

#include <iostream>
#include <vector>
#include "../raymath/Color.hpp"
#include "../raymath/Ray.hpp"
#include "../raymath/Vector3.h"
#include "Object.hpp"

/**
 * @class Polygon
 * @brief Represents a 3D polygon with vertices and a color.
 */
class Polygon : public Object {
private:
    std::vector<Vector3> vertices;
    Color color;

public:
    Polygon(const std::vector<Vector3> &iVertices, const Color &iColor, double reflectivity = 0.0);

    ~Polygon();


    const std::vector<Vector3> &Vertices() const;

    Color getColor() const override;

  void setColor(const Color &iColor) override;

    std::optional<double> intersects(const Ray &iRay) const override;

    friend std::ostream &operator<<(std::ostream &_stream, const Polygon &polygon);
};
