#pragma once

#include "Color.hpp"
#include "Ray.hpp"
#include "Hittable.hpp"
#include <iostream>

/**
 * @class Sphere
 * @brief Represents a 3D sphere with position, radius, and color.
 */
class Sphere : public Hittable
{
private:
    Vector3 origin;
    float radius;
    Color color;

public:
    /**
     * @brief Constructs a sphere with a specified center, radius, and color.
     * @param iOrigin Center of the sphere.
     * @param iRadius Radius of the sphere.
     * @param iColor Color of the sphere.
     */
    Sphere(Vector3 iOrigin, float iRadius, const Color &iColor);

    /**
     * @brief Destructor for the sphere.
     */
    ~Sphere();

    /**
     * @brief Gets the center of the sphere.
     * @return Center of the sphere.
     */
    Vector3 Origin() const;

    /**
     * @brief Gets the radius of the sphere.
     * @return Radius of the sphere.
     */
    float Radius() const;

    /**
     * @brief Gets the color of the sphere.
     * @return Color of the sphere.
     */
    Color getColor() const;

    /**
     * @brief Checks if a ray intersects with the sphere.
     * @param iRay The ray to check for intersection.
     * @return The intersection point as Vector3 if it exists, std::nullopt otherwise.
     */
    std::optional<std::vector<Vector3>> intersects(const Ray &iRay) const override;

    /**
     * @brief Sets the center of the sphere.
     * @param iOrigin New center of the sphere.
     */
    void setOrigin(Vector3 iOrigin);

    /**
     * @brief Sets the radius of the sphere.
     * @param iRadius New radius of the sphere.
     */
    void setRadius(float iRadius);

    /**
     * @brief Sets the color of the sphere.
     * @param iColor New color of the sphere.
     */
    void setColor(const Color &iColor);

    /**
     * @brief Overriding the output stream operator for Sphere.
     *
     * This function outputs the sphere's center coordinates, radius, and color to an output stream.
     *
     * @param _stream The output stream.
     * @param sphere The Sphere object to output.
     * @return std::ostream& A reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &_stream, const Sphere &sphere);
};
