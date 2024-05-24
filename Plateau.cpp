#include "Plateau.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <set>


Plateau::Plateau(){
    setUpPlateau();
}

int Plateau::validerInput(int min, int max) {
    int choix;
    // Entame une boucle qui se poursuit tant que l'entrée est invalide.
    // Une entrée est considérée comme invalide si elle ne peut pas être lue comme un entier
    // ou si elle n'est pas comprise entre 'min' et 'max'.
    while(!(std::cin >> choix) || choix < min || choix > max) {
        // Si l'entrée est invalide, affiche un message demandant à l'utilisateur de choisir un numéro valide.
        std::cout << "Choix invalide. Veuillez choisir un numéro entre " << min << " et " << max << ": ";

        // Nettoie le flux d'entrée. Ceci est nécessaire si std::cin a échoué à lire l'entrée,
        // par exemple, si l'utilisateur a entré un texte au lieu d'un nombre.
        std::cin.clear();

        // Ignore les entrées jusqu'à la fin de la ligne. Cela permet de se débarrasser de tout caractère restant
        // dans le flux d'entrée, y compris le caractère de nouvelle ligne, afin de permettre une nouvelle tentative de saisie.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    // Une fois une entrée valide obtenue, la retourne.
    return choix;
}

void Plateau::setUpPlateau() {
    // Initialisation des variables de jeu
    initialiserVariablesDeJeu();
    // Préparer les jetons de progrès
    preparerJetonsDeProgres();

    for (int age = 0; age < 3; ++age) {
        initialiserCartesPourAge(age);
    }

    // Initialisation des jetons militaires sur le plateau
    initialiserJetonsMilitaires();
    // Distribution initiale des pièces de monnaie aux joueurs
    distribuerPiecesInitiales();

}

void Plateau::initialiserVariablesDeJeu() {
    // Réinitialise la position du pion de conflit à 0, indiquant le début de la partie sans avantage militaire
    // pour aucun joueur.
    positionPionConflit = 0;
    // Réinitialise la position de la piste militaire à 0. (Cette variable semble redondante ou non utilisée
    // si elle a le même but que positionPionConflit)
    militaryTrackPosition = 0;
    // Efface le compteur des symboles scientifiques pour assurer qu'aucun symbole ne soit compté avant le
    // début de la partie.
    scientificSymbolsCount.clear();
    // Efface le compteur des jetons progrès pour assurer qu'aucun jetons ne soit compté avant le début de la partie.
    availableJetonsProgres.clear();
}

void Plateau::preparerJetonsDeProgres(){
    // Initialise la liste des jetons de progrès disponibles en y incluant un assortiment prédéfini de jetons.
    availableJetonsProgres = {
            JetonsProgres::Agriculture,
            JetonsProgres::Architecture,
            JetonsProgres::Economie,
            JetonsProgres::Loi,
            JetonsProgres::Maconnerie,
            JetonsProgres::Mathematiques,
            JetonsProgres::Philosophie,
            JetonsProgres::Strategie,
            JetonsProgres::Theologie,
            JetonsProgres::Urbanisme
    };

    // Utilise l'horloge système pour générer une graine aléatoire.
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    // Mélange aléatoirement les jetons de progrès disponibles en utilisant la graine.
    std::shuffle(availableJetonsProgres.begin(), availableJetonsProgres.end(),
                 std::default_random_engine(seed));
    // Réduit la liste des jetons de progrès à 5, choisissant ainsi aléatoirement les jetons pour la partie.
    availableJetonsProgres.resize(5);
}

void Plateau::initialiserJetonsMilitaires() {
    // TODO: Ajouter une logique pour initialiser et placer les jetons militaires sur le plateau.
}

void Plateau::distribuerPiecesInitiales() {
    // TODO : La distribution initiale des pièces de monnaie aux joueurs.
    // joueur1.ajouterPieces(7);
    // joueur2.ajouterPieces(7);
    // Note: Assurer d'avoir accès aux instances des joueurs
}

void Plateau::initialiserCartesPourAge(int age) {
    if (age < 1 || age > 3) {
        throw std::invalid_argument("Age invalide. Veuillez choisir entre 1 et 3.");
    }

    // Nombre de cartes à sélectionner pour chaque âge
    int nombreDeCartes = (age == 3) ? 20 : 23;

    // Vérifie si le vecteur a suffisamment de cartes pour être sélectionné
    if (Carte::decksParAge[age - 1].size() < nombreDeCartes) {
        throw std::runtime_error("Pas assez de cartes dans le deck pour l'âge " + std::to_string(age));
    }

    // Copie le vecteur pour permettre le mélange sans altérer l'original
    std::vector<Carte> deckCopie = Carte::decksParAge[age - 1];

    // Mélange aléatoire des cartes dans le deck copié
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(deckCopie.begin(), deckCopie.end(), g);

    // Efface le vecteur pour l'âge spécifié et sélectionne le nombre de cartes requis
    ageCardLayouts[age - 1].clear();
    ageCardLayouts[age - 1].insert(ageCardLayouts[age - 1].end(), deckCopie.begin(), deckCopie.begin() + nombreDeCartes);
}

bool Plateau::checkVictoireMilitaire() const {
    // La fonction renvoie true (vrai) si la position du pion de conflit est égale à 9 ou -9.
    // Dans le contexte du jeu, cela signifie que l'un des joueurs a poussé le pion de conflit
    // tout au bout de la piste militaire dans sa direction, indiquant une victoire militaire.
    // positionPionConflit == 9 signifie que le joueur qui avance le pion dans la direction positive
    // a atteint la fin de la piste, symbolisant une victoire militaire sur son adversaire.
    // positionPionConflit == -9 indique l'inverse, où le joueur poussant le pion dans la direction négative
    // a obtenu une victoire militaire.
    // Si aucune de ces conditions n'est remplie, la fonction renvoie false (faux), indiquant qu'aucune victoire
    // militaire n'a encore été atteinte.
    return positionPionConflit == 9 || positionPionConflit == -9;
}

void Plateau::montrerEtatPlateau() const {
    // Affiche la position actuelle du pion de conflit sur la piste.
    // La position du pion de conflit indique le progrès des joueurs vers une victoire ou une défaite militaire.
    std::cout << "Position du pion de conflit: " << positionPionConflit << std::endl;

    // Commence l'affichage des jetons de progrès disponibles.
    std::cout << "Jetons de progres disponibles: ";
    // Parcourt et affiche chaque jeton de progrès disponible sur le plateau.
    for (auto& token : availableJetonsProgres) {
        // Convertit le type de jeton (enum) en entier pour l'affichage et l'ajoute à la sortie standard.
        std::cout << static_cast<int>(token) << " ";
    }
    // Termine la ligne pour séparer proprement les sections de l'affichage.
    std::cout << std::endl;

    // Commence l'affichage des symboles scientifiques collectés.
    std::cout << "Symboles scientifiques collectes: ";
    // Parcourt la collection de symboles scientifiques (une map des symboles vers leur compte).
    for (auto& symbole : scientificSymbolsCount) {
        // Affiche le type de symbole scientifique (converti en entier) et son nombre associé.
        // Format : [type de symbole] x [nombre]
        std::cout << static_cast<int>(symbole.first) << " x " << symbole.second << "; ";
    }
    // Termine la ligne pour une meilleure lisibilité de l'affichage.
    std::cout << std::endl;
}

void Plateau::avancementMilitaire(Joueur& joueur, int steps) {
    // Ajoute le nombre de 'steps' à la position actuelle du pion de conflit.
    // 'steps' peut être positif (avancer vers la victoire militaire du joueur qui agit)
    // ou négatif (reculer suite à des actions de l'adversaire ou des effets de cartes).
    positionPionConflit += steps;

    // Assure que la position du pion de conflit ne dépasse pas les limites de la piste.
    // La piste militaire est représentée par une plage de valeurs allant de -9 à 9,
    // où -9 représente une victoire militaire pour l'adversaire, et 9 une victoire pour le joueur actuel.
    if (positionPionConflit > 9) positionPionConflit = 9; // Limite supérieure à 9
    else if (positionPionConflit < -9) positionPionConflit = -9; // Limite inférieure à -9

    // Après avoir ajusté la position du pion, vérifie si cette nouvelle position
    // conduit à une victoire militaire pour l'un des joueurs.
    if (checkVictoireMilitaire()) {
        // Si 'checkVictoireMilitaire' retourne vrai, cela signifie que le pion de conflit
        // a atteint l'une des extrémités de la piste, indiquant une victoire militaire.
        // Annonce la victoire militaire pour le joueur qui a causé le dernier mouvement.
        std::cout << "Victoire militaire pour " << joueur.getNom() << "!\n";
    }
}

void Plateau::offrirChoixJetonProgres(Joueur& joueur) {
    // Vérifie si la liste des jetons de progrès disponibles est vide.
    if (availableJetonsProgres.empty()) {
        // Si la liste est vide, affiche un message indiquant qu'aucun jeton de progrès n'est disponible.
        std::cout << "Aucun jeton de progrès disponible." << std::endl;
        return; // Sort de la méthode sans offrir de choix au joueur.
    }

    // Affiche la liste des jetons de progrès disponibles.
    std::cout << "Jetons de progrès disponibles : " << std::endl;
    for (int i = 0; i < availableJetonsProgres.size(); ++i) {
        // Pour chaque jeton disponible, affiche son index (en commençant par 1) et son type.
        // Le type de jeton est converti en entier pour l'affichage.
        std::cout << i + 1 << ": " << static_cast<int>(availableJetonsProgres[i]) << std::endl;
    }

    // Demande au joueur de choisir un jeton en validant l'entrée pour s'assurer qu'elle est dans la plage correcte.
    int choix = validerInput(1, availableJetonsProgres.size());
    // Sélectionne le jeton de progrès choisi en utilisant l'index.
    JetonsProgres jetonChoisi = availableJetonsProgres[choix - 1];

    // Applique l'effet du jeton de progrès choisi au joueur.
    appliquerEffetJetonProgres(joueur, jetonChoisi);

    // Affiche un message confirmant le choix du joueur et le type de jeton de progrès choisi.
    std::cout << "Le joueur " << joueur.getNom() << " a choisi le jeton de progrès " << static_cast<int>
    (jetonChoisi) << "." << std::endl;
}

void Plateau::appliquerEffetJetonProgres(Joueur& joueur, JetonsProgres token) {
    // Utilise une instruction switch pour déterminer l'effet du jeton de progrès spécifique.
    switch (token) {
        case JetonsProgres::Agriculture:
            // Ajoute 6 pièces et 4 points de victoire au joueur.
            joueur.ajouterPieces(6);
            joueur.ajouterPointsDeVictoire(4);
            break;
        case JetonsProgres::Architecture:
            // Réduit le coût de construction pour le joueur de 2 unités.
            joueur.reduireCoutConstruction(2);
            break;
        case JetonsProgres::Economie:
            // Active un effet économique spécifique pour le joueur.
            joueur.activerEffetEconomie();
            break;
        case JetonsProgres::Loi:
            // Ajoute un symbole scientifique au joueur.
            offrirChoixSymboleScientifique(joueur);
            break;
        case JetonsProgres::Maconnerie:
            // Réduit le coût des cartes bleues (liées généralement à des points de victoire) pour le joueur.
            joueur.reduireCoutCartesBleues(2);
            break;
        case JetonsProgres::Mathematiques:
            // Ajoute des points de victoire supplémentaires pour chaque jeton de progrès que le joueur possède.
            joueur.ajouterPointsDeVictoirePourJetons(3);
            break;
        case JetonsProgres::Philosophie:
            // Ajoute directement 7 points de victoire au joueur.
            joueur.ajouterPointsDeVictoireDirect(7);
            break;
        case JetonsProgres::Strategie:
            // Augmente la puissance militaire du joueur de 1 unité.
            joueur.augmenterPuissanceMilitaire(1);
            break;
        case JetonsProgres::Theologie:
            // Active un effet permettant au joueur de rejouer.
            joueur.activerEffetRejouer();
            break;
        case JetonsProgres::Urbanisme:
            // Ajoute 6 pièces au joueur et active un effet de chainage, permettant des actions supplémentaires.
            joueur.ajouterPieces(6);
            joueur.activerEffetChainage(4);
            break;
        default:
            // Si le jeton de progrès n'est pas reconnu, affiche un message d'erreur.
            std::cout << "Effet de jeton non reconnu." << std::endl;
            return; // Sort du switch sans appliquer d'effet.
    }
}

void Plateau::collecterSymboleScientifique(Joueur& joueur, SymboleScientifiques symbole) {
    // Incrémente le compteur du symbole scientifique spécifié pour le joueur.
    // Cette ligne ajoute 1 au nombre de fois que le joueur a collecté ce symbole spécifique.
    joueur.SymboleScientifiques[symbole]++;

    // Vérifie si le joueur a collecté une paire de ce symbole (c'est-à-dire un nombre pair de ce symbole).
    if (joueur.SymboleScientifiques[symbole] % 2 == 0) {
        // Si oui, annonce que le joueur a collecté une paire et peut choisir un jeton de progrès.
        std::cout << "Paire de symboles collectée. Choix d'un jeton de progrès." << std::endl;
        // Appelle la méthode offrirChoixJetonProgres pour permettre au joueur de choisir un jeton de progrès.
        // Cette action est un avantage pour le joueur, lui offrant un bonus ou une capacité spéciale.
        offrirChoixJetonProgres(joueur);
    }

    // Après chaque collecte de symbole, vérifie si le joueur a atteint une victoire scientifique.
    // Cette vérification se fait en appelant checkVictoireScientifique avec le joueur comme argument.
    if (checkVictoireScientifique(joueur)) {
        // Si le joueur a atteint la condition de victoire scientifique (collecter au moins 6 symboles uniques),
        // annonce la victoire scientifique du joueur.
        std::cout << "Victoire scientifique pour " << joueur.getNom() << "!" << std::endl;
    }
}

bool Plateau::checkVictoireScientifique(const Joueur& joueur) {
    // Crée un ensemble pour stocker les symboles scientifiques uniques.
    // std::set est utilisé car il ne permet pas les doublons, ce qui facilite le comptage des symboles uniques.
    std::set<SymboleScientifiques> uniqueSymbols;

    // Parcourt tous les symboles scientifiques collectés par le joueur.
    for (const auto& pair : joueur.scientificSymbols) {
        // Vérifie si le joueur a au moins une instance du symbole scientifique (pair.second > 0).
        // Si oui, le symbole (pair.first) est inséré dans l'ensemble des symboles uniques.
        // L'insertion échouera silencieusement si le symbole est déjà présent, garantissant l'unicité.
        if (pair.second > 0) {
            uniqueSymbols.insert(pair.first);
        }
    }

    // Évalue si le nombre de symboles scientifiques uniques collectés par le joueur est égal ou supérieur à 6.
    // La condition de victoire scientifique est satisfaite si le joueur a collecté au moins
    // 6 symboles scientifiques différents.
    // Renvoie 'true' si la condition est remplie, 'false' sinon.
    // Cette condition reflète une des voies possibles pour gagner le jeu, en mettant l'accent
    // sur la diversité scientifique.
    return uniqueSymbols.size() >= 6;
}

void Plateau::offrirChoixSymboleScientifique(Joueur& joueur) {
    // Invite le joueur à choisir un symbole scientifique parmi la liste.
    std::cout << "Choisissez un symbole scientifique : " << std::endl;

    // Crée une liste des symboles scientifiques disponibles pour le choix.
    std::vector<SymboleScientifiques> symboles = {SymboleScientifiques::Roue,
                                                  SymboleScientifiques::Compas,
                                                  SymboleScientifiques::Mortier_Pilon,
                                                  SymboleScientifiques::Tablette,
                                                  SymboleScientifiques::Lyre,
                                                  SymboleScientifiques::Mesure,
                                                  SymboleScientifiques::Telescope};

    // Variable pour numéroter les choix affichés à l'utilisateur.
    int choix = 1;

    // Boucle sur chaque symbole scientifique pour afficher les options disponibles.
    for(auto symbole : symboles) {
        std::cout << choix << ": ";
        // Selon le symbole, affiche le nom correspondant pour rendre le choix plus clair pour le joueur.
        switch(symbole) {
            case SymboleScientifiques::Roue:std::cout << "Roue"; break;
            case SymboleScientifiques::Compas:std::cout << "Compas"; break;
            case SymboleScientifiques::Mortier_Pilon:std::cout << "Mortier Pilon"; break;
            case SymboleScientifiques::Tablette:std::cout << "Tablette"; break;
            case SymboleScientifiques::Lyre:std::cout << "Lyre"; break;
            case SymboleScientifiques::Mesure:std::cout << "Mesure"; break;
            case SymboleScientifiques::Telescope:std::cout << "Telescope"; break;
        }
        std::cout << std::endl;
        choix++; // Incrémente le numéro de choix pour l'affichage du prochain symbole.
    }

    // Demande au joueur de faire son choix. Utilise validerInput pour s'assurer que l'entrée est un choix valide
    // entre 1 et la taille de la liste des symboles.
    int choixJoueur = validerInput(1, symboles.size()) - 1; // Soustrait 1 car les indices du tableau
    // commencent à 0.

    // Sélectionne le symbole scientifique basé sur le choix du joueur.
    SymboleScientifiques symboleChoisi = symboles[choixJoueur];

    // Ajoute le symbole scientifique choisi au joueur.
    joueur.ajouterSymboleScientifique(symboleChoisi);
}
