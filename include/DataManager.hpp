#ifndef DATA_MANAGER_HPP
#define DATA_MANAGER_HPP
#include "nlohmann/json.hpp"
using json = nlohmann::json;

using namespace std;
#include <iostream>
#include <fstream>

class DataManager
{
private:
    string filePath; // File path for JSON data

public:
    /** Constructor */
    DataManager(const string& path) : filePath(path) {}

    /** Get the data of a specific anthill
     * @param int anthillNumber
     * @return json data
     */
    json getAnthillData(int anthillNumber);
};

#endif // DATA_MANAGER_HPP