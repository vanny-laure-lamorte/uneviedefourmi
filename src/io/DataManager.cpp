#include "DataManager.hpp"

json DataManager::getAnthillData(int anthillNumber) {

    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Error opening the JSON file: " << filePath << "\n";
        return json();
    }

    json data;
    file >> data;
    file.close();

    for (const auto& anthill : data) {
        if (anthill.contains("anthill") && anthill["anthill"] == anthillNumber) {
            return anthill;
        }
    }
    return json();
}
