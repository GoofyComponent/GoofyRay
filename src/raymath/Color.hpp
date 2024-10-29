#pragma once

#include <iostream>

/** 
 * @class Color
 * @brief Initialize a color with 3 components : Red, Green and Blue
**/
class  Color
{
private:
  float r = 0;
  float b = 0;
  float g = 0;
public:
  /**
   * @brief Create a black color
   */
  Color();
  /**
   * @brief Create a color with the given components
   * @param iR : red component
   * @param iG : green component
   * @param iB : blue component
   */
  Color(float r, float g, float b);
  /** 
   * @brief Destructor of the color
   * @details Used to free the memory allocated for the color
   */
  ~ Color();

  float R();
  float G();
  float B();

  /**
   * @brief Overloads the + operator to add two colors.
   * 
   * This function adds two colors by summing their respective components.
   * 
   * @param other The color to add.
   * @return The resulting color from adding the two colors.
   * 
   * Example:
   * @code
   * Color c1(100, 150, 200);
   * Color c2(50, 50, 50);
   * Color result = c1 + c2; // result will have the values (150, 200, 250)
   * @endcode
   */
  Color operator+(Color const& col);

  /**
   * @brief Overloads the = operator to assign a color to another.
   * 
   * This function assigns the components of a color to another color.
   * 
   * @param col The color to assign.
   * @return Color& A reference to the assigned color.
   * 
   * Example:
   * @code
   * Color c1(100, 150, 200);
   * Color c2;
   * c2 = c1; // c2 will have the values (100, 150, 200)
   * @endcode
   */
  Color& operator=(Color const& col);


  Color operator*(double scalar) const;  // Nouvelle surcharge


  /**
   * @brief Overriding the output stream operator.
   * 
   * This function outputs the color components (r, g, b) of a Color object
   * to an output stream.
   * 
   * @param _stream The output stream.
   * @param col The Color object to output.
   * @return std::ostream& A reference to the output stream.
   */
  friend std::ostream & operator<<(std::ostream & _stream, Color const & col);
};