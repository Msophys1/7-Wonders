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
            if(current_player == &joueur1 ) cout << "Fin du jeu. "<< joueur1.getNom() << "a remporter la partie par une victoire militaire !" << endl;
            else cout << "Fin du jeu. "<< joueur2.getNom() << "a remporter la partie par une victoire militaire !" << endl;
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
    }
    for(size_t i = 0; i < joueur2.getJetonsProgres().size(); ++i) {
        if(joueur2.getJetonsProgres()[i] == JetonsProgres::Agriculture) {
            totalPointJoueur2 += 4;
        }
        if(joueur2.getJetonsProgres()[i] == JetonsProgres::Philosophie) {
            totalPointJoueur2 += 7;
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
            if(joueur1.getBatiment()[i].getType() == type_batiment::Civile) {
                totalPointCarteBleu1 += joueur1.getBatiment()[i].getPointVictoire();
            }
        }
        for(size_t i = 0; i < joueur2.getBatiment().size(); ++i) {
            if(joueur2.getBatiment()[i].getType() == type_batiment::Civile) {
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

