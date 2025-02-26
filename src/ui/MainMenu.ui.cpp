#include "MainMenu.ui.hpp"


void MainMenu::mainMenu()
{
    displayWelcomeMessage();

    do
    {
        anthillMenuChoiceUser = displayAnthillMenu();
        handleAnthillChoice(anthillMenuChoiceUser);

    } while (anthillMenuChoiceUser != 6);
    cout << endl
         << "Goodbye! See you soon! :) \n \n" << endl;
}

void MainMenu::displayWelcomeMessage()
{
    cout << "\n"
         << "       * * * * * * * * * * * * * * * * * * * * * * *\n"
         << "       *                                           *\n"
         << "       *                 UNE VIE DE FOURMI         *\n"
         << "       *                                           *\n"
         << "       *       By Lucas M., Thanh L, Vanny L.      *\n"
         << "       *       B2 Logiciel - 2025                  *\n"
         << "       *                                           *\n"
         << "       * * * * * * * * * * * * * * * * * * * * * * *\n\n"
         << "> Press Enter to continue.";

    cin.get();
    clearScreen();
}

int MainMenu::displayAnthillMenu()
{
    int anthillMenuChoiceUser;
    do
    {
        cout << "\n"
             << "       * * * * * * * * * * * * * * * * * * * * * * *\n"
             << "       *                                            *\n"
             << "       *            CHOOSE A ANTHILL TYPE           *\n"
             << "       *                                            *\n"
             << "       *      (0) ANTHILL 0                         *\n"
             << "       *      (1) ANTHILL 1                         *\n"
             << "       *      (2) ANTHILL 2                         *\n"
             << "       *      (3) ANTHILL 3                         *\n"
             << "       *      (4) ANTHILL 4                         *\n"
             << "       *      (5) ANTHILL 5                         *\n"
             << "       *                                            *\n"
             << "       *      (6) Quit                              *\n"
             << "       *                                            *\n"
             << "       * * * * * * * * * * * * * * * * * * * * * * * \n\n"
             << "> Select an option: ";
        cin >> anthillMenuChoiceUser;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            anthillMenuChoiceUser = -1;
        }
    } while (!inputValidator.isValidDigit(anthillMenuChoiceUser, 6));

    return anthillMenuChoiceUser;
}


void MainMenu::displayRectangleWithTitle(string text)
{
    int textLength = text.length();
    int rectangleWidth = textLength + 4;
    cout << endl
         << string(rectangleWidth, '*') << endl;
    cout << "* " << text << " *" << endl;
    cout << string(rectangleWidth, '*') << endl;
    cout << endl;
}

void MainMenu::handleAnthillChoice(int userFilterChoice)
{
    vector<string> menuListTitle = {
        "ANTHILL 0",
        "ANTHILL 1",        
        "ANTHILL 2",
        "ANTHILL 3",
        "ANTHILL 4",    
        "ANTHILL 5",
        "QUIT"};

    if (userFilterChoice >= 1 && userFilterChoice <= menuListTitle.size())
    {
        displayRectangleWithTitle(menuListTitle[userFilterChoice]);
    }
    else if (userFilterChoice != 0)
    {
        cout << "Invalid Menu choice. Try again." << endl;
        return;
    }

    switch (userFilterChoice)
    {
    case 0:
        break;    
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;

    default:
        cout << "Invalid Menu choice. Try again." << endl;
        break;
    }
};
