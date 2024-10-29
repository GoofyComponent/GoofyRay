#include "Vector3.h"

// Constructor
Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z)
{
}

// Operator overloads for vector operations
Vector3 Vector3::operator+(const Vector3 &other) const
{
    return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator-(const Vector3 &other) const
{
    return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator-() const
{
    return {-x, -y, -z};
}

Vector3 Vector3::operator*(const double scalar) const
{
    return Vector3(x * scalar, y * scalar, z * scalar);
}

Vector3 Vector3::operator*(const float scalar) const
{
    return Vector3(x * scalar, y * scalar, z * scalar);
}

Vector3 Vector3::operator/(const double scalar) const
{
    return Vector3(x / scalar, y / scalar, z / scalar);
}

float Vector3::operator*(const Vector3 &other) const
{
    return x * other.x + y * other.y + z * other.z;
}

// Method for vector length
double Vector3::length() const
{
    return std::sqrt(x * x + y * y + z * z);
}

double Vector3::length_squared() const
{
    return x * x + y * y + z * z;
}

// Normalize vector: returns a new vector with length 1
Vector3 Vector3::normalized() const
{
    double len = length();
    return Vector3(x / len, y / len, z / len);
}

// Cross product of two vectors
Vector3 Vector3::cross(const Vector3 &other) const
{
    return Vector3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
}