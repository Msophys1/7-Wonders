#include "Carte.h"

int Carte::nextId = 1;

Carte::Carte(std::string nom, std::string couleur, std::vector<std::string> cost, std::string type,
             int pointsDeVictoire, std::string symbolesScientifiques, std::string chainage,
             int boucliers, int argent, std::vector<std::string> avantages,
             std::vector<std::string> produits)
        : id(nextId++), nom(std::move(nom)), couleur(std::move(couleur)), cost(std::move(cost)), type(std::move(type)),
          pointsDeVictoire(pointsDeVictoire), symbolesScientifiques(std::move(symbolesScientifiques)),
          chainage(std::move(chainage)), boucliers(boucliers), argent(argent), avantages(std::move(avantages)),
          produits(std::move(produits)) {}


void Carte::chargerDeckDepuisFichier(const std::string& cheminFichier) {
    std::ifstream fichier(cheminFichier);
    if (!fichier.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier des cartes.");
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


// Définition de la méthode testerChargementDecks dans Carte.cpp
void Carte::testerChargementDecks() {

    Carte::chargerDeckDepuisFichier("D:/CLion/7-Wonders/Assets/Cartes.json");

    // Vérification du nombre de cartes dans chaque deck d'âge
    for (int i = 0; i < 3; i++) {
        std::cout << "Age " << i + 1 << " contient " << Carte::decksParAge[i].size() << " cartes." << std::endl;
    }

// Itérer à travers chaque deck d'âge
    for (auto & i : Carte::decksParAge) {

        // Itérer à travers chaque carte dans le deck
        for (const auto& carte : i) {
            std::cout << "\n" <<"ID: " << carte.getID() << "\n"
                      << "Nom: " << carte.getNom() << "\n"
                      << "Couleur: " << carte.getCouleur() << "\n"
                      << "Type: " << carte.getType()<< "\n"
                      << "Chainage: " << carte.getChainage() << "\n"
                      << "Symbole Scientifique: " << carte.getSymbolesScientifiques() << "\n"
                      << "Points de Victoire: " << carte.getPointsDeVictoire() <<"\n"
                      << "Argent: " << carte.getArgent() <<"\n"
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
                std::cout << avantage << " " <<"\n";
            }
            std::cout << std::endl;

            // Afficher les produits
            std::cout << "Produits: ";
            for (const auto& produit : carte.getProduits()) {
                std::cout << produit << " " ;
            }
            std::cout << std::endl;
        }
    }
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
    if (produitJson.contains("produitManufacture") && produitJson["produitManufacture"].is_array()) {
        for (const auto& produit : produitJson["produitManufacture"]) {
            std::string itemProduit = produit.get<std::string>();
            if (!itemProduit.empty()) {
                produits.emplace_back(itemProduit);
            } else {
                produits.emplace_back("0");
            }
        }
    }
    return produits;
}

std::vector<Carte> Carte::decksParAge[3];
