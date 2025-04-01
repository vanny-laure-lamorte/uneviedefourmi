#ifndef DATAMANAGER_HPP
#define DATAMANAGER_HPP

#include "Anthill.hpp"
#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>

using json = nlohmann::json;
using filesystem::current_path;

class DataManager {
public:

static Anthill loadAnthillFromJson(int anthillNumber);
    // Room *findRoomByName(const string &roomName);

    /**
     * @brief Scan files in the json folder
     * @return vector<filesystem::path> files
     */
    static vector<filesystem::path> scanFilesInJson();

private:

    /**
     * @brief Retrieve JSON data based on the anthill number
     * @param int anthillNumber
     * @return json anthillData
    */
   static json getAnthillData(int anthillNumber);


};

#endif // DATAMANAGER_HPP
