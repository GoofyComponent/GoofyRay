#include <iostream>
#include "Color.hpp"
#include "Image.hpp"
#include "Ray.h"
#include "Uinputs.hpp"

using namespace std;


int main() {
    UserInputs userInputs;


    // Image
    auto aspect_ratio = 16.0 / 9.0;
    int image_width = 400;


    Color red(1, 0, 0);
    Color black;


    cout << "Red : " << red << std::endl;
    cout << "Black : " << black << std::endl;

    const int WIDTH = userInputs.AskIntInput("Enter the width of the image : ");
    const int HEIGHT = userInputs.AskIntInput("Enter the height of the image : ");


    // Camera
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(WIDTH) / HEIGHT);
    auto camera_center = Vector(0, 0, 0);

    Image image(WIDTH, HEIGHT, black);

    int centerX = WIDTH / 2;
    int centerY = HEIGHT / 2;


    int radius = min(WIDTH, HEIGHT) / 4;
    //

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            Ray r(camera_center, ray_direction);
            Color pixel_color = ray_color(r);
        }
    }

    image.WriteFile("../../../circle.png");
}
