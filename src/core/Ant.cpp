#include "Ant.hpp"

Ant::Ant(int id, string position) : id(id), position(position)
{
    cout << "Hello, I'm F" << id << "! I'm in " << position << "!" << endl;
}

Ant::~Ant()
{
    cout << "Ant destroyed: " << id << endl;
}

void Ant::setPosition(string newPosition)
{
    position = newPosition;
}