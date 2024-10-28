#ifndef RAY_H
#define RAY_H

#include "../raymath/Vector.h"

class Ray {
private:
    Vector orig;
    Vector direct;

public:
    Ray(const Vector &origin, const Vector &direction) : orig(origin), direct(direction) {
    }

    // Destructeur
    ~Ray() = default; // Si le destructeur ne fait rien, on peut utiliser "= default"

    // Accesseurs
    Vector origin() { return orig; }
    Vector direction() { return direct; }
};

#endif // RAY_H
