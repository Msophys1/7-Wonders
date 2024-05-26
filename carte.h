#pragma once

#include <iostream>
#include <string>
#include <list>
#include <set>

#include "Type.h"

#ifndef CARTE_H
#define CARTE_H
//enum class type_batiment { Militaire, Scientifique, Manufacture, Premiere, Civil, Commerce, Guilde, Merveille };
//enum class JetonsProgres { Agriculture, Architecture, Economie, Loi, Maconnerie, Mathematiques, Philosophie, Strategie, Theologie, Urbanisme };
//enum class phase_jeu { START, AGE_I, AGE_II, AGE_III, END };
//enum class ressource { Bouclier, Papyrus, Verre, Pierre, Argile, Bois, Roue, Compas, Pilon, Tablette, Lyre, Mesure, Telescope };

std::set<Ressources> getMatierePremiere();
std::set<Ressources> getProduitManufacture();
std::set<Ressources> getRessource();
std::set<Ressources> getSymboleScientifique();

std::string tostringRessources(Ressources r);
std::string tostringType(Types t);

class Carte {
public:
    Carte(std::string nom, Types type, std::list<Ressources> cost_r = {}, unsigned int cost_m = 0, unsigned int argent = 0, unsigned int pt_victoire = 0, bool visible = false, bool selectionnee = false);

    // GETTERS
    std::string getNom() const { return nom; }
    bool getVisibilite const { return visible;}
    bool getSelection const { return selectionnee;}
    Types getType() const { return type; }
    unsigned int getCoutArgent() const { return cost_m; }
    unsigned int getRewardArgent() const { return argent; }
    unsigned int getPointVictoire() const { return pt_victoire; }
    std::list<Ressources> getCoutRessource() const { return cost_r; }

    // SETTERS
    void setNom(std::string new_nom) { nom = new_nom; }
    void setVisibilite(bool v) { visible = v; }
    void setSelection(bool s) { selectionnee = s; }
    void setCoutArgent(unsigned int new_cost_m) { cost_m = new_cost_m; }
    void setRewardArgent(unsigned int new_argent) { argent = new_argent; }
    void setPointVictoire(unsigned int new_pt_victoire) { pt_victoire = new_pt_victoire; }
    void setCoutRessource(std::list<Ressources> cost);

    // UTILS
    bool achetableRessource(std::list<Ressources> buy) const;

private:
    std::string nom;
    const Types type;
    std::list<Ressources> cost_r; // cout en ressources
    unsigned int cost_m; // cout en argent

    unsigned int argent;
    unsigned int pt_victoire;

    bool checkCoutRessources(std::list<Ressources> cost_r) const;
    bool visible;
    bool selectionnee;
};

std::ostream& operator<<(std::ostream& f, Carte c);

class Batiment : public Carte {
    // Civil, Scientifique, Militaire, Ressources
public:
private:
    std::list<Ressources> production;
    Batiment& chained_by;
};

class Guilde : public Batiment {
public:
private:
    Types affectation;
    bool usurier;
};

class Commerce : public Batiment {
public:
private:
};

class Merveille : public Carte {
public:
    Merveille(std::string nom, Types type = Types::Merveille, std::list<Ressources> cost_r = {}, unsigned int cost_m = 0, unsigned int argent = 0, unsigned int pt_victoire = 0, bool b = false) : Carte(nom, type, cost_r, cost_m, argent, pt_victoire), replay(b) {
        if (type != Types::Merveille) {
            throw std::runtime_error("Merveille instanciée avec un type autre que Merveille");
        }
    };

    // GETTERS
    bool getReplay() const { return replay; }

    // SETTERS
    void setReplay(bool b) { replay = b; }

private:
    bool replay;
};
#endif // CARTE_H
