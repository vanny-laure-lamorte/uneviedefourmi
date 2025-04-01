#include <iostream>
#include "DataManager.hpp"

int main() {
    try {
        std::cout << "=== Fourmilière Simulator ===" << std::endl;

        int anthillNumber;
        std::cout << "Entrez le numéro de la fourmilière à charger : ";
        std::cin >> anthillNumber;
        std::cin.ignore(); // pour consommer le retour à la ligne

        // Chargement de la fourmilière via le DataManager
        Anthill anthill = DataManager::loadAnthillFromJson(anthillNumber);

        // Vérification de validité
        if (!anthill.isValid()) {
            std::cerr << "[ERREUR] La fourmilière chargée est invalide (SV ou SD manquant, ou vide)." << std::endl;
            return 1;
        }

        // Affichage des infos
        anthill.displayAnthillInfo();

        // Déplacement pas à pas des fourmis
        anthill.displayAntLocationStepByStep();

    } catch (const std::exception& e) {
        std::cerr << "[EXCEPTION] Une erreur est survenue : " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
