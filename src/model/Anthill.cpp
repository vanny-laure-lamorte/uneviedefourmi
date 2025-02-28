#include "Anthill.hpp"

#include "Anthill.hpp"

Anthill::Anthill(const vector<Room> &roomsList, const vector<Ant> &antsList, 
                 const Room *Sv, const Room *Sd, int step)
    : anthillRoomsList(roomsList), anthillAntsList(antsList), step(step) {
    
    // Assign the start and destination rooms
    this->Sv = findRoomByName(Sv->name);
    this->Sd = findRoomByName(Sd->name);
    displayAnthillInfo();
    displayAntLocationStepByStep();
}

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

// void Anthill::displayAnthillInfo() {

//     mainMenu.displayRectangleWithTitle(" ANTHILL INFORMATION ");

//     cout << ">Rooms Information " << endl;
//     for (auto& room : rooms) {
//         cout << "Room: " << room.getName() 
//              << ", Capacity: " << (room.getCapacity() == -1 ? "Unlimited" : to_string(room.getCapacity())) 
//              << endl;
//     }

//     cout << "\n>Start Room: " << Sv->getName() << endl;
//     cout << ">End Room: " << Sd->getName() << endl;

//     cout << "\n>Ants Information " << endl;
//     for (auto& ant : ants) {
//         cout << "Ant " << ant.getId() << ", Start Room: " << ant.getStartRoom()->getName() << endl;
//     }

//     cout << "\n>Connections Information: " << endl;
//     for (auto& room : rooms) {
//         for (auto& tunnel : room.getTunnels()) {
//             cout << "Room: " << room.getName() 
//                  << " is connected to: " << tunnel->getName() << endl;
//         }
//     }
// }

// Room* Anthill:: findRoomByName(const string& roomName) {
//     for (auto& room : rooms) {
//         if (room.name == roomName) {
//             return &room;
//         }
//     }
//     return nullptr;
// }

// void Anthill::moveAnts() {
//     for (auto& ant : ants) {
//         for (auto& tunnel : ant.currentRoom->tunnels) {
//             if (canMoveToRoom(tunnel)) {
//                 ant.moveAntToNewLocation(tunnel);
//                 cout << "Ant " << ant.id << " moved to room " << ant.currentRoom->name << endl;
//             }
//         }
//     }
// }

bool Anthill::canMoveToRoom(Room* room) {
    if (room->capacity == -1 || getAntsInRoom(room) < room->capacity) {
        return true; 
    }
    return false; 
}

// int Anthill::getAntsInRoom(Room* room) {
//     int count = 0;
//     for (auto& ant : ants) {
//         if (ant.currentRoom == room) {
//             count++;
//         }
//     }
//     return count;
// }

// void Anthill::displayAntLocationStepByStep() {

//     int step = 1;

//     while (true) {
//         mainMenu.displayRectangleWithTitleAndVariable("ANT MOVEMENT STEP ", step);
//         for (auto& ant : ants) {
//             cout << "Ant " << ant.getId() << " is in room " << ant.getStartRoom()->getName() << endl;
//         }

//         cout << "\n>Press Enter to move ants to the next step ";
//         cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

//         bool allAtEnd = true; 
//         for (auto& ant : ants) {
//             bool moved = false;
//             for (auto& tunnel : ant.getStartRoom()->getTunnels()) {
//                 if (canMoveToRoom(tunnel)) {
//                     ant.moveAntToNewLocation(tunnel);  
//                     moved = true;
//                     break;
//                 }
//             }

//             if (moved) {
//                 cout << "Ant " << ant.getId() << ">moved to next room " << ant.getStartRoom()->getName() << endl;
//             } else {
//                 cout << "Ant " << ant.getId() << "> Cannot move (no available tunnels or capacity full).\n";
//                 allAtEnd = false;  
//             }
//         }
//         step++;

//         if (allAtEnd) {
//             cout << "\nAll ants have reached the end room!" << endl;
//             break;  
//         }
//     }
// }

