#pragma once

#include "../raymath/Ray.hpp"
#include "../raymath/Vector3.h"
#include "Object.hpp"


/**
 * @class Plane
 * @brief Represents a plane in 3D space.
 */
class Plane : public Object {
private:
    Vector3 position;
    Vector3 normal;

public:
    /**
     * @brief Constructs a Plane object.
     *
     * @param position The position of the plane.
     * @param normal The normal vector of the plane.
     * @param iColor The color of the plane.
     * @param iReflection The reflectivity of the plane.
     */
    Plane(const Vector3 &position, const Vector3 &normal, const Color &iColor, double iReflection);

    /**
     * @brief Destructor for the Plane object.
     */
    ~Plane() override;

    /**
     * @brief Gets the position of the plane.
     *
     * @return The position of the plane.
     */
    Vector3 Position() const;

    /**
     * @brief Gets the normal vector of the plane.
     *
     * @return The normal vector of the plane.
     */
    Vector3 Normal() const;

    /**
     * @brief Checks if a ray intersects with the plane.
     *
     * @param ray The ray to check for intersection.
     * @return An optional containing the distance to the intersection point if there is an intersection, otherwise
     * std::nullopt.
     */
    std::optional<double> intersects(const Ray &ray) const override;

    /**
     * @brief Checks if a ray hits the plane within a given range.
     *
     * @param r The ray to check for a hit.
     * @param t_min The minimum distance to check for a hit.
     * @param t_max The maximum distance to check for a hit.
     * @param rec The hit record to store hit information.
     * @return True if the ray hits the plane within the given range, otherwise false.
     */
    bool hit(const Ray &r, double t_min, double t_max, hit_record &rec) const override;

    /**
     * @brief Gets the color of the plane.
     *
     * @return The color of the plane.
     */
    Color getColor() const override;

    /**
     * @brief Sets the color of the plane.
     *
     * @param iColor The new color of the plane.
     */
    void setColor(const Color &iColor) override;

    /**
     * @brief Sets the reflectivity of the plane.
     *
     * @param iReflectivity The new reflectivity of the plane.
     */
    void setReflectivity(double iReflectivity) override;

    /**
     * @brief Gets the reflectivity of the plane.
     *
     * @return The reflectivity of the plane.
     */
    double getReflectivity() override;
};
