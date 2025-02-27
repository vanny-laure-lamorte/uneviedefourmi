#include "MainMenu.ui.hpp"

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

    if (userFilterChoice < 0 || userFilterChoice >= menuListTitle.size() - 1) {
        cout << "Invalid Menu choice. Try again." << endl;
        return;
    }

    displayRectangleWithTitle(menuListTitle[userFilterChoice]);

    DataManager dataManager("../src/assets/anthills.json");
    json anthillData = dataManager.getAnthillData(userFilterChoice);

    if (anthillData.empty()) {
        cout << "Error: Anthill data not found!" << endl;
        return;
    }

    int antsNumber = anthillData["ants"];
    
    vector<pair<string, int>> roomsData;
    for (auto& [key, value] : anthillData["rooms"].items()) {
        roomsData.emplace_back(key, value);
    }

    vector<pair<string, string>> roomConnection;
    for (auto& conn : anthillData["connections"]) {
        if (conn.is_array() && conn.size() == 2) {
            roomConnection.emplace_back(conn[0], conn[1]);
        }
    }

    Anthill anthill(antsNumber, roomsData, roomConnection);
}


void MainMenu::mainMenu()
{
    displayWelcomeMessage();

    do
    {
        anthillMenuChoiceUser = displayAnthillMenu();
        handleAnthillChoice(anthillMenuChoiceUser);
        cin.get();

    } while (anthillMenuChoiceUser != 6);
    cout << endl
         << "Goodbye! See you soon! :) \n \n"
         << endl;
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
             << "         * * * * * * * * * * * * * * * * * * * * * *\n"
             << "        *                                           *\n"
             << "        *           CHOOSE A ANTHILL TYPE           *\n"
             << "        *                                           *\n"
             << "        *      (0) ANTHILL 0                        *\n"
             << "        *      (1) ANTHILL 1                        *\n"
             << "        *      (2) ANTHILL 2                        *\n"
             << "        *      (3) ANTHILL 3                        *\n"
             << "        *      (4) ANTHILL 4                        *\n"
             << "        *      (5) ANTHILL 5                        *\n"
             << "        *                                           *\n"
             << "        *      (6) Quit                             *\n"
             << "        *                                           *\n"
             << "         * * * * * * * * * * * * * * * * * * * * * * \n\n"
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
