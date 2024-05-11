#ifndef CARTE_H
#define CARTE_H

#include <string>
#include <vector>
#include <iostream>
#include <json.hpp>
#include <fstream>
#include "Type.h"

class Carte {
public:
    Carte(std::string nom, std::string couleur, std::vector<std::string> cost,std::string type,
          int pointsDeVictoire, std::string symbolesScientifiques, std::string chainage,
          int boucliers, int argent, std::vector<std::string> avantages,
          std::vector<std::string> produits);


    //Guilde(std::string nom, std::string type...);

    //Merveille(jefbsfhbiqzebfiqebfrfibei...)

// Getters
    std::string getNom() const { return nom; }
    std::string getCouleur() const { return couleur; }
    std::vector<std::string> getCost() const { return cost; }
    int getPointsDeVictoire() const { return pointsDeVictoire; }
    std::string getSymbolesScientifiques() const { return symbolesScientifiques; }
    std::string getType() const { return type; }
    std::string getChainage() const { return chainage; }
    int getBoucliers() const { return boucliers; }
    int getArgent() const { return argent; }
    std::vector<std::string> getAvantages() const { return avantages; }
    std::vector<std::string> getProduits() const { return produits; }
    int getID() const{return id;}


    // Méthode statique pour charger les cartes depuis un fichier JSON
    static void chargerDeckDepuisFichier(const std::string& cheminFichier);
    static void testerChargementDecks();


private:
    int id;
    static int nextId;
    std::string nom;
    std::string couleur;
    std::vector<std::string> cost;
    std::string type;
    std::vector<std::string> produits;
    int pointsDeVictoire;
    std::string symbolesScientifiques;
    std::string chainage;
    int boucliers;
    int argent;
    std::vector<std::string> avantages;



    // Méthodes statiques pour le parsing
    static std::vector<std::string> parseCost(const nlohmann::json& json);
    static std::vector<std::string> parseAvantages(const nlohmann::json& json);
    static std::string parseSymbolesScientifiques(const nlohmann::json& symbolesJson);
    static std::vector<std::string> parseProduit(const nlohmann::json &produitJson);

    static std::vector<Carte> decksParAge[3];
};

#endif // CARTE_H
