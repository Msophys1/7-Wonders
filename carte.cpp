#include <iostream>
#include<string>
#include "carte.h"
using namespace std;



string const Carte::getNom() {
    return nom;
}

Prix const Carte::getPrix(){
    return prix;
}

string const Carte::getAge() {
    return ageToString(age);
}

Effet const Carte::getEffet(){
    return effet;
}

