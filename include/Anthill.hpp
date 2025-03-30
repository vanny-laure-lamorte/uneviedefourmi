#ifndef ANTHILL_HPP
#define ANTHILL_HPP

#include "InputValidator.hpp"
#include "UIRenderer.hpp" //refactor

#include "Room.hpp"
#include "Ant.hpp"
#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <limits>
#include <queue>
#include <unordered_set>
#include <map>
#include <stack>

using namespace std;

class Anthill
{
public:
    vector<Room*> anthillRoomsList;
    vector<Ant> anthillAntsList;
    Room *Sv;
    Room *Sd;
    int algorithm;

    int step = 0;
    // debug

    Anthill(const vector<Room*> &roomsList, const vector<Ant> &antsList, Room *Sv, Room *Sd, int algorithm);

    vector<Room*> getAnthillRoomsList(){
        return anthillRoomsList;
    };

    vector<Ant> getAnthillAntsList() {
        return anthillAntsList;
    };

    Room *getSv() {
        return Sv;
    };

    Room *getSd() {
        return Sd;
    };


    void moveAnts();

    /**
     * @brief Displays the current positions of the ants in the anthill
     * When the user presses Enter, the ants move to the next room
     */
    void displayAntLocationStepByStep();

    /**
     * @brief Displays all info related to the anthill choosen
     * number of rooms, number of ants, etc.
     */
    void displayAnthillInfo();

private:

    Room *findRoomByName(const string &roomName);
    void moveAntsBfs();
    vector<string> computeShortestPathBfs(const string &start, const string &end);

};

#endif // ANTHILL_HPP
