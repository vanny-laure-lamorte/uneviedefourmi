#ifndef ANT_HPP
#define ANT_HPP

#include <iostream>
#include <string>

using namespace std;

class Ant {
private:
    int id;
    string position;

public:
    Ant(int id, string position);
    ~Ant();

    int getId() const { return id; }
    string getPosition() const { return position; }
    void setPosition(string newPosition);
};

#endif
