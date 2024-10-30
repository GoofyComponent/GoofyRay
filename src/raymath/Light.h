//
// Created by dev-tgamiette on 30/10/2024.
//

#ifndef LIGHT_H
#define LIGHT_H

struct Light {
    Vector3 position;
    Color color;
    double intensity;

    Light(const Vector3 &pos, const Color &col, double inten) : position(pos), color(col), intensity(inten) {}
};


#endif // LIGHT_H
