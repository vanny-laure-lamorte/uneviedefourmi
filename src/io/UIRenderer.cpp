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
    int subtitleLength = textWithChiffre.length();
    int subtitleWidth = subtitleLength;
    cout << endl;
    cout << textWithChiffre << endl;
    cout << string(subtitleWidth, '*') << endl;
}

void UIRenderer::displaySubtitle(const string& subtitle)
{
    int subtitleLength = subtitle.length();
    int subtitleWidth = subtitleLength;
    cout << subtitle << endl;
    cout << string(subtitleWidth, '*') << endl;
}
