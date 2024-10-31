#include "Sphere.hpp"
#include <cmath>

Sphere::Sphere(Vector3 center, double radius, Color color, double reflectivity) :
    origin(center), radius(radius), Object(color, reflectivity) {}

// Détecte l'intersection avec un rayon
std::optional<double> Sphere::intersects(const Ray &iRay) const {
    Vector3 oc = origin - iRay.Origin();

    // Calculate the dot product which is just a float
    float dotProd = oc * iRay.Direction();

    // Multiply the dot product with the ray's direction vector
    Vector3 op = dotProd * iRay.Direction();

    Vector3 p = iRay.Origin() + op;

    // Displacement vector from c to p
    Vector3 cp = p - origin;

    // calculate the length of a vector using pythagoras
    float distance = cp.length();


    if (distance > radius) {
        return std::nullopt;
    }

    float halfChord = std::sqrt(radius * radius - distance * distance);
    double t = dotProd - halfChord; // Calcule la distance t depuis l'origine du rayon

    // Renvoie la distance de l'intersection
    return t;
}


bool Sphere::hit(const Ray &r, double t_min, double t_max, hit_record &rec) const {
    // Récupère la distance d'intersection si elle existe
    auto distance = intersects(r);

    // Vérifie si une intersection valide existe dans la plage t_min et t_max
    if (!distance) {
        return false;
    }

    // Enregistrement des informations d'intersection
    rec.t = *distance;
    rec.position = r.At(rec.t);

    // Calcul de la normale et ajustement pour qu'elle soit orientée dans la bonne direction
    Vector3 outward_normal = (rec.position - origin) / radius;
    rec.set_face_normal(r, outward_normal);
    rec.color = getColor();
    rec.reflectivity = m_reflectivity;


    return true;
}

Sphere::~Sphere() = default;

std::ostream &operator<<(std::ostream &_stream, const Sphere &sphere) {
    _stream << "Sphere: " << std::endl;
    _stream << "Center: " << sphere.Origin() << std::endl;
    _stream << "Radius: " << sphere.Radius() << std::endl;
    _stream << "Color: " << sphere.getColor() << std::endl;
    return _stream;
}


// Renvoie la couleur de la sphère
Color Sphere::getColor() const { return m_color; }

void Sphere::setColor(const Color &iColor) { m_color = iColor; }

void Sphere::setRadius(float iRadius) { radius = iRadius; }

void Sphere::setOrigin(Vector3 iOrigin) { origin = iOrigin; }

float Sphere::Radius() const { return radius; }

Vector3 Sphere::Origin() const { return origin; }

void Sphere::setReflectivity(double iReflectivity) { m_reflectivity = iReflectivity; }

double Sphere::getReflectivity() { return m_reflectivity; }
