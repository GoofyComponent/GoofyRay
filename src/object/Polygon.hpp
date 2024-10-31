#pragma once

#include <iostream>
#include <vector>
#include "../raymath/Color.hpp"
#include "../raymath/Ray.hpp"
#include "../raymath/Vector3.h"
#include "Object.hpp"

class Polygon : public Object {
private:
    std::vector<Vector3> vertices;
    Color color;

public:
    /**
     * @class Polygon
     * @brief Represents a 3D polygon with vertices and a color.
     */
    /**
     * Constructor for the Polygon class.
     *
     * @param iVertices A vector of Vector3 objects representing the vertices of the polygon.
     * @param iColor A Color object representing the color of the polygon.
     * @param reflectivity A double representing the reflectivity of the polygon. Default is 0.0.
     */
    Polygon(const std::vector<Vector3> &iVertices, const Color &iColor, double reflectivity = 0.0);

    /**
     * Destructor for the Polygon class.
     */
    ~Polygon() override;

    /**
     * Getter for the vertices of the polygon.
     *
     * @return A constant reference to a vector of Vector3 objects representing the vertices of the polygon.
     */
    const std::vector<Vector3> &Vertices() const;

    /**
     * Getter for the color of the polygon.
     *
     * @return A Color object representing the color of the polygon.
     */
    Color getColor() const override;

    /**
     * Setter for the color of the polygon.
     *
     * @param iColor A Color object representing the new color of the polygon.
     */
    void setColor(const Color &iColor) override;

    /**
     * Determines if a given ray intersects with the polygon.
     *
     * @param iRay A Ray object representing the ray to test for intersection.
     * @return An optional double representing the distance to the intersection point if there is an intersection, or
     * std::nullopt if there is no intersection.
     */
    std::optional<double> intersects(const Ray &iRay) const override;

    /**
     * Overloaded stream insertion operator for the Polygon class.
     *
     * @param _stream The output stream to write to.
     * @param polygon The Polygon object to write to the stream.
     * @return A reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &_stream, const Polygon &polygon);
};
