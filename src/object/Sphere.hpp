#pragma once
#include "../raymath/Color.hpp"
#include "../raymath/Vector3.h"
#include "Object.hpp"

/**
 * @class Sphere
 * @brief Represents a 3D sphere object in the scene.
 */
class Sphere : public Object {
public:
    /**
     * @brief Constructs a Sphere object.
     *
     * @param center The center of the sphere.
     * @param radius The radius of the sphere.
     * @param color The color of the sphere.
     * @param reflectivity The reflectivity of the sphere (default is 0.0).
     */
    Sphere(Vector3 center, double radius, Color color, double reflectivity = 0.0);

    /**
     * @brief Destructor for the Sphere class.
     */
    ~Sphere() override;

    /**
     * @brief Determines if a given ray intersects with the sphere.
     *
     * @param ray The ray to test for intersection.
     * @return An optional double representing the distance to the intersection point if there is an intersection, or
     * std::nullopt if there is no intersection.
     */
    std::optional<double> intersects(const Ray &ray) const override;

    /**
     * @brief Determines if a given ray intersects with the sphere and returns the hit record.
     *
     * @param r The ray to test for intersection.
     * @param t_min The minimum distance to consider for intersection.
     * @param t_max The maximum distance to consider for intersection.
     * @param rec The hit record to populate if there is an intersection.
     * @return A boolean indicating if there was an intersection.
     */
    bool hit(const Ray &r, double t_min, double t_max, hit_record &rec) const override;

    /**
     * @brief Getter for the origin of the sphere.
     *
     * @return A Vector3 object representing the origin of the sphere.
     */
    Vector3 Origin() const;

    /**
     * @brief Getter for the radius of the sphere.
     *
     * @return A float representing the radius of the sphere.
     */
    float Radius() const;

    /**
     * @brief Getter for the reflectivity of the sphere.
     *
     * @return A double representing the reflectivity of the sphere.
     */
    double getReflectivity() override;

    /**
     * @brief Getter for the color of the sphere.
     *
     * @return A Color object representing the color of the sphere.
     */
    Color getColor() const override;

    /**
     * @brief Setter for the origin of the sphere.
     *
     * @param iOrigin A Vector3 object representing the new origin of the sphere.
     */
    void setOrigin(Vector3 iOrigin);

    /**
     * @brief Setter for the radius of the sphere.
     *
     * @param iRadius A float representing the new radius of the sphere.
     */
    void setRadius(float iRadius);

    /**
     * @brief Setter for the color of the sphere.
     *
     * @param iColor A Color object representing the new color of the sphere.
     */
    void setColor(const Color &iColor) override;

    /**
     * @brief Setter for the reflectivity of the sphere.
     *
     * @param iReflectivity A double representing the new reflectivity of the sphere.
     */
    void setReflectivity(double iReflectivity) override;

    /**
     * @brief Overloaded stream insertion operator for the Sphere class.
     *
     * @param _stream The output stream to write to.
     * @param sphere The Sphere object to write to the stream.
     * @return A reference to the output stream.
     */
    friend std::ostream &operator<<(std::ostream &_stream, const Sphere &sphere);

private:
    Vector3 origin;
    float radius;
};
