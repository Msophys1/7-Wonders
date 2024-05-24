#ifndef INC_7_WONDERS_PLATEAU_H
#define INC_7_WONDERS_PLATEAU_H

#include <vector>
#include <map>
#include "Carte.h"
#include "Joueur.h"
#include "Type.h"

class Plateau {
public:
    Plateau();
    void montrerEtatPlateau() const;
    void avancementMilitaire(Joueur& joueur, int steps);
    void collecterSymboleScientifique(Joueur& joueur, SymboleScientifiques symbole);
    void appliquerEffetJetonProgres(Joueur &joueur, JetonsProgres token);
    void offrirChoixJetonProgres(Joueur &joueur);
    void offrirChoixSymboleScientifique(Joueur &joueur);
    bool checkVictoireScientifique(const Joueur &joueur);
    bool checkVictoireMilitaire() const;
    static int validerInput(int min, int max);
    void preparerJetonsDeProgres();


private:
    void setUpPlateau();
    void initialiserVariablesDeJeu();
    void initialiserJetonsMilitaires();
    void distribuerPiecesInitiales();
    void initialiserCartesPourAge(int age);
    int militaryTrackPosition{}; // de -9 à 9
    int positionPionConflit{};
    std::vector<std::vector<Carte>> ageCardLayouts;
    std::map<SymboleScientifiques, int> scientificSymbolsCount;
    std::vector<JetonsProgres> availableJetonsProgres;

};

#endif //INC_7_WONDERS_PLATEAU_H
