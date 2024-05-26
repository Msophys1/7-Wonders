#include "Joueur.h"

ostream& operator<<(ostream& f, const Joueur& joueur) {
    f << "Batiments du joueur " << joueur.getNom() << ":" << endl;
    for (const Batiment& batiment : joueur.getBatiment()) {
        f << batiment << endl;
    }

    /*
    f << "Guildes du joueur " << joueur.getNom() << ":" << endl;
    for (const Guilde& guilde : joueur.getGuildes()) {
        f << guilde << endl;
    }
     */


    f << "Merveilles du joueur " << joueur.getNom() << ":" << endl;
    for (const Merveille& merveille : joueur.getMerveilles()) {
        f << merveille << endl;
    }

    return f;
}

vector<Ressources> Joueur::getAllRessources() const {
    vector<Ressources> result;
    for (size_t i = 0; i < batiments.size(); i++) {
        const list<Ressources>& production = batiments[i].getProduction();
        for (list<Ressources>::const_iterator it = production.begin(); it != production.end(); ++it) {
            result.push_back(*it);
        }
    }
    return result;
}

void Joueur::construireBatiment(const Batiment& bat){
    unsigned int coutArgent = bat.getCoutArgent();
    if(pieces < coutArgent)
    {
        cout << "Vous n'avez pas assez de pièce pour construire ce batiment"<<endl;
        return;
    }

    const list<Ressources>& coutRessourcesBatiment = bat.getCoutRessource();
    vector<Ressources> ressourcesJoueur = getAllRessources();
    // Parcourir les ressources requises par le bâtiment
    for (const Ressources& ressource : coutRessourcesBatiment) {
        // Check si le joueur possede la ressource nécessaire
        auto it = find(ressourcesJoueur.begin(), ressourcesJoueur.end(), ressource);
        if (it != ressourcesJoueur.end()) {
            // La ressource est trouvée, on la supprime du vecteur des ressources du joueur (pour prendre en compte les doublons)
            ressourcesJoueur.erase(it);
        } else {
            // La ressource n'est pas trouvée
            cout << "Vous n'avez pas assez de ressources pour construire ce bâtiment" << endl;
            return;
        }
    }
    pieces -= coutArgent;
    ajouterBatiment(bat);
}
