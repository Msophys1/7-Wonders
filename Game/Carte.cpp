#include "Carte.h"

int Carte::nextId = 1;
int Guilde::nextGuildeID = 1;

// Constructeur pour la classe Carte
Carte::Carte(std::string nom, std::string couleur, std::vector<std::string> cost, std::string type,
             int pointsDeVictoire, std::string symbolesScientifiques, std::string chainage,
             int boucliers, int argent, std::vector<std::string> avantages,
             std::vector<std::string> produits)
        : id(nextId++), nom(std::move(nom)), couleur(std::move(couleur)), cost(std::move(cost)), type(std::move(type)),
          pointsDeVictoire(pointsDeVictoire), symbolesScientifiques(std::move(symbolesScientifiques)),
          chainage(std::move(chainage)), boucliers(boucliers), argent(argent), avantages(std::move(avantages)),
          produits(std::move(produits)) {}

// Constructeur pour la classe Guilde
Guilde::Guilde(std::string nom, std::string couleur, std::vector<std::string> cost, std::string type,
               int pointsDeVictoire, std::string symbolesScientifiques, std::string chainage, int boucliers,
               int argent, std::vector<std::string> avantages, std::vector<std::string> produits,
               const std::string &nom1, const std::vector<std::string> &cost1, int pointsDeVictoire1,
               const std::vector<std::string> &affectation, int argent1)
        : Carte(std::move(nom), std::move(couleur), std::move(cost), std::move(type), pointsDeVictoire,
                std::move(symbolesScientifiques), std::move(chainage), boucliers, argent, std::move(avantages),
                std::move(produits)), affectation(affectation), id(nextGuildeID++) {}



void Carte::chargerDeckDepuisFichier(const std::string& cheminFichier) {
    std::ifstream fichier(cheminFichier);
    if (!fichier.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier des cartes." + cheminFichier);
    }

    nlohmann::json deckJson;
    fichier >> deckJson;

    for (const auto& ageKey : {"Age1", "Age2", "Age3"}) {
        int ageIndex = (ageKey[3] - '1'); // Convertit '1', '2', '3' en 0, 1, 2
        for (const auto& carteData : deckJson[ageKey]) {
            std::string nom = carteData["name"];
            std::string couleur = carteData["couleur"];
            auto cost = parseCost(carteData["cost"]);
            std::string type = carteData["type"];
            auto produits = parseProduit(carteData["produit"]);
            int pointsDeVictoire = carteData["points_de_victoire"];
            std::string symbolesScientifiques = carteData["symboles_scientifiques"];
            std::string chainage = carteData["chainage"];
            int boucliers = carteData["boucliers"];
            int argent = carteData["argent"];
            auto avantages = parseAvantages(carteData["avantage"]);


            decksParAge[ageIndex].emplace_back(nom, couleur, cost, type, pointsDeVictoire, symbolesScientifiques,
                                               chainage, boucliers, argent, avantages, produits);
        }
    }
    fichier.close();
}

// Implémentation pour charger les decks de Guilde depuis un fichier
void Guilde::chargerDeckGuildeDepuisFichier(const std::string& cheminFichier) {
    std::ifstream fichier(cheminFichier);
    if (!fichier.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier des guildes." + cheminFichier);
    }

    nlohmann::json deckJson;
    fichier >> deckJson;

    for (const auto& guildeData : deckJson["Guilde"]) {
        std::string nom = guildeData["name"];
        std::string couleur = "violet";
        auto cost = parseCost(guildeData["cost"]);
        std::string type = "Guilde";
        auto produits = std::vector<std::string>(); // Les guildes n'ont pas de produits
        int pointsDeVictoire = guildeData["victoire"];
        std::string symbolesScientifiques;
        std::string chainage;
        int boucliers = 0;
        int argent = guildeData["argent"];
        auto avantages = std::vector<std::string>();
        auto affectation = parseAffectation(guildeData["affectation"]);

        decksGuilde[0].emplace_back(nom, couleur, cost, type, pointsDeVictoire, symbolesScientifiques,
                                   chainage, boucliers, argent, avantages, produits, nom, cost,
                                   pointsDeVictoire, affectation, argent);
    }

    fichier.close();
}


std::vector<std::string> Carte::parseCost(const nlohmann::json& costJson) {
    std::vector<std::string> cost;
    if (costJson.is_array()) {
        for (const auto& item : costJson) {
            std::string itemCost = item.get<std::string>();
            if (!itemCost.empty()) {
                cost.push_back(itemCost);
            } else {
                cost.emplace_back("0");
            }
        }
    } else if (costJson.is_string()) {
        std::string itemCost = costJson.get<std::string>();
        if (!itemCost.empty()) {
            cost.push_back(itemCost);
        } else {
            cost.emplace_back("0");
        }
    }
    return cost;
}

std::vector<std::string> Carte::parseAvantages(const nlohmann::json& avantagesJson) {
    std::vector<std::string> avantages;
    if (avantagesJson.is_array()) {
        for (const auto& item : avantagesJson) {
            std::string avantage = item.get<std::string>();
            if (!avantage.empty()) {
                avantages.emplace_back(avantage);
            } else {
                avantages.emplace_back("0");
            }
        }
    }
    return avantages;
}

std::vector<std::string> Carte::parseProduit(const nlohmann::json& produitJson) {
    std::vector<std::string> produits;
    if (produitJson.contains("ressources") && produitJson["ressources"].is_array()) {
        for (const auto& ressource : produitJson["ressources"]) {
            std::string itemRessource = ressource.get<std::string>();
            if (!itemRessource.empty()) {
                produits.emplace_back(itemRessource);
            } else {
                produits.emplace_back("0");
            }
        }
    }
    return produits;
}

std::vector<std::string> Carte::parseAffectation(const nlohmann::json &json) {
    std::vector<std::string> affectation;
    for (const auto &item: json) {
        affectation.push_back(item);
    }
    return affectation;
}

void Carte::testerChargementDecks() {
    // Charger les cartes et les guildes depuis leurs fichiers respectifs
    Carte::chargerDeckDepuisFichier("D:/CLion/7-Wonders/Assets/Cartes.json");
    Guilde::chargerDeckGuildeDepuisFichier("D:/CLion/7-Wonders/Assets/Cartes.json");

    // Vérification du nombre de cartes dans chaque deck d'âge
    for (int i = 0; i < 3; i++) {
        std::cout << "Age " << i + 1 << " contient " << Carte::decksParAge[i].size() << " cartes." << std::endl;
    }

    // Vérification du nombre de guildes
    std::cout << "Guildes contient " << Guilde::decksGuilde[0].size() << " guildes." << std::endl;

    // Itérer à travers chaque deck d'âge
    for (auto & deck : Carte::decksParAge) {
        // Itérer à travers chaque carte dans le deck
        for (const auto& carte : deck) {
            std::cout << "\nID: " << carte.getID() << "\n"
                      << "Nom: " << carte.getNom() << "\n"
                      << "Couleur: " << carte.getCouleur() << "\n"
                      << "Type: " << carte.getType() << "\n"
                      << "Chainage: " << carte.getChainage() << "\n"
                      << "Symbole Scientifique: " << carte.getSymbolesScientifiques() << "\n"
                      << "Points de Victoire: " << carte.getPointsDeVictoire() << "\n"
                      << "Argent: " << carte.getArgent() << "\n"
                      << "Bouclier: " << carte.getBoucliers() << std::endl;

            // Afficher le coût
            std::cout << "Cout: ";
            for (const auto& cost : carte.getCost()) {
                std::cout << cost << " ";
            }
            std::cout << std::endl;

            // Afficher les avantages
            std::cout << "Avantages: ";
            for (const auto& avantage : carte.getAvantages()) {
                std::cout << avantage << " ";
            }
            std::cout << std::endl;

            // Afficher les produits
            std::cout << "Produits: ";
            for (const auto& produit : carte.getProduits()) {
                std::cout << produit << " ";
            }
            std::cout << std::endl;
        }
    }

    // Itérer à travers le deck des guildes
    for (const auto& guilde : Guilde::decksGuilde[0]) {
        std::cout << "\nID: " << guilde.getIDGuilde() << "\n"
                  << "Nom: " << guilde.getNom() << "\n"
                  << "Couleur: " << guilde.getCouleur() << "\n"
                  << "Type: " << guilde.getType() << "\n"
                  << "Points de Victoire: " << guilde.getPointsDeVictoire() << "\n"
                  << "Argent: " << guilde.getArgent() << std::endl;

        // Afficher le coût
        std::cout << "Cout: ";
        for (const auto& cost : guilde.getCost()) {
            std::cout << cost << " ";
        }
        std::cout << std::endl;

        // Afficher les affectations spécifiques à la guilde
        std::cout << "Affectation: ";
        for (const auto& affectation : guilde.getAffectation()) {
            std::cout << affectation << " ";
        }
        std::cout << std::endl;
    }
}


std::vector<Carte> Carte::decksParAge[3];
std::vector<Guilde> Guilde::decksGuilde[1];
