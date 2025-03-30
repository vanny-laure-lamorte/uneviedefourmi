#include "Ant.hpp"

void Ant::moveAntToNewLocation() {
    // Get available tunnels for the current room
    vector<string> availableTunnels = currentRoom->getTunnelsName();
    cout << "Ant " << id << " is in room " << currentRoom->getName() << endl;
    cout << "Available tunnels: ";
    for (const auto& tunnel : availableTunnels) {
        cout << tunnel << " ";
    }
    cout << endl;

    if (!availableTunnels.empty()) {
        // Pick a tunnel (for simplicity, pick the first one)
        string nextRoomName = availableTunnels[0];

        // Find the corresponding Room pointer for the next room
        Room* nextRoom = nullptr;
        for (auto& room : currentRoom->tunnels) {
            if (room->getName() == nextRoomName) {
                nextRoom = room;
                break;
            }
        }

        if (nextRoom) {
            currentRoom = nextRoom;  // Move the ant to the next room
            cout << "Ant " << id << " moved to room " << nextRoom->getName() << endl;
        }
    } else {
        cout << "No available tunnels for Ant " << id << endl;
    }
}


int Ant::getId(){
    return id;
}

Room* Ant::getStartRoom(){
    return currentRoom;
}