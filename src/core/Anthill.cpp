#include "Anthill.hpp"

Anthill::Anthill(int antsNumber, vector<pair<string, int>> roomsData, vector<pair<string, string>> roomConnection, int algorithmChoice)
    : antsNumber(antsNumber), algorithmChoice(algorithmChoice)
{
    uiRenderer.displayRectangleWithTitle("ANTHILL INFORMATION");

    for (const auto &room : roomsData)
    {
        if (room.first == "SV" || room.first == "SD")
            rooms.push_back(make_unique<Room>(room.first, 99999));
        else
            rooms.push_back(make_unique<Room>(room.first, room.second));
    }
    cout << endl;

    for (const auto &connection : roomConnection)
    {
        Room *roomA = getRoomByName(connection.first);
        Room *roomB = getRoomByName(connection.second);
        if (roomA && roomB)
        {
            roomA->addConnection(roomB);
            roomB->addConnection(roomA);
        }
    }
    cout << endl;

    for (int i = 0; i < antsNumber; i++)
    {
        antsColony.push_back(make_unique<Ant>(i, "SV"));
        getRoomByName("SV")->addAnt(antsColony.back().get());
    }
    cout << endl << "> Your Anthill has been created ! :) \n";
    cin.get();
    cout<< endl << "> Press enter to continue." ;

    bool allAntsArrived = false;
    int step = 1;
    while (!allAntsArrived)
    {
        if (algorithmChoice == 1)
        {
            cin.get();
            cout << "****** Step " << step << " (BFS) ******" << endl;
            allAntsArrived = anthillResolution();
            step++;

            cout<< endl << "> Press enter to continue." ;
        }
        else if (algorithmChoice == 2)
        {

            cin.get();
            cout << "****** Step " << step << " (DFS) ******" << endl;
            allAntsArrived = anthillResolutionDfs();
            step++;
            cout<< endl << "> Press enter to continue.";
        }
        else
        {
            cout << "Invalid algorithm choice.\n";
            return;
        }
    }
}

Room *Anthill::getRoomByName(const string &name)
{
    for (auto &room : rooms)
        if (room->getName() == name)
            return room.get();
    return nullptr;
}

Anthill::~Anthill()
{
    cout << "\n Sile Anthill destroying" << endl;
}

vector<string> Anthill::computeShortestPathBfs(const string &start, const string &end)
{
    queue<vector<string>> pathQueue;
    set<string> visited;

    pathQueue.push({start});
    visited.insert(start);

    while (!pathQueue.empty())
    {
        vector<string> path = pathQueue.front();
        pathQueue.pop();

        string lastRoom = path.back();
        if (lastRoom == end)
            return path;

        Room *currentRoom = getRoomByName(lastRoom);
        if (!currentRoom)
            continue;

        for (Room *neighbor : currentRoom->getConnections())
        {
            if (visited.find(neighbor->getName()) == visited.end())
            {
                vector<string> newPath = path;
                newPath.push_back(neighbor->getName());
                pathQueue.push(newPath);
                visited.insert(neighbor->getName());
            }
        }
    }
    return {};
}


vector<string> Anthill::computeShortestPathDfs(const string &start, const string &end)
{
    stack<vector<string>> pathStack;
    set<string> visited;

    pathStack.push({start});
    visited.insert(start);

    while (!pathStack.empty())
    {
        vector<string> path = pathStack.top();
        pathStack.pop();

        string lastRoom = path.back();
        if (lastRoom == end)
            return path;

        Room *currentRoom = getRoomByName(lastRoom);
        if (!currentRoom)
            continue;

        for (Room *neighbor : currentRoom->getConnections())
        {
            if (visited.find(neighbor->getName()) == visited.end() && neighbor->getCapacity() > 0)
            {
                vector<string> newPath = path;
                newPath.push_back(neighbor->getName());
                pathStack.push(newPath);
                visited.insert(neighbor->getName());
            }
        }
    }
    return {};
}

bool Anthill::anthillResolution()
{
    bool allAntsArrived = true;

    for (auto &ant : antsColony)
    {
        allAntsArrived = false;
        vector<string> path = computeShortestPathBfs(ant->getPosition(), "SD");
        if (path.size() > 1)
        {
            Room *currentRoom = getRoomByName(path[0]);
            Room *nextRoom = getRoomByName(path[1]);
            
            if (currentRoom && nextRoom && nextRoom->getCapacity() > 0)
            {
                currentRoom->removeAnt(ant.get());
                nextRoom->addAnt(ant.get());
                ant->setPosition(nextRoom->getName());
                cout << "Ant " << ant->getId() << " moved from " << currentRoom->getName()
                     << " to " << nextRoom->getName() << endl;
                if (ant->getPosition() == "SD")
                {
                    allAntsArrived = true;
                }
            }
        }
    }
    return allAntsArrived;
}

bool Anthill::anthillResolutionDfs()
{
    bool allAntsArrived = true;

    for (auto &ant : antsColony)
    {
        allAntsArrived = false;
        vector<string> path = computeShortestPathDfs(ant->getPosition(), "SD");

        if (path.size() > 1)
        {
            Room *currentRoom = getRoomByName(path[0]);
            Room *nextRoom = getRoomByName(path[1]);

            if (currentRoom && nextRoom && nextRoom->getCapacity() > 0)
            {
                currentRoom->removeAnt(ant.get());
                nextRoom->addAnt(ant.get());
                ant->setPosition(nextRoom->getName());
                cout << "Ant " << ant->getId() << " moved from " << currentRoom->getName()
                     << " to " << nextRoom->getName() << endl;
                if (ant->getPosition() == "SD")
                {
                    allAntsArrived = true;
                }
            }
        }
    }
    return allAntsArrived;
}
