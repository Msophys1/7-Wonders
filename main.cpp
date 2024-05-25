#include <iostream>
#include "GameManager.h"

int main() {
    try {
        Merveille m1 = Merveille("Merveille 1", Types::Merveille, {}, 0, 0, 5, true);
        cout<<m1<<endl;

        // Initialiser les joueurs
        Joueur joueur1("Joueur 1");
        Joueur joueur2("Joueur 2");

        // Initialiser le gestionnaire de jeu
        GameManager gameManager(joueur1, joueur2);

        // Création et ajout des merveilles au jeu
        gameManager.ajouterMerveille(Merveille("Merveille 1", Types::Merveille, {}, 0, 0, 5, true));
        gameManager.ajouterMerveille(Merveille("Merveille 2", Types::Merveille, {}, 0, 0, 5, true));
        gameManager.ajouterMerveille(Merveille("Merveille 3", Types::Merveille, {}, 0, 0, 5, true));
        gameManager.ajouterMerveille(Merveille("Merveille 4", Types::Merveille, {}, 0, 0, 5, true));
        gameManager.ajouterMerveille(Merveille("Merveille 5", Types::Merveille, {}, 0, 0, 5, true));
        gameManager.ajouterMerveille(Merveille("Merveille 6", Types::Merveille, {}, 0, 0, 5, true));
        gameManager.ajouterMerveille(Merveille("Merveille 7", Types::Merveille, {}, 0, 0, 5, true));
        gameManager.ajouterMerveille(Merveille("Merveille 8", Types::Merveille, {}, 0, 0, 5, true));
        gameManager.ajouterMerveille(Merveille("Merveille 9", Types::Merveille, {}, 0, 0, 5, true));
        gameManager.ajouterMerveille(Merveille("Merveille 10", Types::Merveille, {}, 0, 0, 5, true));

        // Distribuer les merveilles
        gameManager.choisirMerveilles();


    } catch (const GameException& e) {
        cerr << "Erreur: " << e.getInfo() << endl;
    }

    return 0;
}
