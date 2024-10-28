//
// Created by dev-tgamiette on 28/10/2024.
//

#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <ostream>

class Vector {
    float x;
    float y;
    float z;

public:
    Vector(float x, float y, float z);

    ~Vector();

    float X() const {
        return x;
    }

    float Y() const {
        return y;
    }

    float Z() const {
        return z;
    }

    Vector operator+(Vector const &other) const {
        return Vector(x + other.x, y + other.y, z + other.z);
    }

    Vector operator-(Vector const &other) const {
        return Vector(x - other.x, y - other.y, z - other.z);
    }

    Vector operator*(const double scalar) const {
        return Vector(x * scalar, y * scalar, z * scalar);
    }

    Vector operator/(const double scalar) const {
        return Vector(x / scalar, y / scalar, z / scalar);
    }

    double length() const {
        return sqrt(x * x + y * y + z * z);
    }

    double length_squared() const {
        return x * x + y * y + z * z;
    }
};

// Fonctions utilitaires
inline std::ostream& operator<<(std::ostream& out, const Vector& v) {
    return out << v.X() << ' ' << v.Y() << ' ' << v.Z();
}


#endif //VECTOR_H
