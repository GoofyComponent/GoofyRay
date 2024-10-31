#include "Input.hpp"

int Input::getInt(const std::string &prompt, int defaultValue) {
    std::string input;
    std::cout << prompt;
    std::getline(std::cin, input);
    if (!input.empty()) {
        std::stringstream(input) >> defaultValue;
    }
    return defaultValue;
}

float Input::getFloat(const std::string &prompt) {
    float value;
    std::cout << prompt;
    std::cin >> value;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}

void Input::getVector3(const std::string &prompt, float &x, float &y, float &z) {
    std::cout << prompt;
    while (true) {
        std::string positionInput;
        std::getline(std::cin >> std::ws, positionInput);
        std::stringstream posStream(positionInput);
        if (posStream >> x >> y >> z) {
            break;
        } else {
            std::cout << "Veuillez entrer trois valeurs numériques (x y z) : ";
        }
    }
}

void Input::getColor(const std::string &prompt, float &r, float &g, float &b) {
    std::cout << prompt;
    while (true) {
        std::string colorInput;
        std::getline(std::cin >> std::ws, colorInput);
        std::stringstream colorStream(colorInput);
        if (colorStream >> r >> g >> b && r >= 0 && r <= 1 && g >= 0 && g <= 1 && b >= 0 && b <= 1) {
            break;
        } else {
            std::cout << "Veuillez entrer trois valeurs entre 0 et 1 pour la couleur (r g b) : ";
        }
    }
}

bool Input::promptTemplateChoice() {
    int choice;
    std::cout << "Souhaitez-vous utiliser un template d'objets ? (1: Oui, 2: Non) : ";
    while (true) {
        std::cin >> choice;
        if (choice == 1 || choice == 2) {
            break;
        } else {
            std::cout << "Veuillez entrer 1 ou 2 : ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return choice == 1;
}
