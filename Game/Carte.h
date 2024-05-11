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
    Carte(std::string nom,
          std::string couleur,
          std::vector<std::string> cost,
          std::string type,
          int pointsDeVictoire,
          std::string symbolesScientifiques,
          std::string chainage,
          int boucliers,
          int argent,
          std::vector<std::string> avantages,
          std::vector<std::string> produits);

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


    static std::vector<std::string> parseAvantages(const nlohmann::json& json);
    static std::vector<std::string> parseProduit(const nlohmann::json &produitJson);

    static std::vector<Carte> decksParAge[3];
protected:
    // Méthodes statiques pour le parsing
    static std::vector<std::string> parseCost(const nlohmann::json& json);

    static std::vector<std::string> parseAffectation(const nlohmann::json &json);


    int id;
};

class Guilde : public Carte {
public:
    // Constructeur pour Guilde
    Guilde(std::string nom1, std::string couleur, std::vector<std::string> cost1, std::string type,
           int pointsDeVictoire1, std::string symbolesScientifiques, std::string chainage, int boucliers,
           int argent1, std::vector<std::string> avantages, std::vector<std::string> produits,
           const std::string &nom, const std::vector<std::string> &cost, int pointsDeVictoire,
           const std::vector<std::string> &affectation, int argent);

    static void chargerDeckGuildeDepuisFichier(const std::string &cheminFichier);

    // Getter pour l'affectation spécifique à Guilde
    const std::vector<std::string>& getAffectation() const { return affectation; }
    int getIDGuilde() const{return id;}

    static std::vector<Guilde> decksGuilde[1];
private:
    std::vector<std::string> affectation;
    static int nextGuildeID;
    int argent;
    int id;
};

#endif // CARTE_H
