#include "Anthill.hpp"

Anthill::Anthill(const vector<Room*> &roomsList, const vector<Ant> &antsList, Room *Sv, Room *Sd, int algorithm)
    : anthillRoomsList(roomsList), anthillAntsList(antsList), algorithm(algorithm) {

        this->Sv = findRoomByName(Sv->getName());
        this->Sd = findRoomByName(Sd->getName());

        displayAnthillInfo();
}

void Anthill::displayAnthillInfo() {

    UIRenderer::displayRectangleWithTitle("ANTHILL INFORMATION");

       // Display the chosen algorithm
    UIRenderer::displaySubtitle("Algorithm choosen");

       switch (algorithm) {
           case 1:
               cout << "> BFS - Breadth-First Search" << endl;
               break;
           case 2:
               cout << "> DFS - Depth-First Search" << endl;
               break;
           default:
               cout << "> Unknown Algorithm" << endl;
               break;
       }
    cout << endl;

    UIRenderer::displaySubtitle("Rooms Information");
    for (auto& room : anthillRoomsList) {
        cout << "> Room: " << room->getName()
             << ", Capacity: " << (room->getCapacity() == -1 ? "Unlimited" : to_string(room->getCapacity()))
             << endl;
    }
    cout << endl;

    UIRenderer::displaySubtitle("Starting and destination point");
    cout << "> Start Room: " << Sv->getName() << endl;
    cout << "> End Room: " << Sd->getName() << endl << endl;

    UIRenderer::displaySubtitle("Ants Information");
    for (auto& ant : anthillAntsList) {
        cout << "> Ant " << ant.getId() << ", Start Room: " << ant.getStartRoom()->getName() << endl;
    }
    cout << endl;

    UIRenderer::displaySubtitle("Connections Information");
    for (auto& room : anthillRoomsList) {
        vector<string> tunnelNames = room->getTunnelsName();
        for (const auto& tunnelName : tunnelNames) {
            cout << "> Room: " << room->getName() << " is connected to: " << tunnelName << endl;
        }
    }
}

Room* Anthill::findRoomByName(const string& roomName) {
    for (auto& room : anthillRoomsList) {
        if (room->getName() == roomName) {
            return room;
        }
    }
    return nullptr;
}

void Anthill::moveAnts() {
    cout << "Debug: Ants are moving..." << endl;

    for (auto& ant : anthillAntsList) {
        if (ant.currentRoom != Sd) {
            vector<string> tunnelNames = ant.currentRoom->getTunnelsName();
            cout << "Ant " << ant.getId() << " is in room " << ant.currentRoom->getName() << endl;
            cout << "Debug: Available tunnels: ";
            for (const auto& tunnelName : tunnelNames) {
                cout << tunnelName << " ";
            }
            cout << endl;

            if (!tunnelNames.empty()) {
                string nextRoomName = tunnelNames[0];
                Room* nextRoom = nullptr;
                for (auto& room : anthillRoomsList) {
                    if (room->getName() == nextRoomName) {
                        nextRoom = room;
                        break;
                    }
                }

                if (nextRoom) {
                    if (nextRoom->getCapacity() != -1 && nextRoom->getCurrentOccupants() >= nextRoom->getCapacity()) {
                        cout << "Room " << nextRoom->getName() << " is full. Ant " << ant.getId() << " cannot move there." << endl;
                    } else {
                        ant.currentRoom->removeAnt();
                        ant.moveAntToNewLocation();
                        nextRoom->addAnt();

                        cout << "Ant " << ant.getId() << " moved to room " << nextRoom->getName() << endl;
                    }
                } else {
                    cout << "Debug: No valid room found for ant " << ant.getId() << endl;
                }
            }
        } else {
            cout << "Ant " << ant.getId() << " has reached the destination." << endl;
        }
    }
}


void Anthill::displayAntLocationStepByStep() {
    step = 1;

    while (true) {
        UIRenderer::displayRectangleWithTitleAndVariable("ANT MOVEMENT STEP", step);

        bool allAtEnd = true;

        for (auto& ant : anthillAntsList) {
            cout << "Ant " << ant.getId() << " is in room " << ant.currentRoom->getName() << endl;
            if (ant.currentRoom != Sd) {
                allAtEnd = false;
            }
        }

        if (allAtEnd) {
            cout << "> All ants have reached the destination!" << endl;
            break;
        }
        cout << "\n> Press Enter to move ants to the next step ";
        cin.get();

        moveAnts();

        step++;
    }
}
