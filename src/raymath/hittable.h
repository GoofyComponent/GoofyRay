//
// Created by dev-tgamiette on 28/10/2024.
//

#ifndef HITTABLE_H
#define HITTABLE_H
#include "Ray.h"


class hit_record {
public:
    Vector p;
    Vector normal;
    double t;
};

class hittable {
public:
    virtual ~hittable() = default;

    virtual bool hit(Ray const &ray, double tMin, double tMax, hit_record &rec) = 0;
};

#endif //HITTABLE_H
