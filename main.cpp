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

        cout << gameManager.getJoueur1();

        // Test de la construction  d'un batiment
        Batiment chantier = Batiment(
                "Chantier", // Nom du bâtiment
                Types::Premiere, // Type du bâtiment
                {}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Bois}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment exploitation = Batiment(
                "Exploitation", // Nom du bâtiment
                Types::Premiere, // Type du bâtiment
                {}, // Liste des ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                1, // Points de victoire
                {Ressources::Bois}, // Liste des ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Joueur joueurBat("JoueurBat");
        joueurBat.construireBatiment(chantier);
        cout << joueurBat;

    } catch (const GameException& e) {
        cerr << "Erreur: " << e.getInfo() << endl;
    }

    return 0;
}
