#ifndef DATAMANAGER_HPP
#define DATAMANAGER_HPP

#include "Anthill.hpp"

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include <iostream>
using namespace std;

#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
using filesystem::current_path;

class DataManager {

public:

    ~DataManager();

    Anthill loadAnthillFromJson(int anthillNumber);

    vector<Room*> rooms;

private:
    /**
     * @brief Retrieve JSON data based on the anthill number
     * @param int anthillNumber
     * @return json anthillData
     */
    json getAnthillData(int anthillNumber);

    /**
     * @brief Scan files in the json folder
     * @return vector<filesystem::path> files
     */
    vector<filesystem::path> scanFilesInJson();
};

#endif // DATAMANAGER_HPP
