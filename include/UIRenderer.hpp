#ifndef UIRENDERER_HPP
#define UIRENDERER_HPP

#include "InputValidator.hpp"
#include "Room.hpp"

#include <iostream>
using namespace std;

class UIRenderer
{
public:   

    /**
     * @brief Displays a rectangle with a title inside, centered.
     * @param text The title to display inside the rectangle.
     * @param number The number to display inside the rectangle.
     */
    void static displayRectangleWithTitleAndVariable(string text, int number);
    void static displayRectangleWithTitle(string text);    

    /**
    * @brief Clears the console screen.
    */
    void static clearScreen (){ printf("\033c");}



private:
   
};

#endif // UIRENDERER_HPP
