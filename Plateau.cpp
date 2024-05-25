#include "GameManager.h"

void GameManager::selectionnerJetonsProgres() {
    plateau.setJetonsPlateau();
    choisirMerveilles();
}

vector<int> GameManager::generateUniqueRandomArray() {
    // Créer un vecteur avec les nombres de 0 à 9
    std::vector<int> array;
    for (int i = 0; i < 10; ++i) {
        array.push_back(i);
    }

    // Dispositif aléatoire
    std::random_device rd;
    // Générateur de nombres pseudo-aléatoires
    std::mt19937 g(rd());

    // Mélanger les éléments du vecteur
    std::shuffle(array.begin(), array.end(), g);

    return array;
}

void GameManager::choisirMerveilles() {
    vector<int> array = generateUniqueRandomArray();

    // Le joueur 1 choisit une merveille
    for(size_t i = 0; i < 4; i++) {
        cout << i + 1 << ". " << merveilles[array[i]].getNom() << endl;
    }
    int choix;
    cout << joueur1.getNom() << ", choisissez une merveille (1-4): ";
    cin >> choix;
    while (choix < 1 || choix > 4) {
        cout << "Choix invalide. Veuillez choisir une merveille (1-4): ";
        cin >> choix;
    }
    joueur1.ajouterMerveille(merveilles[array[choix - 1]]);
    array.erase(array.begin() + (choix - 1));

    // Le joueur 2 choisit une merveille parmi les trois restantes
    for(size_t i = 0; i < 3; i++) {
        cout << i + 1 << ". " << merveilles[array[i]].getNom() << endl;
    }
    cout << joueur2.getNom() << ", choisissez une merveille (1-3): ";
    cin >> choix;
    while (choix < 1 || choix > 3) {
        cout << "Choix invalide. Veuillez choisir une merveille (1-3): ";
        cin >> choix;
    }
    joueur2.ajouterMerveille(merveilles[array[choix - 1]]);
    array.erase(array.begin() + (choix - 1));

    // Le joueur 2 choisit une autre merveille parmi les deux restantes
    for(size_t i = 0; i < 2; i++) {
        cout << i + 1 << ". " << merveilles[array[i]].getNom() << endl;
    }
    cout << joueur2.getNom() << ", choisissez une merveille (1-2): ";
    cin >> choix;
    while (choix < 1 || choix > 2) {
        cout << "Choix invalide. Veuillez choisir une merveille (1-2): ";
        cin >> choix;
    }
    joueur2.ajouterMerveille(merveilles[array[choix - 1]]);
    array.erase(array.begin() + (choix - 1));

    // Joueur 1 prend la carte restante
    joueur1.ajouterMerveille(merveilles[array[0]]);


    // On recommence l'opération en inversant les roles des joueur 1 et 2
    // Le joueur 1 choisit une merveille
    for(size_t i = 0; i < 4; i++) {
        cout << i + 1 << ". " << merveilles[array[i]].getNom() << endl;
    }
    cout << joueur2.getNom() << ", choisissez une merveille (1-4): ";
    cin >> choix;
    while (choix < 1 || choix > 4) {
        cout << "Choix invalide. Veuillez choisir une merveille (1-4): ";
        cin >> choix;
    }
    joueur2.ajouterMerveille(merveilles[array[choix - 1]]);
    array.erase(array.begin() + (choix - 1));

    // Le joueur 2 choisit une merveille parmi les trois restantes
    for(size_t i = 0; i < 3; i++) {
        cout << i + 1 << ". " << merveilles[array[i]].getNom() << endl;
    }
    cout << joueur1.getNom() << ", choisissez une merveille (1-3): ";
    cin >> choix;
    while (choix < 1 || choix > 3) {
        cout << "Choix invalide. Veuillez choisir une merveille (1-3): ";
        cin >> choix;
    }
    joueur1.ajouterMerveille(merveilles[array[choix - 1]]);
    array.erase(array.begin() + (choix - 1));

    // Le joueur 1 choisit une autre merveille parmi les deux restantes
    for(size_t i = 0; i < 2; i++) {
        cout << i + 1 << ". " << merveilles[array[i]].getNom() << endl;
    }
    cout << joueur1.getNom() << ", choisissez une merveille (1-2): ";
    cin >> choix;
    while (choix < 1 || choix > 2) {
        cout << "Choix invalide. Veuillez choisir une merveille (1-2): ";
        cin >> choix;
    }
    joueur1.ajouterMerveille(merveilles[array[choix - 1]]);
    array.erase(array.begin() + (choix - 1));

    // Joueur 2 prend la carte restante
    joueur2.ajouterMerveille(merveilles[array[0]]);

    // Vérification
    cout<<joueur1;
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

    // Points de victoire militaire
    if(plateau.getSaccage1duJoueur1()) totalPointJoueur2 += 2;
    if(plateau.getSaccage2duJoueur1()) totalPointJoueur2 += 5;
    if(plateau.getSaccage3duJoueur1()) totalPointJoueur2 += 7;

    if(plateau.getSaccage1duJoueur2()) totalPointJoueur1 += 2;
    if(plateau.getSaccage2duJoueur2()) totalPointJoueur1 += 5;
    if(plateau.getSaccage3duJoueur2()) totalPointJoueur1 += 7;

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
