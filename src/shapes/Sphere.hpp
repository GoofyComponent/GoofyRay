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
    float x, y, z;
    float radius;
    Color color;

public:
    /**
     * @brief Default constructor for a unit sphere at the origin with a black color.
     */
    Sphere();

    /**
     * @brief Constructs a sphere with a specified center, radius, and color.
     * @param iX X-coordinate of the center.
     * @param iY Y-coordinate of the center.
     * @param iZ Z-coordinate of the center.
     * @param iRadius Radius of the sphere.
     * @param iColor Color of the sphere.
     */
    Sphere(float iX, float iY, float iZ, float iRadius, const Color &iColor);

    /**
     * @brief Destructor for the sphere.
     */
    ~Sphere();

    /**
     * @brief Gets the X-coordinate of the center.
     * @return X-coordinate of the center.
     */
    float getX() const;

    /**
     * @brief Gets the Y-coordinate of the center.
     * @return Y-coordinate of the center.
     */
    float getY() const;

    /**
     * @brief Gets the Z-coordinate of the center.
     * @return Z-coordinate of the center.
     */
    float getZ() const;

    /**
     * @brief Gets the radius of the sphere.
     * @return Radius of the sphere.
     */
    float getRadius() const;

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
    std::optional<Vector3> intersects(const Ray &iRay) const override;

    /**
     * @brief Sets the center of the sphere.
     * @param iX New X-coordinate of the center.
     * @param iY New Y-coordinate of the center.
     * @param iZ New Z-coordinate of the center.
     */
    void setCenter(float iX, float iY, float iZ);

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
