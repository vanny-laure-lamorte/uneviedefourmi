#include "DataManager.hpp"

DataManager::~DataManager(){
    for (auto room : rooms)
    {
        delete room;
    }
    rooms.clear();
};

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
Anthill DataManager::loadAnthillFromJson(int anthillNumber) {
    try {
        json anthillData = getAnthillData(anthillNumber);
        Room* vestibule = nullptr;
        Room* dormitory = nullptr;

        // cout << "Debug: Creating rooms:" << endl;
        for (const auto& [roomName, capacity] : anthillData["rooms"].items()) {
            Room* newRoom = new Room(roomName, capacity);
            rooms.push_back(newRoom);
            // cout << "Debug: Room created - Name: " << roomName << ", Capacity: " << capacity << endl;

            if (roomName == "SV")
                vestibule = newRoom;
            else if (roomName == "SD")
                dormitory = newRoom;
        }

        if (vestibule) {
            // cout << "Debug: Vestibule room (SV) created: " << vestibule->getName() << endl;
        } else {
            // cout << "Debug: Error - Vestibule room (SV) not found!" << endl;
        }

        if (dormitory) {
            // cout << "Debug: Dormitory room (SD) created: " << dormitory->getName() << endl;
        } else {
            // cout << "Debug: Error - Dormitory room (SD) not found!" << endl;
        }

        if (!vestibule || !dormitory) {
            throw runtime_error("Missing essential rooms (SV or SD).");
        }

        // cout << "Debug: Creating connections between rooms:" << endl;
        for (const auto& connection : anthillData["connections"]) {
            string from = connection["from"];
            string to = connection["to"];

            Room* fromRoom = nullptr;
            Room* toRoom = nullptr;

            for (auto& room : rooms) {
                if (room->getName() == from)
                    fromRoom = room;
                if (room->getName() == to)
                    toRoom = room;
            }

            if (fromRoom && toRoom) {
                fromRoom->addTunnels(toRoom);
                // cout << "Debug: Connection created - " << fromRoom->getName() << " <-> " << toRoom->getName() << endl;
            } else {
                // cout << "Debug: Error - Invalid connection between " << from << " and " << to << endl;
            }
        }

        vector<Ant> ants;
        int numberOfAnts = anthillData["ants"];
        // cout << "Debug: Creating " << numberOfAnts << " ants:" << endl;
        for (int i = 1; i <= numberOfAnts; i++) {
            ants.emplace_back(i, vestibule);
            // cout << "Debug: Ant " << i << " created, starting in room: " << vestibule->getName() << endl;
        }

        // cout << "Debug: Anthill configuration completed." << endl;
        return Anthill(rooms, ants, vestibule, dormitory, 0);
    } catch (const exception &e) {
        cerr << "Error loading the anthill: " << e.what() << endl;
        return Anthill({}, {}, nullptr, nullptr, 0);
    }
}
