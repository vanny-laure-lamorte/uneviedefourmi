#ifndef DATAMANAGER_HPP
#define DATAMANAGER_HPP

#include <iostream>
using namespace std;

#include <nlohmann/json.hpp>
using json = nlohmann::json;


#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

using std::filesystem::current_path;

class DataManager {
public:

    /**
     * Retrieve JSON data based on the  
     * anthill number
     * @param int anthillNumber
     * @return json anthillData
     */
    json getAnthillData(int anthillNumber);

    /**
     * @brief Scan files in the json folder
     * @return vector<filesystem::path> files
     */
    std::vector<std::filesystem::path> scanFilesInJson();


};

#endif // DATAMANAGER_HPP
