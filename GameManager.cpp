#include "GameManager.h"

void GameManager::selectionnerJetonsProgres() {
    //plateau.preparerJetonsDeProgres();
}

void GameManager::choisirMerveilles() {
    // Mélanger et choisir 4 merveilles aléatoires pour le premier tour
    random_device rd;
    mt19937 g(rd());
    vector<int> indices(merveilles.size());
    iota(indices.begin(), indices.end(), 0); // Remplit le vecteur avec les valeurs de 0 à N-1
    shuffle(indices.begin(), indices.end(), g);

    auto choisirEtAfficherMerveilles = [&](Joueur& joueur1, Joueur& joueur2, const vector<int>& indices) {
        // Afficher les 4 merveilles disponibles
        cout << "Merveilles disponibles:" << endl;
        for (size_t i = 0; i < 4; ++i) {
            cout << i + 1 << ". " << merveilles[indices[i]].getNom() << endl;
        }

        // Joueur 1 choisit une merveille
        int choix;
        cout << joueur1.getNom() << ", choisissez une merveille (1-4): ";
        cin >> choix;
        while (choix < 1 || choix > 4) {
            cout << "Choix invalide. Veuillez choisir une merveille (1-4): ";
            cin >> choix;
        }
        joueur1.ajouterMerveille(merveilles[indices[choix - 1]]);

        // Copier les indices restants dans une liste temporaire
        vector<int> indicesTemp(indices);

        // Retirer la merveille choisie par joueur1 de la liste temporaire
        indicesTemp.erase(indicesTemp.begin() + (choix - 1));

        // Joueur 2 choisit deux merveilles
        for (int i = 0; i < 2; ++i) {
            cout << joueur2.getNom() << ", choisissez une merveille (1-" << 4 - i << "): ";
            cin >> choix;
            while (choix < 1 || choix > 4 - i) {
                cout << "Choix invalide. Veuillez choisir une merveille (1-" << 4 - i << "): ";
                cin >> choix;
            }
            joueur2.ajouterMerveille(merveilles[indicesTemp[choix - 1]]);

            // Retirer la merveille choisie par joueur2 de la liste temporaire
            indicesTemp.erase(indicesTemp.begin() + (choix - 1));
        }

        // Attribuer la dernière merveille à joueur1
        joueur1.ajouterMerveille(merveilles[indicesTemp[0]]);
    };

    // Premier tour de choix de merveilles
    choisirEtAfficherMerveilles(joueur1, joueur2, indices);

    // Copier les indices restants après le premier tour
    vector<int> indicesDeuxiemeTour(indices.begin() + 4, indices.end());

    // Mélanger à nouveau les indices pour le deuxième tour
    shuffle(indicesDeuxiemeTour.begin(), indicesDeuxiemeTour.end(), g);

    // Deuxième tour de choix de merveilles
    choisirEtAfficherMerveilles(joueur2, joueur1, indicesDeuxiemeTour);
}




int GameManager::compterDoublonsSymbolesScientifiques(const Joueur& joueur) const {
    map<SymboleScientifiques, int> occurrences;
    int doublons = 0;

    // Itérer à travers les symboles scientifiques du joueur
    for (const auto& symbole : joueur.getSymbolesScientifiques()) {
        // Incrémenter le nombre d'occurrences de chaque symbole
        occurrences[symbole]++;
    }

    // Compter les doublons (deux occurrences du même symbole)
    for (const auto& pair : occurrences) {
        if (pair.second > 1) {
            doublons += pair.second / 2;
        }
    }
    return doublons;
}

void GameManager::commencerPartie() {
    bool partiefini = false;
    bool victoire = false;
    Joueur* current_player = &joueur1;

    while (!partiefini){
        // Victoire militaire :
        /*
        if (plateau.checkVictoireMilitaire()) {
            if(current_player == &joueur1 ) cout << "Fin du jeu. "<< joueur1.getNom() << "a remporter la partie par une victoire militaire !" << endl;
            else cout << "Fin du jeu. "<< joueur2.getNom() << "a remporter la partie par une victoire militaire !" << endl;
            partiefini = true;
            victoire = true;
        }
        */

        // Victoire scientifique :
        if(compterDoublonsSymbolesScientifiques(joueur1) >= 7)
        {
            cout << "Fin du jeu. "<< joueur1.getNom() << "a remporter la partie par une victoire scientifique !" << endl;
            partiefini = true;
            victoire = true;
        }
        if(compterDoublonsSymbolesScientifiques(joueur2) >= 7)
        {
            cout << "Fin du jeu. "<< joueur2.getNom() << "a remporter la partie par une victoire scientifique !" << endl;
            partiefini = true;
            victoire = true;
        }


        // Prochain joueur
        if(current_player == &joueur1 && joueur1.getEffetRejouer()) current_player = &joueur1;
        else if(current_player == &joueur2 && joueur2.getEffetRejouer()) current_player = &joueur2;
        else if(current_player == &joueur1) current_player = &joueur2;
        else current_player = &joueur1;
    }

    // Victoire civile
    if(!victoire)
    {
        victoireCivile();
    }
}

void GameManager::victoireCivile() {
    //Decompte des points et attribution de la victoire
    unsigned int totalPointJoueur1 = 0;
    unsigned int totalPointJoueur2 = 0;

    // Points de victoire par bâtiment
    for(size_t i = 0; i < joueur1.getBatiment().size(); ++i) {
        totalPointJoueur1 += joueur1.getBatiment()[i].getPointVictoire();
    }
    for(size_t i = 0; i < joueur2.getBatiment().size(); ++i) {
        totalPointJoueur2 += joueur2.getBatiment()[i].getPointVictoire();
    }

    // Points de victoire Merveilles
    for(size_t i = 0; i < joueur1.getMerveilles().size(); ++i) {
        totalPointJoueur1 += joueur1.getMerveilles()[i].getPointVictoire();
    }
    for(size_t i = 0; i < joueur2.getMerveilles().size(); ++i) {
        totalPointJoueur2 += joueur2.getMerveilles()[i].getPointVictoire();
    }

    // Points de victoire Progres
    for(size_t i = 0; i < joueur1.getJetonsProgres().size(); ++i) {
        if(joueur1.getJetonsProgres()[i] == JetonsProgres::Agriculture) {
            totalPointJoueur1 += 4;
        }
        if(joueur1.getJetonsProgres()[i] == JetonsProgres::Philosophie) {
            totalPointJoueur1 += 7;
        }
        if(joueur1.getJetonsProgres()[i] == JetonsProgres::Mathematiques) {
            totalPointJoueur1 += 3;
            totalPointJoueur1 += joueur1.getJetonsProgres().size() - 1;
        }
    }
    for(size_t i = 0; i < joueur2.getJetonsProgres().size(); ++i) {
        if(joueur2.getJetonsProgres()[i] == JetonsProgres::Agriculture) {
            totalPointJoueur2 += 4;
        }
        if(joueur2.getJetonsProgres()[i] == JetonsProgres::Philosophie) {
            totalPointJoueur2 += 7;
        }
        if(joueur2.getJetonsProgres()[i] == JetonsProgres::Mathematiques) {
            totalPointJoueur1 += 3;
            totalPointJoueur1 += joueur2.getJetonsProgres().size() - 1;
        }
    }

    // TODO : Points de victoire militaire

    // TODO : Points de victoire guildes


    // Trésor de la cité
    totalPointJoueur1 += joueur1.getPieces() / 3;
    totalPointJoueur2 += joueur2.getPieces() / 3;

    if(totalPointJoueur1 == totalPointJoueur2)
    {
        cout << "Fin de la partie. Égalité des points. La partie se départagera en fonction des bâtiments civils." << endl;
        unsigned int totalPointCarteBleu1 = 0;
        unsigned int totalPointCarteBleu2 = 0;
        for(size_t i = 0; i < joueur1.getBatiment().size(); ++i) {
            if(joueur1.getBatiment()[i].getType() == Types::Civil) {
                totalPointCarteBleu1 += joueur1.getBatiment()[i].getPointVictoire();
            }
        }
        for(size_t i = 0; i < joueur2.getBatiment().size(); ++i) {
            if(joueur2.getBatiment()[i].getType() == Types::Civil) {
                totalPointCarteBleu1 += joueur2.getBatiment()[i].getPointVictoire();
            }
        }
        if(totalPointCarteBleu1 > totalPointCarteBleu2) cout << "Fin du jeu. "<< joueur1.getNom() << "a remporter la partie !" << endl;
        else cout << "Fin du jeu. "<< joueur2.getNom() << "a remporter la partie par une victoire Civile!" << endl;
    }
    else {
        if(totalPointJoueur1 > totalPointJoueur2) cout << "Fin du jeu. "<< joueur1.getNom() << "a remporter la partie !" << endl;
        else cout << "Fin du jeu. "<< joueur2.getNom() << "a remporter la partie par une victoire Civile !" << endl;
    }
}

