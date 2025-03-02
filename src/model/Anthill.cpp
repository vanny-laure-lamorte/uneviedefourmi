#include "Anthill.hpp"

Anthill::Anthill(const vector<Room> &roomsList, const vector<Ant> &antsList, 
                 const Room *Sv, const Room *Sd, int step)
    : anthillRoomsList(roomsList), anthillAntsList(antsList), step(step) {
    
    // Assign the start and destination rooms
    this->Sv = findRoomByName(Sv->name);
    this->Sd = findRoomByName(Sd->name);

    displayAnthillInfo();
}


void Anthill::displayAnthillInfo() {

    UIRenderer::displayRectangleWithTitle("ANTHILL INFORMATION");

    cout << "Rooms Information \n"
    << "* * * * * * * * *" << endl;
    for (auto& room : anthillRoomsList) {
        cout << "> Room: " << room.getName() 
             << ", Capacity: " << (room.getCapacity() == -1 ? "Unlimited" : to_string(room.getCapacity())) 
             << endl;
    }
    cout << endl;

    cout << "starting and destination point\n"
    << "* * * * * * * * * * * * * * * *";
    cout << "\nStart Room: " << Sv->getName() << endl;
    cout << "End Room: " << Sd->getName() << endl << endl;

    cout << "Ants Information \n"
    << "* * * * * * * * *" << endl;
    for (auto& ant : anthillAntsList) {
        cout << "> Ant " << ant.getId() << ", Start Room: " << ant.getStartRoom()->getName() << endl;
    }
    cout<<endl;

    cout << "Connections Information \n"
    << "* * * * * * * * * * * *" << endl;
    for (auto& room : anthillRoomsList) {
        for (auto& tunnel : room.getTunnels()) {
            cout << "Room: " << room.getName() 
                 << " is connected to: " << tunnel->getName() << endl;
        }
    }

    cout << "\n> Press Enter to move ants to the next step :)";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin.get();

}

Room* Anthill:: findRoomByName(const string& roomName) {
    for (auto& room : anthillRoomsList) {
        if (room.name == roomName) {
            return &room;
        }
    }
    return nullptr;
}

void Anthill::moveAnts() {
    for (auto& ant : anthillAntsList) {
        for (auto& tunnel : ant.currentRoom->tunnels) {
            if (canMoveToRoom(tunnel)) {
                ant.moveAntToNewLocation(tunnel);
                cout << "Ant " << ant.id << " moved to room " << ant.currentRoom->name << endl;
            }
        }
    }
}

bool Anthill::canMoveToRoom(Room* room) {
    if (room->capacity == -1 || getAntsInRoom(room) < room->capacity) {
        return true; 
    }
    return false; 
}

int Anthill::getAntsInRoom(Room* room) {
    int count = 0;
    for (auto& ant : anthillAntsList) {
        if (ant.currentRoom == room) {
            count++;
        }
    }
    return count;
}

void Anthill::displayAntLocationStepByStep() {

    step = 1;
    UIRenderer::clearScreen();
    UIRenderer::displayRectangleWithTitleAndVariable("ANT MOVEMENT STEP", step);

    while (true) {
        for (auto& ant : anthillAntsList) {
            cout << "Ant " << ant.getId() << " is in room " << ant.getStartRoom()->getName() << endl;
        }

        cout << "\n> Press Enter to move ants to the next step ";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        bool allAtEnd = true; 
        for (auto& ant : anthillAntsList) {
            bool moved = false;
            for (auto& tunnel : ant.getStartRoom()->getTunnels()) {
                if (canMoveToRoom(tunnel)) {
                    ant.moveAntToNewLocation(tunnel);  
                    moved = true;
                    break;
                }
            }

            if (moved) {
                cout << "Ant " << ant.getId() << ">moved to next room " << ant.getStartRoom()->getName() << endl;
            } else {
                cout << "Ant " << ant.getId() << "> Cannot move (no available tunnels or capacity full).\n";
                allAtEnd = false;  
            }
        }
        step++;

        if (allAtEnd) {
            cout << "\nAll ants have reached the end room!" << endl;
            break;  
        }
    }
}

