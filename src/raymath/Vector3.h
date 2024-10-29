#pragma once
#include <cmath>
#include <ostream>

class Vector3 {
public:
    float x, y, z;

    // Constructor to initialize the vector
    Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f);

    // Overloaded operators for vector operations
    Vector3 operator+(const Vector3 &other) const;

    Vector3 operator-(const Vector3 &other) const;

    Vector3 operator-() const;

    Vector3 operator*(double scalar) const;

    float operator*(const Vector3 &other) const;

    Vector3 operator/(double scalar) const;

    // Methods to get the length of the vector
    double length() const;

    double length_squared() const;

    // Method to get a normalized vector (unit vector)
    Vector3 normalized() const;
};

// Overloading the stream operator to display the vector
inline std::ostream &operator<<(std::ostream &out, const Vector3 &v) {
    return out << v.x << ' ' << v.y << ' ' << v.z;
}
