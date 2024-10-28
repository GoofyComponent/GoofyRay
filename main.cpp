#include <iostream>
#include "Vector3.h"

using namespace std;


int main() {
    auto const vector1 = Vector3(0, 0, 0);
    auto const vector2 = Vector3(255, 255, 2555);

    std::cout << "Vector1 ->" << vector1 << std::endl;
    std::cout << "Vector2->" << vector2 << std::endl;
}
