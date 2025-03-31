#include "DataManager.hpp"

vector<filesystem::path> DataManager::scanFilesInJson() {
    vector<filesystem::path> files;
    for (const auto & entry : std::filesystem::directory_iterator(std::filesystem::current_path().parent_path().string()+"\\assets\\json")) {
        files.push_back(entry.path());
    }
    return files;
}

json DataManager::getAnthillData(int anthillNumber) {
    string filePath = scanFilesInJson()[0].string();
    ifstream file(filePath);  
    if (!file.is_open()) {
        cerr << "Error opening the JSON file.\n";
        return json();  
    }

    json data;
    file >> data;

    for (const auto& anthill : data) {
        if (anthill["anthill"] == anthillNumber) {
            cout << "Matching anthill found:\n" << anthill.dump(4) << endl;
            return anthill;  
        }
    }
    return data;
}

Anthill DataManager::loadAnthillFromJson(int anthillNumber)
{
    try
    {
        json anthillData = getAnthillData(anthillNumber);
        if (anthillData.is_null())
        {
            throw std::runtime_error("Anthill data is empty or invalid.");
        }

        std::vector<Room> rooms;
        Room* vestibule = nullptr;
        Room* dortoir = nullptr;

        for (const auto& [roomName, capacity] : anthillData["rooms"].items())
        {
            Room newRoom(roomName, capacity);
            rooms.push_back(newRoom);

            if (roomName == "SV")
                vestibule = &rooms.back();
            else if (roomName == "SD")
                dortoir = &rooms.back();
        }

        if (!vestibule || !dortoir)
        {
            throw std::runtime_error("Missing essential rooms (SV or SD).");
        }

        for (const auto& connection : anthillData["connections"])
        {
            std::string from = connection["from"];
            std::string to = connection["to"];

            Room* fromRoom = nullptr;
            Room* toRoom = nullptr;

            for (auto& room : rooms)
            {
                if (room.getName() == from)
                    fromRoom = &room;
                if (room.getName() == to)
                    toRoom = &room;
            }

            if (fromRoom && toRoom)
            {
                fromRoom->addTunnels(toRoom);
            }
        }

        std::vector<Ant> ants;
        int numberOfAnts = anthillData["ants"];
        for (int i = 1; i <= numberOfAnts; i++)
        {
            ants.emplace_back(i, vestibule);
        }

        return Anthill(rooms, ants, vestibule, dortoir, 0);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error loading anthill: " << e.what() << std::endl;
        return Anthill({}, {}, nullptr, nullptr, 0);
    }
}


// void GraphManager::loadGraph(std::string graphPath) {
//     std::unordered_map<std::string, std::vector<std::string>> nodes;
//     std::cout << "Loading graph..." << std::endl;
//     std::ifstream file(graphPath);
//     if (!file) {
//         std::cerr << "Error: Unable to open file " << graphPath << std::endl;
//         exit(EXIT_FAILURE);
//     }
//     std::string line;
//     while (std::getline(file, line)) {
//         std::cout << line << std::endl;
//         std::stringstream ss(line);
//         std::string token;
//         ss >> token;

//         if (token[0] == 'f' && token[1] == '='){
//             int antsNumber = std::stoi(token.substr(2));
//             std::cout << "Ants number: " << antsNumber << std::endl;
//         }

//         if (token[0] == 'S'){
//             std::string node;
//             ss >> node;
//             std::cout << "Start node: " << node << std::endl;
            
//         }
//     }
// }
