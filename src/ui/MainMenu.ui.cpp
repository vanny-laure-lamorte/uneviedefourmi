#include "MainMenu.ui.hpp"

void MainMenu::mainMenu()
{
    clearScreen();
    displayWelcomeMessage();

    do
    {
        anthillMenuChoiceUser = displayAnthillMenu();
        handleAnthillChoice(anthillMenuChoiceUser);

        if (anthillMenuChoiceUser != 6){
            int algorithmChoice = displayMenuChooseAlgorithm();
            handleAlgorithmChoice(algorithmChoice);
        }

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
         << "> Press Enter to continue";

    cin.get();
    clearScreen();
}

int MainMenu::displayAnthillMenu()
{
    clearScreen();
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

int MainMenu::displayMenuChooseAlgorithm()
{
        int algorithmMenuChoiceUser; 
        do {
            cout << "\n"
            << "       * * * * * * * * * * * * * * * * * * * * * * *\n"
            << "       *                                            *\n"
            << "       *           CHOOSE A AN ALGORITHM            *\n"
            << "       *                                            *\n"
            << "       *   (1) BFS - Breadth-First Search           *\n"
            << "       *   (2) DFS - Depth-FirstSearch              *\n"
            << "       *                                            *\n"
            << "       *   (3) Previous                             *\n"
            << "       *   (4) Quit                                 *\n"
            << "       *                                            *\n"
            << "       * * * * * * * * * * * * * * * * * * * * * * *\n\n"
            << "> Select an option : ";
            cin >> algorithmMenuChoiceUser;
        } while (!inputValidator.isValidDigit(algorithmMenuChoiceUser, 4));

    return algorithmMenuChoiceUser;
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

void MainMenu::displayRectangleWithTitleAndVariable(string text, int chiffre)
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

void MainMenu::handleAnthillChoice(int anthillChoiceUser)
{
    DataManager dataManager;
    clearScreen();
    switch (anthillChoiceUser)
    {
    case 0:
        dataManager.getAnthillData(0);
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
    case 6:
        break;
    default:
        cout << "Invalid Menu choice. Try again." << endl;
        break;
    }
};

void MainMenu::handleAlgorithmChoice(int algorithmChoiceUser)
{
    clearScreen();

    vector<string> menuListTitle = {
        "BFS - Breadth-First Search",
        "DFS - Depth-First Search",        
        "PREVIOUS",
        "QUIT"};

    if (algorithmChoiceUser >= 1 && algorithmChoiceUser <= menuListTitle.size()-2)
    {
        displayRectangleWithTitle(menuListTitle[algorithmChoiceUser -1]);
    }

    switch (algorithmChoiceUser)
    {
    case 1:
        
    case 2:
        break;
    case 3:
        break;
    case 4:
        anthillMenuChoiceUser=6;
        break;

    default:
        cout << "Invalid Menu choice. Try again." << endl;
        break;
    }
};
