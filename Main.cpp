#include "MainMenu.ui.hpp"
#include "GraphManager.hpp"

#include "Anthill.hpp"
#include"DataManager.hpp"

#include <iostream>
using namespace std;

DataManager dataManager;
MainMenu mainMenu;


int main()
{
    GraphManager graphManager;
    graphManager.getProjectRootPath();
    graphManager.setCurrentPathForAssets();
    std::vector<std::filesystem::path> files = graphManager.getFilesInGraph();

    for (const auto & file : files) {
        std::cout << file << std::endl;
    }
    graphManager.loadGraph(files[0].string());
    return EXIT_SUCCESS;
}
