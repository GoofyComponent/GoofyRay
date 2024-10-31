#pragma once
#include <algorithm>
#include <iostream>

class Color {
public:
    float r, g, b;

    // Constructeurs
    Color();
    Color(float iR, float iG, float iB);
    ~Color();

    // Méthodes d'accès
    float R() const;
    float G() const;
    float B() const;

    // Opérateurs arithmétiques de base
    Color operator+(const Color &other) const;
    Color operator-(const Color &other) const;
    Color operator*(const Color &other) const;
    Color operator/(const Color &other) const;

    // Opérateurs avec des scalaires
    Color operator*(float scalar) const;
    Color operator/(float scalar) const;

    // Opérateurs d'affectation avec des couleurs
    Color &operator+=(const Color &other);
    Color &operator-=(const Color &other);
    Color &operator*=(const Color &other);
    Color &operator/=(const Color &other);

    // Opérateurs d'affectation avec des scalaires
    Color &operator*=(float scalar);
    Color &operator/=(float scalar);

    // Opérateur d'affectation
    Color &operator=(const Color &col);

    // Opérateurs de comparaison
    bool operator==(const Color &other) const;
    bool operator!=(const Color &other) const;

    // Affichage de la couleur
    friend std::ostream &operator<<(std::ostream &os, const Color &color);

    friend std::istream& operator>>(std::istream& _stream, Color& col);

    friend std::ostream &operator<<(std::ostream &os, const Color &color);Color clamped();
};

// Opérateurs avec des scalaires pour permettre le scalar * color
inline Color operator*(float scalar, const Color &color) {
    return Color(color.r * scalar, color.g * scalar, color.b * scalar);
}
