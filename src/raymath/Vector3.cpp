#include "Vector3.h"

// Définition du constructeur
Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

// Définition du destructeur
Vector3::~Vector3() {}

// Définition de l'opérateur d'addition
Vector3 Vector3::operator+(const Vector3& other) const {
    return Vector3(x + other.x, y + other.y, z + other.z);
}

// Définition de l'opérateur de soustraction
Vector3 Vector3::operator-(const Vector3& other) const {
    return Vector3(x - other.x, y - other.y, z - other.z);
}

// Définition de l'opérateur de multiplication par un scalaire
Vector3 Vector3::operator*(const double scalar) const {
    return Vector3(x * scalar, y * scalar, z * scalar);
}

// Définition de l'opérateur de division par un scalaire
Vector3 Vector3::operator/(const double scalar) const {
    return Vector3(x / scalar, y / scalar, z / scalar);
}

// Définition de la méthode pour obtenir la longueur du vecteur
double Vector3::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

// Définition de la méthode pour obtenir le carré de la longueur du vecteur
double Vector3::length_squared() const {
    return x * x + y * y + z * z;
}
