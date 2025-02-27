#ifndef ANT_HPP
#define ANT_HPP

using namespace std;
#include <iostream>

class Ant {
private:
    int id;
    string position;

public:
    /**
     * Constructor
     * @param id The id of the ant
     * @param position The position of the ant
     */
    Ant(int id, string position);
    ~Ant();

    /**
     * Get the id of the ant
     * @return int The id of the ant
     */
    int getId() const { return id; }

    /**
     * Get the position of the ant
     * @return string The position of the ant
     */
    string getPosition() const { return position; }

    /**
     * Set the position of the ant
     * @param newPosition The new position of the ant
     */
    void setPosition(string newPosition);
};

#endif