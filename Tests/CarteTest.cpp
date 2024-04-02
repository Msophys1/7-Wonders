#include "../Game/Carte.h"
#include "../Game/Carte.cpp"
#include <iostream>


int main() {
    try {
        Carte::testerChargementDecks();
    } catch (const std::exception& e) {
        std::cerr << "Erreur lors du test: " << e.what() << std::endl;
    }
    return 0;
}