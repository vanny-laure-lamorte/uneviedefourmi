#include "UIRenderer.hpp"

void UIRenderer::displayRectangleWithTitle(string text)
{
    int textLength = text.length();
    int rectangleWidth = textLength + 4;
    cout << endl
         << string(rectangleWidth, '*') << endl;
    cout << "* " << text << " *" << endl;
    cout << string(rectangleWidth, '*') << endl;
    cout << endl;
}

void UIRenderer::displayRectangleWithTitleAndVariable(string text, int chiffre)
{
    string textWithChiffre = text + " " + to_string(chiffre); 
    
    int textLength = textWithChiffre.length();
    int rectangleWidth = textLength + 4; 
    cout << endl
         << string(rectangleWidth, '*') << endl;
    cout << "* " << textWithChiffre << " *" << endl;
    cout << string(rectangleWidth, '*') << endl;
    cout << endl;
}