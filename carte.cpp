#include <iostream>
#include<string>
#include "carte.h"
using namespace std;

string Carte::ageToString(Age age) {
    switch(age) {
        case AGE_I: return "I";
        case AGE_II: return "II";
        case AGE_III: return "III";
        default: return "Invalid Age";
    }
}

string Carte::RessourceToString(Ressource ressource) {
    switch(ressource) {
        case Bois: return "Bois";
        case Pierre: return "Pierre";
        case Verre: return "Verre";
        case Papyrus: return "Papyrus";
        case Argile: return "Argile";
        case Aucune: return "Aucune";
        default: return "Ressource invalide";
    }
}

string const Carte::getNom() {
    return nom;
}

int const Carte::getPrix(){
    return prix;
}

string const Carte::getAge() {
    return ageToString(age);
}

string const Carte::getRessource() {
    return RessourceToString(effet.ressource);

}

int const Carte::getRecompense(){
    return effet.recompense;
}

string const Carte::getCondition(){
        return condition;
}
