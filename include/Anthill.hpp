#ifndef ANTHILL_HPP
#define ANTHILL_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>
#include "Room.hpp"
#include "Ant.hpp"
#include <algorithm>
#include <set>

using namespace std;

class Anthill {
private:
    int antsNumber;
    vector<unique_ptr<Room>> rooms;
    vector<unique_ptr<Ant>> antsColony;
    vector<vector<string>> shortestPaths;

    Room* getRoomByName(const string& name);
    vector<string> computeShortestPath(const string &start, const string &end);

public:
    Anthill(int antsNumber, vector<pair<string, int>> roomsData, vector<pair<string, string>> roomConnection);
    ~Anthill();
    bool anthillResolution();
};

#endif
