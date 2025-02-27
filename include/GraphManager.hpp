#ifndef GRAPHMANAGER_HPP
#define GRAPHMANAGER_HPP

#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>

using std::filesystem::current_path;

class GraphManager {

    public:
    std::filesystem::path getProjectRootPath();
    void setCurrentPathForAssets();
    std::vector<std::filesystem::path> getFilesInGraph();
    void loadGraph(std::string graphPath);
};

#endif // GRAPHMANAGER_HPP