#include "Plateau.h"

Plateau::Plateau()
        : positionPionConflit(0),
          saccage1duJoueur1(false),
          saccage2duJoueur1(false),
          saccage3duJoueur1(false),
          saccage1duJoueur2(false),
          saccage2duJoueur2(false),
          saccage3duJoueur2(false),
          jetonsProgresPlateau() {

}

void Plateau::setJetonsPlateau() {
    // Vérifier si le vecteur jetonsProgresPlateau contient au moins 5 jetons
    if (jetonsProgresPlateau.size() < 5) {
        std::cerr << "Erreur : Pas assez de jetons Progrès sur le plateau." << std::endl;
        return;
    }

    // Utiliser un moteur de génération de nombres aléatoires basé sur le temps actuel
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    // Mélanger les jetonsProgresPlateau
    std::shuffle(jetonsProgresPlateau.begin(), jetonsProgresPlateau.end(), generator);

    // Sélectionner les 5 premiers jetonsProgres après le mélange
    std::vector<JetonsProgres> jetonsPlateau;
    for (int i = 0; i < 5; ++i) {
        jetonsPlateau.push_back(jetonsProgresPlateau[i]);
    }

    // Mettre les 5 jetons choisis dans jetonsProgresPlateau
    jetonsProgresPlateau = jetonsPlateau;
}
