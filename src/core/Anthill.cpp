#include "Anthill.hpp"
#include <queue>
#include <unordered_map>

Anthill::Anthill(int antsNumber, vector<pair<string, int>> roomsData, vector<pair<string, string>> roomConnection)
    : antsNumber(antsNumber)
{
    cout << "Anthill constructor" << endl;

    for (const auto &room : roomsData)
    {
        if (room.first == "Sv" || room.first == "Sd")
            rooms.push_back(make_unique<Room>(room.first, 99999));
        else
            rooms.push_back(make_unique<Room>(room.first, room.second));
    }

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

    for (int i = 0; i < antsNumber; i++)
    {
        antsColony.push_back(make_unique<Ant>(i, "Sv"));
        getRoomByName("Sv")->addAnt(antsColony.back().get());
    }

    bool allAntsArrived = false;
    int step = 0;
    while (!allAntsArrived)
    {
        cout << "****** Step " << step++ << " ******" << endl;
        allAntsArrived = anthillResolution();
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
    cout << "Anthill destructor" << endl;
}

vector<string> Anthill::computeShortestPath(const string &start, const string &end)
{
    queue<vector<string>> q;
    set<string> visited;

    q.push({start});
    visited.insert(start);

    while (!q.empty())
    {
        vector<string> path = q.front();
        q.pop();

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
                q.push(newPath);
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
        vector<string> path = computeShortestPath(ant->getPosition(), "Sd");

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
                if (ant->getPosition() == "Sd")
                {
                    allAntsArrived = true;
                }
            }
        }
    }
    return allAntsArrived;
}