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

Age const Carte::getAge() {
    return age;
}

Effet const Carte::getEffet(){
    return effet;
}

