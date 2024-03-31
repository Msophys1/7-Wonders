#ifndef INC_7_WONDERS_PLATEAU_H
#define INC_7_WONDERS_PLATEAU_H

#include <vector>
#include <map>
#include "Cards.h"
#include "Joueur.h"
#include "Type.h" // Inclusion du nouveau fichier Types.h

class Plateau {
public:
    Plateau();
    static int validateInput(int min, int max);
    bool checkMilitaryVictory() const;
    void displayStatePlateau() const;
    void avancementMilitaire(Joueur& joueur, int steps);
    void collecterSymboleScientifique(Joueur& joueur, SymboleScientifiques symbole);
    bool checkVictoireScientifique(const Joueur &joueur);
    void appliquerEffetJetonProgres(Joueur &joueur, JetonsProgres token);
    void offrirChoixJetonProgres(Joueur &joueur);
    void offrirChoixSymboleScientifique(Joueur &joueur);

private:
    void setUpPlateau();
    int militaryTrackPosition{}; // de -9 à 9
    int positionPionConflit{};
    std::vector<std::vector<Cards>> ageCardLayouts;
    std::map<SymboleScientifiques, int> scientificSymbolsCount;
    std::vector<JetonsProgres> availableJetonsProgres;

};

#endif //INC_7_WONDERS_PLATEAU_H
