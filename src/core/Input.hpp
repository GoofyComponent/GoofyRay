#ifndef INPUT_HPP
#define INPUT_HPP

#include <iostream>
#include <string>
#include <sstream>

class Input {
public:
    static int getInt(const std::string &prompt, int defaultValue);
    static float getFloat(const std::string &prompt);
    static void getVector3(const std::string &prompt, float &x, float &y, float &z);
    static void getColor(const std::string &prompt, float &r, float &g, float &b);
    static bool promptTemplateChoice();
};

#endif
