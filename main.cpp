#include <iostream>
#include "Vector3.h"
#include "Ray.hpp"

using namespace std;


int main() {
    auto const vector1 = Vector3(0, 0, 0);
    auto const vector2 = Vector3(255, 255, 2555);

    cout << "Vector1: " << vector1 << endl;
    cout << "Vector2: " << vector2 << endl;

    Ray const ray = Ray(vector1, vector2);

    cout << "Ray origin: " << ray.Origin() << endl;
    cout << "Ray direction: " << ray.Direction() << endl;
    cout << "Ray scaled at 2: " << ray.At(2) << endl;
}
