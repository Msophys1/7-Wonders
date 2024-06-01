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

        /*

         Carte my_carte1 = Carte("Stables", Types::Militaire, phase_jeu::AGE_I, {Resssources::Argile, Resssources::Argile, Resssources::Bois, Resssources::Bois, Resssources::Bois}, 3) ;
    my_carte1.setCoutResssources({Resssources::Argile, Resssources::Argile, Resssources::Bois});
    std::cout << my_carte1 << std::endl ; 

    Merveille my_wonder1 = Merveille("Le Mausolée", Types::Merveille, phase_jeu::AGE_I, {Resssources::Argile, Resssources::Bois, Resssources::Bois, Resssources::Pierre, Resssources::Papyrus}, 0, 0, 5, true);
    std::cout << my_wonder1 << std::endl;

    // std::cout << "display missing Ressources : " << std::endl ; 
    // displayRessources( my_wonder1.achetableResssources({{Resssources::Bois, Resssources::Bois, Resssources::Verre, Resssources::Papyrus, Resssources::Papyrus}})) ;
    // laisse cette ligne en commentaire j'ai pas push displayRessources encore (enfin je crois)
    
    std::cout << std::endl ; 

    Batiment my_batiment1 = Batiment("Muraille", Types::Militaire, phase_jeu::AGE_III, {Resssources::Pierre, Resssources::Pierre}, 0, 0, 0, {Resssources::Bouclier, Resssources::Bouclier}, "");
    std::cout << my_batiment1 << std::endl ;

    Batiment my_batiment2 = Batiment("Palace", Types::Civil, phase_jeu::AGE_I, {}, 0, 0, 0, {}, "Obélisque");
    Batiment my_batiment3 = Batiment("Académie", Types::Scientifique, phase_jeu::AGE_I, {}, 0, 0, 0, {Resssources::Roue}, "");

        
        */

        // Distribuer les merveilles
        gameManager.choisirMerveilles();

        cout << gameManager.getJoueur1();

        // Test de la construction  d'un batiment
        Batiment chantier = Batiment(
                "Chantier", // Nom du bâtiment
                Types::Premiere, // Type du bâtiment
                {}, // Liste des Ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                0, // Points de victoire
                {Ressources::Bois}, // Liste des Ressources produites par le bâtiment
                "" // Bâtiment chaîné (si applicable)
        );

        Batiment exploitation = Batiment(
                "Exploitation", // Nom du bâtiment
                Types::Premiere, // Type du bâtiment
                {}, // Liste des Ressources nécessaires
                0, // Coût en argent
                0, // Récompense en argent
                1, // Points de victoire
                {Ressources::Bois}, // Liste des Ressources produites par le bâtiment
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
