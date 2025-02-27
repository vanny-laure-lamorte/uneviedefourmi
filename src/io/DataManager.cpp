#include "DataManager.hpp"

json DataManager::getAnthillData(int anthillNumber) {
    
    ifstream file(filePath);  
    if (!file.is_open()) {
        cerr << "Error opening the JSON file.\n";
        return json();  
    }

    json data;
    file >> data;

    for (const auto& anthill : data) {
        if (anthill["anthill"] == anthillNumber) {
            return anthill;  
        }
    }
    return data;
}

