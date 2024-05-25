#include "GameManager.h"

void GameManager::initialiserJeu() {
    selectionnerJetonsProgres();
    choisirMerveilles();
}

void GameManager::selectionnerJetonsProgres() {
    plateau.preparerJetonsDeProgres();
}

void GameManager::choisirMerveilles() {
    // Mélanger et choisir 4 merveilles aléatoires
    random_device rd;
    mt19937 g(rd());
    shuffle(merveilles.begin(), merveilles.end(), g);

    vector<Merveille> merveillesChoisies(merveilles.begin(), merveilles.begin() + 4);
    vector<Merveille> merveillesRestantes(merveilles.begin() + 4, merveilles.end());

    auto choisirEtAfficherMerveilles = [&](Joueur& joueur1, Joueur& joueur2) {
        // Afficher 4 merveilles
        cout << "Merveilles disponibles:" << endl;
        for (size_t i = 0; i < 4; ++i) {
            cout << i + 1 << ". " << merveillesChoisies[i].getNom() << endl;
        }

        // Joueur 1 choisit une merveille
        int choix;
        cout << joueur1.getNom() << ", choisissez une merveille (1-4): ";
        cin >> choix;
        while (choix < 1 || choix > 4) {
            cout << "Choix invalide. Veuillez choisir une merveille (1-4): ";
            cin >> choix;
        }
        joueur1.ajouterMerveille(merveillesChoisies[choix - 1]);
        merveillesChoisies.erase(merveillesChoisies.begin() + (choix - 1));

        // Joueur 2 choisit deux merveilles
        for (int i = 0; i < 2; ++i) {
            cout << joueur2.getNom() << ", choisissez une merveille (1-" << 4 - i << "): ";
            cin >> choix;
            while (choix < 1 || choix > 4 - i) {
                cout << "Choix invalide. Veuillez choisir une merveille (1-" << 4 - i << "): ";
                cin >> choix;
            }
            joueur2.ajouterMerveille(merveillesChoisies[choix - 1]);
            merveillesChoisies.erase(merveillesChoisies.begin() + (choix - 1));
        }

        // Attribuer la dernière merveille à joueur1
        joueur1.ajouterMerveille(merveillesChoisies[0]);
        merveillesChoisies.clear();
    };

    // Premier tour de choix de merveilles
    choisirEtAfficherMerveilles(joueur1, joueur2);

    // Deuxième tour de choix de merveilles
    merveillesChoisies.insert(merveillesChoisies.end(), merveillesRestantes.begin(), merveillesRestantes.begin() + 4);
    choisirEtAfficherMerveilles(joueur2, joueur1);
}

void GameManager::commencerPartie() {
    bool partiefini = false;
    bool victoire = false;
    Joueur* current_player = &joueur1;

    while (!partiefini){
        // Victoire militaire :
        if (plateau.checkVictoireMilitaire()) {
            if(current_player == &joueur1 ) cout << "Fin du jeu. "<< joueur1.getNom() << "a remporter la partie !" << endl;
            else cout << "Fin du jeu. "<< joueur2.getNom() << "a remporter la partie !" << endl;
            partiefini = true;
            victoire = true;
        }

        // TODO : Victoire scientifique :
        // partiefini = true;
        // victoire = true;

        // Prochain joueur
        if(current_player == &joueur1 && joueur1.getEffetRejouer()) current_player = &joueur1;
        else if(current_player == &joueur2 && joueur2.getEffetRejouer()) current_player = &joueur2;
        else if(current_player == &joueur1) current_player = &joueur2;
        else current_player = &joueur1;
    }

    // Victoire civile
    if(!victoire)
    {
        // TODO : Decompte des points et attribution de la victoire
    }
}


