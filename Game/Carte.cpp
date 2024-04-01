#include "Carte.h"


Carte::Carte(std::string nom, std::string couleur, std::vector<std::string> cost,
             int pointsDeVictoire, std::vector<std::string> symbolesScientifiques,
             int boucliers, int argent, std::vector<std::string> avantages)
        : nom(std::move(nom)), couleur(std::move(couleur)), cost(std::move(cost)),
          pointsDeVictoire(pointsDeVictoire), symbolesScientifiques(std::move(symbolesScientifiques)),
          boucliers(boucliers), argent(argent), avantages(std::move(avantages)) {}

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
            int pointsDeVictoire = carteData["points_de_victoire"];
            auto symbolesScientifiques = parseSymbolesScientifiques(carteData["symboles_scientifiques"]);
            int boucliers = carteData["boucliers"];
            int argent = carteData["argent"];
            auto avantages = parseAvantages(carteData["avantage"]);

            // Crée une instance de Carte et l'ajoute au vecteur correspondant
            decksParAge[ageIndex].emplace_back(nom, couleur, cost, pointsDeVictoire, symbolesScientifiques, boucliers, argent, avantages);
        }
    }
}


std::vector<std::string> Carte::parseCost(const nlohmann::json& costJson) {
    std::vector<std::string> cost;
    if (costJson.is_array()) {
        for (const auto& item : costJson) {
            if (item.is_string()) {
                cost.push_back(item.get<std::string>());
            }
        }
    } else if (costJson.is_string()) {
        cost.push_back(costJson.get<std::string>());
    }
    return cost;
}

std::vector<std::string> Carte::parseAvantages(const nlohmann::json& avantagesJson) {
    std::vector<std::string> avantages;
    if (avantagesJson.is_array()) {
        for (const auto& item : avantagesJson) {
            if (item.is_string()) {
                avantages.push_back(item.get<std::string>());
            }
        }
    }
    return avantages;
}

std::vector<std::string> Carte::parseSymbolesScientifiques(const nlohmann::json &symbolesJson) {
    std::vector<std::string> symboles;
    if (symbolesJson.is_array()) {
        for (const auto& item : symbolesJson) {
            if (item.is_string()) {
                symboles.push_back(item.get<std::string>());
            }
        }
    } else if (symbolesJson.is_string()) {
        symboles.push_back(symbolesJson.get<std::string>());
    }
    return symboles;
}

