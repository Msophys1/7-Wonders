#include "Joueur.h"

ostream& operator<<(ostream& f, const Joueur& joueur) {
    f << "Cartes du joueur " << joueur.getNom() << ":" << std::endl;
    for (const Carte& carte : joueur.getCartes()) {
        f << carte << endl;
    }
    return f;
}
