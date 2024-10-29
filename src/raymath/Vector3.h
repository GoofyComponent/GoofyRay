#pragma once
#include <cmath>
#include <ostream>

class Vector3 {
public:
    float x, y, z;

    // Constructeur
    Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f);

    // Surcharges des opérateurs
    Vector3 operator+(const Vector3 &other) const;
    Vector3 operator-(const Vector3 &other) const;
    Vector3 operator-() const;
    Vector3 operator*(double scalar) const;
    Vector3 operator*(float scalar) const;
    float operator*(const Vector3 &other) const;
    Vector3 operator/(double scalar) const;

    // Méthodes de la classe
    double length() const;
    double length_squared() const;
    Vector3 normalized() const;
    Vector3 cross(const Vector3 &other) const;
};

// Surcharge de l'opérateur * pour permettre double * Vector3 (hors de la classe)
Vector3 operator*(double scalar, const Vector3& vec);

// Affichage de Vector3 dans le flux de sortie
inline std::ostream &operator<<(std::ostream &out, const Vector3 &v) {
    return out << v.x << ' ' << v.y << ' ' << v.z;
}
