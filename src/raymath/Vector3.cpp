#include "Vector3.h"

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3 Vector3::operator+(const Vector3 &other) const {
    return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator-(const Vector3 &other) const {
    return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator-() const {
    return {-x, -y, -z};
}

Vector3 Vector3::operator*(const double scalar) const {
    return Vector3(x * scalar, y * scalar, z * scalar);
}

Vector3 Vector3::operator*(const float scalar) const {
    return Vector3(x * scalar, y * scalar, z * scalar);
}

float Vector3::operator*(const Vector3 &other) const {
    return x * other.x + y * other.y + z * other.z;
}

Vector3 Vector3::operator/(const double scalar) const {
    return Vector3(x / scalar, y / scalar, z / scalar);
}

double Vector3::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

double Vector3::length_squared() const {
    return x * x + y * y + z * z;
}

Vector3 Vector3::normalized() const {
    double len = length();
    return Vector3(x / len, y / len, z / len);
}

Vector3 Vector3::cross(const Vector3 &other) const {
    return Vector3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
}

Vector3 operator*(double scalar, const Vector3& vec) {
    return Vector3(vec.x * scalar, vec.y * scalar, vec.z * scalar);
}