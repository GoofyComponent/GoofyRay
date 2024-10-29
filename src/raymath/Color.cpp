#include <iostream>
#include "Color.hpp"


Color:: Color() : r(0), b(0), g(0)
{  
}


Color:: Color(float iR, float iG, float iB) : r(iR), g(iG), b(iB)
{  
}

Color::~ Color()
{
}

float Color::R()
{
  return r;
}

float Color::G()
{
  return g;
}

float Color::B()
{
  return b;
}

Color Color::operator+(Color const& col) {
  Color c;
  c.r = fmax(fmin(r + col.r, 1), 0);
  c.g = fmax(fmin(g + col.g, 1), 0);
  c.b = fmax(fmin(b + col.b, 1), 0);
  return c;
}

Color Color::operator*(float scalar) const {
    return Color(std::clamp(r * scalar, 0.0f, 1.0f), std::clamp(g * scalar, 0.0f, 1.0f), std::clamp(b * scalar, 0.0f, 1.0f));
}

Color& Color::operator=(Color const& col) {
  r = col.r;
  g = col.g;
  b = col.b;
  return *this;
}

std::ostream & operator<<(std::ostream & _stream, Color const & col) {  
  return _stream << "(" << col.r << "," << col.g << "," << col.b << ")";
}