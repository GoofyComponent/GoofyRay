#include "Color.hpp"
#include <algorithm>

// Constructeurs et destructeur
Color::Color() : r(0), g(0), b(0) {}
Color::Color(float iR, float iG, float iB) : r(iR), g(iG), b(iB) {}
Color::~Color() {}

// Méthodes d'accès
float Color::R() const { return r; }
float Color::G() const { return g; }
float Color::B() const { return b; }

// Opérateurs arithmétiques de base
Color Color::operator+(const Color &col) const {
    return Color(std::clamp(r + col.r, 0.0f, 1.0f), std::clamp(g + col.g, 0.0f, 1.0f),
                 std::clamp(b + col.b, 0.0f, 1.0f));
}

Color Color::operator-(const Color &col) const {
    return Color(std::clamp(r - col.r, 0.0f, 1.0f), std::clamp(g - col.g, 0.0f, 1.0f),
                 std::clamp(b - col.b, 0.0f, 1.0f));
}

Color Color::operator*(const Color &col) const { return Color(r * col.r, g * col.g, b * col.b); }

Color Color::operator/(const Color &col) const { return Color(r / col.r, g / col.g, b / col.b); }

// Opérateurs avec des scalaires
Color Color::operator*(float scalar) const { return Color(r * scalar, g * scalar, b * scalar); }

Color Color::operator/(float scalar) const { return Color(r / scalar, g / scalar, b / scalar); }

// Opérateurs d'affectation avec des couleurs
Color &Color::operator+=(const Color &col) {
    r = std::clamp(r + col.r, 0.0f, 1.0f);
    g = std::clamp(g + col.g, 0.0f, 1.0f);
    b = std::clamp(b + col.b, 0.0f, 1.0f);
    return *this;
}

Color &Color::operator-=(const Color &col) {
    r = std::clamp(r - col.r, 0.0f, 1.0f);
    g = std::clamp(g - col.g, 0.0f, 1.0f);
    b = std::clamp(b - col.b, 0.0f, 1.0f);
    return *this;
}

Color &Color::operator*=(const Color &col) {
    r *= col.r;
    g *= col.g;
    b *= col.b;
    return *this;
}

Color &Color::operator/=(const Color &col) {
    r /= col.r;
    g /= col.g;
    b /= col.b;
    return *this;
}

// Opérateurs d'affectation avec des scalaires
Color &Color::operator*=(float scalar) {
    r = std::clamp(r * scalar, 0.0f, 1.0f);
    g = std::clamp(g * scalar, 0.0f, 1.0f);
    b = std::clamp(b * scalar, 0.0f, 1.0f);
    return *this;
}

Color &Color::operator/=(float scalar) {
    r = std::clamp(r / scalar, 0.0f, 1.0f);
    g = std::clamp(g / scalar, 0.0f, 1.0f);
    b = std::clamp(b / scalar, 0.0f, 1.0f);
    return *this;
}

// Opérateur d'affectation
Color &Color::operator=(const Color &col) {
    r = col.r;
    g = col.g;
    b = col.b;
    return *this;
}

bool Color::operator==(const Color &other) const { return r == other.r && g == other.g && b == other.b; }

bool Color::operator!=(const Color &other) const { return !(*this == other); }

// Affichage
std::ostream &operator<<(std::ostream &os, const Color &color) {
    os << "Color(" << color.r << ", " << color.g << ", " << color.b << ")";
    return os;
}

std::istream& operator>>(std::istream& _stream, Color& col) {
    _stream >> col.r >> col.g >> col.b;
    return _stream;
}

Color Color::clamped() {
    return Color(std::clamp(r, 0.0f, 1.0f), std::clamp(g, 0.0f, 1.0f), std::clamp(b, 0.0f, 1.0f));
}
