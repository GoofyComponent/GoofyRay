// Created by dev-tgamiette on 28/10/2024.

#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <ostream>

class Vector3 {
private:
    float x;
    float y;
    float z;

public:
    // Constructeur avec paramètres pour initialiser le vecteur
    Vector3(float x, float y, float z);

    // Destructeur
    ~Vector3();

    // Accesseurs pour les composantes du vecteur
    float X() const { return x; }
    float Y() const { return y; }
    float Z() const { return z; }

    // Opérateurs de surcharge pour les opérations de vecteur
    Vector3 operator+(const Vector3& other) const;
    Vector3 operator-(const Vector3& other) const;
    Vector3 operator*(const double scalar) const;
    Vector3 operator/(const double scalar) const;

    // Méthodes pour obtenir la longueur du vecteur
    double length() const;
    double length_squared() const;
};

// Surcharge de l'opérateur de flux pour afficher le vecteur
inline std::ostream& operator<<(std::ostream& out, const Vector3& v) {
    return out << v.X() << ' ' << v.Y() << ' ' << v.Z();
}

#endif // VECTOR3_HPP
