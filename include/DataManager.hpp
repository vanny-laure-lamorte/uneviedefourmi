#ifndef DATAMANAGER_HPP
#define DATAMANAGER_HPP

#include <iostream>
using namespace std;

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include <fstream>
#include <string>
#include <vector>

class DataManager {
public:

    /**
     * Retrieve JSON data based on the  
     * anthill number
     * @param int anthillNumber
     * @return json anthillData
     */
    json getAnthillData(int anthillNumber);

    void setFilePath(const string& path) {
        filePath = path;
    };


private:

    string filePath = "../src/Json/uneviedefourmi.json";

};

#endif // DATAMANAGER_HPP
