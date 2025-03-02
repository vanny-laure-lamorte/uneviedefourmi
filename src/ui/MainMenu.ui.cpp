#include "MainMenu.ui.hpp"

void MainMenu::mainMenu()
{
    UIRenderer::clearScreen();
    displayWelcomeMessage();

    do
    {
        anthillMenuChoiceUser = displayAnthillMenu();        
        if (anthillMenuChoiceUser != 6){
            algorithmChoiceUser = displayMenuChooseAlgorithm();
            handleAlgorithmChoice(anthillMenuChoiceUser, algorithmChoiceUser);
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
    UIRenderer::clearScreen();
}

int MainMenu::displayAnthillMenu()
{
    UIRenderer::clearScreen();
    int anthillMenuChoiceUser;
    do
    {
        cin.clear();

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
    
    UIRenderer::clearScreen();
    
    do {
            cin.clear();
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
        
        vector<string> menuListTitle = {
            "BFS - Breadth-First Search",
            "DFS - Depth-First Search",        
            "PREVIOUS",
            "QUIT"};
            UIRenderer::displayRectangleWithTitle(menuListTitle[algorithmMenuChoiceUser -1]);

    return algorithmMenuChoiceUser;
}

void MainMenu::handleAlgorithmChoice( int anthillMenuChoiceUser, int algorithmChoiceUser)
{
    UIRenderer::clearScreen();
    anthillMenuChoiceUser=0;

    if (algorithmChoiceUser == 4){
        exit(0);
        // anthillMenuChoiceUser=6; // debug
    }
    else if (algorithmChoiceUser != 3){
        Anthill anthillCreation = dataManager.loadAnthillFromJson(anthillMenuChoiceUser);      
    
        UIRenderer::clearScreen();

        vector<string> menuListTitle = {
            "BFS - Breadth-First Search",
            "DFS - Depth-First Search",        
            "PREVIOUS",
            "QUIT"};

        if (algorithmChoiceUser >= 1 && algorithmChoiceUser <= menuListTitle.size()-2)
        {
            UIRenderer::displayRectangleWithTitle(menuListTitle[algorithmChoiceUser -1]);
        }   

        switch (algorithmChoiceUser)
        {
        case 1: 
        case 2 :
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();  
            anthillCreation.displayAntLocationStepByStep(); 
            break; 
        default:
            cout << "Invalid Menu choice. Try again." << endl;
            break;
        }
    }
     else {
        cout << "Error " << endl;
    }    
};
