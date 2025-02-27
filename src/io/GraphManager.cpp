#include "GraphManager.hpp"

std::filesystem::path GraphManager::getProjectRootPath() {
    std::cout << "Current path: " << std::filesystem::current_path().parent_path() << std::endl;
    return current_path();
}

void GraphManager::setCurrentPathForAssets() {
    
    std::string AssetsPath = std::filesystem::current_path().parent_path().string()+"\\assets";
    std::cout << "Assets path: " << AssetsPath << std::endl;
}

std::vector<std::filesystem::path> GraphManager::getFilesInGraph() {
    std::vector<std::filesystem::path> files;
    for (const auto & entry : std::filesystem::directory_iterator(std::filesystem::current_path().parent_path().string()+"\\assets\\graph")) {
        files.push_back(entry.path());
    }
    return files;
}

void GraphManager::loadGraph(std::string graphPath) {
    std::unordered_map<std::string, std::vector<std::string>> nodes;
    std::cout << "Loading graph..." << std::endl;
    std::ifstream file(graphPath);
    if (!file) {
        std::cerr << "Error: Unable to open file " << graphPath << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
        std::stringstream ss(line);
        std::string token;
        ss >> token;

        if (token[0] == 'f' && token[1] == '='){
            int antsNumber = std::stoi(token.substr(2));
            std::cout << "Ants number: " << antsNumber << std::endl;
        }

        if (token[0] == 'S'){
            std::string node;
            ss >> node;
            std::cout << "Start node: " << node << std::endl;
            
        }
    }
}
