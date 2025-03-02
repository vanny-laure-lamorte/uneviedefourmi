#include "DataManager.hpp"

vector<filesystem::path> DataManager::scanFilesInJson() {
    vector<filesystem::path> files;
    for (const auto & entry : filesystem::directory_iterator(filesystem::current_path().parent_path().string()+"\\assets\\json")) {
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
            throw runtime_error("Anthill data is empty or invalid.");
        }

        vector<Room> rooms;
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
        cout << endl;

        if (!vestibule || !dortoir)
        {
            throw runtime_error("Missing essential rooms (SV or SD).");
        }

        for (const auto& connection : anthillData["connections"])
        {
            string from = connection["from"];
            string to = connection["to"];

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

        vector<Ant> ants;
        int numberOfAnts = anthillData["ants"];
        for (int i = 1; i <= numberOfAnts; i++)
        {
            ants.emplace_back(i, vestibule);
        }
        return Anthill(rooms, ants, vestibule, dortoir, 0);
    }
    catch (const exception &e)
    {
        std::cerr << "Error loading anthill: " << e.what() << std::endl;
        return Anthill({}, {}, nullptr, nullptr, 0);
    }
}
