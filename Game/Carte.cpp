#include "Carte.h"


Carte::Carte(std::string nom, std::string couleur, std::vector<std::string> cost,
             int pointsDeVictoire, std::vector<std::string> symbolesScientifiques,
             int boucliers, int argent, std::vector<std::string> avantages,
             std::vector<std::string> produits)
        : nom(std::move(nom)), couleur(std::move(couleur)), cost(std::move(cost)),
          pointsDeVictoire(pointsDeVictoire), symbolesScientifiques(std::move(symbolesScientifiques)),
          boucliers(boucliers), argent(argent), avantages(std::move(avantages)),
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
            auto produits = parseProduit(carteData["produit"]);
            int pointsDeVictoire = carteData["points_de_victoire"];
            auto symbolesScientifiques = parseSymbolesScientifiques(carteData["symboles_scientifiques"]);
            int boucliers = carteData["boucliers"];
            int argent = carteData["argent"];
            auto avantages = parseAvantages(carteData["avantage"]);

            decksParAge[ageIndex].emplace_back(nom, couleur, cost, pointsDeVictoire, symbolesScientifiques, boucliers, argent, avantages, produits);
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

std::vector<std::string> Carte::parseSymbolesScientifiques(const nlohmann::json& symbolesJson) {
    std::vector<std::string> symboles;
    if (symbolesJson.is_array()) {
        for (const auto& item : symbolesJson) {
            std::string symbole = item.get<std::string>();
            if (!symbole.empty()) {
                symboles.emplace_back(symbole);
            } else {
                symboles.emplace_back("0");
            }
        }
    } else if (symbolesJson.is_string()) {
        std::string symbole = symbolesJson.get<std::string>();
        if (!symbole.empty()) {
            symboles.emplace_back(symbole);
        } else {
            symboles.emplace_back("0");
        }
    }
    return symboles;
}

// Définition de la méthode testerChargementDecks dans Carte.cpp
void Carte::testerChargementDecks() {

    Carte::chargerDeckDepuisFichier("D:/CLion/7-Wonders/Assets/Cartes.json");

    // Vérification du nombre de cartes dans chaque deck d'âge
    for (int i = 0; i < 3; i++) {
        std::cout << "Age " << i + 1 << " contient " << Carte::decksParAge[i].size() << " cartes." << std::endl;
    }

    // Exemple de vérification pour la première carte de l'âge 1, si disponible
    if (!Carte::decksParAge[0].empty()) {
        const Carte& carte = Carte::decksParAge[0][0];
        std::cout << "Nom de la premiere carte de l'age 1: " << "\n" << carte.getNom() <<std::endl;
        std::cout << "Couleur de la premiere carte de l'age 1: " << "\n" << carte.getCouleur() <<std::endl;

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