#pragma once

#include "../raymath/Color.hpp"
#include "../raymath/Vector3.h"
#include "../raymath/Ray.hpp"
#include "Object.hpp"
#include <vector>
#include <iostream>

/**
 * @class Polygon
 * @brief Represents a 3D polygon with vertices and a color.
 */
class Polygon : public Object
{
private:
    std::vector<Vector3> vertices;
    Color color;

public:
    /**
     * @brief Constructs a polygon with specified vertices and color.
     * @param iVertices List of vertices defining the polygon.
     * @param iColor Color of the polygon.
     */
    Polygon(const std::vector<Vector3> &iVertices, const Color &iColor);

    /**
     * @brief Destructor for the polygon.
     */
    ~Polygon();

    /**
     * @brief Gets the vertices of the polygon.
     * @return A vector of vertices defining the polygon.
     */
    const std::vector<Vector3> &Vertices() const;

    /**
     * @brief Gets the color of the polygon.
     * @return Color of the polygon.
     */
    Color getColor() const override;

    /**
     * @brief Sets the color of the polygon.
     * @param iColor New color of the polygon.
     */
    void setColor(const Color &iColor);

    /**
     * @brief Checks if a ray intersects with the polygon.
     * @param iRay The ray to check for intersection.
     * @return True if the ray intersects with the polygon, false otherwise.
     */
    std::optional<Vector3> intersects(const Ray &iRay) const override;

    /**
     * @brief Overriding the output stream operator for Polygon.
     *
     * This function outputs the polygon's vertices and color to an output stream.
     *
     * @param _stream The output stream.
     * @param polygon The Polygon object to output.
     * @return std::ostream& A reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &_stream, const Polygon &polygon);
};
