#ifndef ANTHILL_HPP
#define ANTHILL_HPP
#include "Room.hpp"
#include "Ant.hpp"

using namespace std;
#include <memory>
#include <set>
#include <queue>
#include <vector>

class Anthill
{
private:
    int antsNumber;
    vector<unique_ptr<Room>> rooms;
    vector<unique_ptr<Ant>> antsColony;
    vector<vector<string>> shortestPaths;

    /**
     * Function used for the creation of connections between rooms
     *   @brief Get a room by its name
     *   @param roomA The first room
     *   @return Room* The room found
     */
    Room *getRoomByName(const string &name);

    /**
     * Function used to compute the shortest path between two rooms
     *  @brief Compute the shortest path between two rooms
     *  @param start The starting room
     *  @param end The ending room
     *  @return vector<string> The shortest path
     */
    vector<string> computeShortestPathBfs(const string &start, const string &end);

public:
    /**
     * Constructor
     * @param antsNumber The number of ants
     * @param roomsData The data of the rooms
     * @param roomConnection The connections between rooms
     */
    Anthill(int antsNumber, vector<pair<string, int>> roomsData, vector<pair<string, string>> roomConnection);
    ~Anthill();

    /**
     * Function used to resolve the anthill
     * @brief Resolve the anthill
     * @return bool True if all ants have arrived, false otherwise
     */    
    bool anthillResolution();
};

#endif