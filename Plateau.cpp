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

string Plateau::jetonsProgresToString(JetonsProgres jeton) const {
    switch (jeton) {
        case JetonsProgres::Agriculture: return "Agriculture";
        case JetonsProgres::Architecture: return "Architecture";
        case JetonsProgres::Economie: return "Economie";
        case JetonsProgres::Loi: return "Loi";
        case JetonsProgres::Maconnerie: return "Maconnerie";
        case JetonsProgres::Mathematiques: return "Mathematiques";
        case JetonsProgres::Philosophie: return "Philosophie";
        case JetonsProgres::Strategie: return "Strategie";
        case JetonsProgres::Theologie: return "Theologie";
        case JetonsProgres::Urbanisme: return "Urbanisme";
        default: return "Unknown";
    }
}

void Plateau::retirerJetonProgres(int index) {
    if (index >= 0 && index < jetonsProgresPlateau.size()) {
        jetonsProgresPlateau.erase(jetonsProgresPlateau.begin() + index);
    } else {
        cout << "Index invalide" << endl;
    }
}
