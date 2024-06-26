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
    Carte(std::string nom, std::string couleur, std::vector<std::string> cost,
          int pointsDeVictoire, std::vector<std::string> symbolesScientifiques,
          int boucliers, int argent, std::vector<std::string> avantages,
          std::vector<std::string> produits);

// Getters
    std::string getNom() const { return nom; }
    std::string getCouleur() const { return couleur; }
    std::vector<std::string> getCost() const { return cost; }
    int getPointsDeVictoire() const { return pointsDeVictoire; }
    std::vector<std::string> getSymbolesScientifiques() const { return symbolesScientifiques; }
    int getBoucliers() const { return boucliers; }
    int getArgent() const { return argent; }
    std::vector<std::string> getAvantages() const { return avantages; }
    std::vector<std::string> getProduits() const { return produits; }

// Setters
    void setNom(const std::string& value) { nom = value; }
    void setCouleur(const std::string& value) { couleur = value; }
    void setCost(const std::vector<std::string>& value) { cost = value; }
    void setPointsDeVictoire(int value) { pointsDeVictoire = value; }
    void setSymbolesScientifiques(const std::vector<std::string>& value) { symbolesScientifiques = value; }
    void setBoucliers(int value) { boucliers = value; }
    void setArgent(int value) { argent = value; }
    void setAvantages(const std::vector<std::string>& value) { avantages = value; }

    // Méthode statique pour charger les cartes depuis un fichier JSON
    static void chargerDeckDepuisFichier(const std::string& cheminFichier);
    static void testerChargementDecks();


private:
    std::string nom;
    std::string couleur;
    std::vector<std::string> cost;
    std::vector<std::string> produits;
    int pointsDeVictoire;
    std::vector<std::string> symbolesScientifiques;
    int boucliers;
    int argent;
    std::vector<std::string> avantages;

    // Méthodes statiques pour le parsing
    static std::vector<std::string> parseCost(const nlohmann::json& json);
    static std::vector<std::string> parseAvantages(const nlohmann::json& json);
    static std::vector<std::string> parseSymbolesScientifiques(const nlohmann::json& symbolesJson);
    static std::vector<std::string> parseProduit(const nlohmann::json &produitJson);

    static std::vector<Carte> decksParAge[3];
};

#endif // CARTE_H
