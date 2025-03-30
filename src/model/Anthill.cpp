#include "Anthill.hpp"

Anthill::Anthill(const vector<Room *> &roomsList, const vector<Ant> &antsList, Room *Sv, Room *Sd, int algorithm)
    : anthillRoomsList(roomsList), anthillAntsList(antsList), algorithm(algorithm)
{

    this->Sv = findRoomByName(Sv->getName());
    this->Sd = findRoomByName(Sd->getName());

    displayAnthillInfo();

    // Launch the selected algorithm
    switch (algorithm)
    {
    case 1:
        cout << "Debug: Launching BFS for Ant movement..." << endl;
        moveAntsBfs();
        break;
    case 2:
        cout << "Debug: DFS Algorithm placeholder (not implemented yet)..." << endl;
        break;
    default:
        cout << "Debug: ALGORITHM NOT CHOOSED YET" << endl;
        break;
    }
}

void Anthill::displayAnthillInfo()
{
    // Display information about the anthill (if needed)
}

Room *Anthill::findRoomByName(const string &roomName)
{
    for (auto &room : anthillRoomsList)
    {
        if (room->getName() == roomName)
        {
            return room;
        }
    }
    return nullptr;
}

void Anthill::moveAnts()
{
    // Placeholder for another movement algorithm
}

void Anthill::moveAntsBfs() {
    cout << "Debug: BFS Movement Step..." << endl;

    for (auto& ant : anthillAntsList) {
        if (ant.currentRoom == Sd) {
            cout << "Ant " << ant.getId() << " has already reached the destination." << endl;
            continue;
        }

        queue<vector<Room*>> pathQueue;
        set<Room*> visited;
        unordered_map<Room*, Room*> cameFrom; // Pour reconstruire le chemin

        pathQueue.push({ant.currentRoom});
        visited.insert(ant.currentRoom);

        Room* destination = nullptr;

        while (!pathQueue.empty()) {
            vector<Room*> path = pathQueue.front();
            pathQueue.pop();

            Room* lastRoom = path.back();
            if (lastRoom == Sd) {
                destination = lastRoom;
                break;
            }

            for (Room* neighbor : lastRoom->getConnections()) {
                if (visited.find(neighbor) == visited.end() &&
                    (neighbor->getCapacity() == -1 || neighbor->getCurrentOccupants() < neighbor->getCapacity())) {
                    
                    visited.insert(neighbor);
                    cameFrom[neighbor] = lastRoom;
                    vector<Room*> newPath = path;
                    newPath.push_back(neighbor);
                    pathQueue.push(newPath);
                }
            }
        }

        // Construire le chemin le plus court à partir de cameFrom
        vector<Room*> shortestPath;
        if (destination) {
            Room* step = destination;
            while (step != ant.currentRoom) {
                shortestPath.push_back(step);
                step = cameFrom[step];
            }
            reverse(shortestPath.begin(), shortestPath.end());
        }

        if (!shortestPath.empty()) {
            Room* nextRoom = shortestPath[0];

            // Vérification avant de déplacer la fourmi
            if (nextRoom->getCapacity() != -1 && nextRoom->getCurrentOccupants() >= nextRoom->getCapacity()) {
                cout << "Room " << nextRoom->getName() << " is full. Ant " << ant.getId() << " cannot move there." << endl;
                continue;
            }

            ant.currentRoom->removeAnt();  // Retirer la fourmi de la salle actuelle
            nextRoom->addAnt();            // Ajouter la fourmi à la nouvelle salle
            ant.currentRoom = nextRoom;    // Mettre à jour la position de la fourmi

            cout << "Ant " << ant.getId() << " moved to room " << nextRoom->getName() << endl;
        } else {
            cout << "Ant " << ant.getId() << " has no valid path to the destination." << endl;
        }
    }
}


void Anthill::displayAntLocationStepByStep()
{
    step = 1;

    while (true)
    {
        UIRenderer::displayRectangleWithTitleAndVariable("ANT MOVEMENT STEP", step);

        bool allAtEnd = true;

        for (auto &ant : anthillAntsList)
        {
            cout << "Ant " << ant.getId() << " is in room " << ant.currentRoom->getName() << endl;
            if (ant.currentRoom != Sd)
            {
                allAtEnd = false;
            }
        }

        if (allAtEnd)
        {
            cout << "> All ants have reached the destination!" << endl;
            break;
        }

        cout << "\n> Press Enter to move ants to the next step ";
        cin.get();

        if (algorithm == 1)
        {
            moveAntsBfs();
        }
        else
        {
            moveAnts();
        }

        step++;
    }
}
