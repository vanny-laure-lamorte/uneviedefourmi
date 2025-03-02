
// void GraphManager::loadGraph(string graphPath) {
//     unordered_map<string, vector<string>> nodes;
//     cout << "Loading graph..." << endl;
//     ifstream file(graphPath);
//     if (!file) {
//         cerr << "Error: Unable to open file " << graphPath << endl;
//         exit(EXIT_FAILURE);
//     }
//     string line;
//     while (getline(file, line)) {
//         cout << line << endl;
//         stringstream ss(line);
//         string token;
//         ss >> token;

//         if (token[0] == 'f' && token[1] == '='){
//             int antsNumber = stoi(token.substr(2));
//             cout << "Ants number: " << antsNumber << endl;
//         }

//         if (token[0] == 'S'){
//             string node;
//             ss >> node;
//             cout << "Start node: " << node << endl;
            
//         }
//     }
// }

// Anthill::Anthill(const vector<Room>& roomsList, const vector<Ant>& antsList,
//     const Room* Sv, const Room* Sd, int step) {

//     for (auto& roomData : anthillData["rooms"].items()) {
//         string roomName = roomData.key();
//         int capacity = (roomData.value().is_null()) ? -1 : roomData.value().get<int>();
//         rooms.push_back(Room(roomName, capacity));
//     }

//     Sv = findRoomByName("SV");
//     Sd = findRoomByName("SD");

//     int antCount = anthillData["ants"];
//     for (int i = 0; i < antCount; ++i) {
//         ants.push_back(Ant(i + 1, Sv));
//     }

//     for (auto& connection : anthillData["connections"]) {
//         Room* fromRoom = findRoomByName(connection["from"]);
//         Room* toRoom = findRoomByName(connection["to"]);
//         fromRoom->addTunnels(toRoom);
//     }
// }


/**
 * @brief Handles the user's choice from the anthill menu and performs actions.
 * @param anthillMenuChoiceUser The user's choice from the anthill menu
 * @return Anthill - The anthill object created from the user's choice
 */
// Anthill handleAnthillChoice(int anthillMenuChoiceUser);


// Anthill MainMenu::handleAnthillChoice(int anthillChoiceUser)
// {
//     DataManager dataManager;
//     UIRenderer::clearScreen();

//    Anthill anthill = dataManager.loadAnthillFromJson(anthillChoiceUser); 
   
//    return anthill;
// };

