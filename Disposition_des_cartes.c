#include <vector>
#include <algorithm>
#include <random>
#include "Carte.h"



std::vector<std::vector<Carte>> dispositionDesCartes(phase_jeu phase, std::vector<Carte>& cartes) {

    // Mélanger les cartes et retirer 3 cartes
    std::random_device rd;
    std::mt19937 g(rd());


    std::vector<std::vector<Carte>> disposition;

    if (phase == phase_jeu::AGE_I) {

        std::shuffle(cartes.begin(), cartes.end(), g);
        cartes.resize(20); // Enlever 3 cartes



        s = 0;

        for (int i = 0; i < 5; ++i){
          for (int j = 0; j < 6-i; ++j){
            disposition[i][j] = *cartes.begin() + j + s;
          }
          s+= 6-i;

        }
        for (int i = 0; i < disposition[0].size(); ++i) disposition[0][i].setVisibilite(true);
        for (int i = 0; i < disposition[2].size(); ++i) disposition[2][i].setVisibilite(true);
        for (int i = 0; i < disposition[4].size(); ++i) disposition[4][i].setVisibilite(true);

    }
    } else if (phase == phase_jeu::AGE_II) {
        std::shuffle(cartes.begin(), cartes.end(), g);
        cartes.resize(20); // Enlever 3 cartes

        std::vector<std::vector<Carte>> disposition;

        s = 0;

        for (int i = 0; i < 5; ++i){
          for (int j = 0; j < 2+i; ++j){
            disposition[i][j] = *cartes.begin() + j + s;
          }
          s+= 2+i;
        }
        for (int i = 0; i < disposition[0].size(); ++i) disposition[0][i].setVisibilite(true);
        for (int i = 0; i < disposition[2].size(); ++i) disposition[2][i].setVisibilite(true);
        for (int i = 0; i < disposition[4].size(); ++i) disposition[4][i].setVisibilite(true);
    }
    else if (phase == phase_jeu::AGE_III) {

        /*std::shuffle(cartes.begin(), cartes.end(), g);
        cartes.resize(20); // Enlever 3 cartes*/

        disposition = {
            {*cartes.begin(), *(cartes.begin() + 1)},
            {*(cartes.begin() + 2), *(cartes.begin() + 3),*(cartes.begin() + 4)},
            {*(cartes.begin() + 5), *(cartes.begin() + 6),*(cartes.begin() + 7), *(cartes.begin() + 8)},
            {*cartes.begin() + 9, *(cartes.begin() + 10)},
            {*(cartes.begin() + 11), *(cartes.begin() + 12),*(cartes.begin() + 13), *(cartes.begin() + 14)},
            {*(cartes.begin() + 15), *(cartes.begin() + 16),*(cartes.begin() + 17)},
            {*cartes.begin() + 18, *(cartes.begin() + 19)}
        };
        for (int i = 0; i < disposition[0].size(); ++i) disposition[0][i].setVisibilite(true);
        for (int i = 0; i < disposition[2].size(); ++i) disposition[2][i].setVisibilite(true);
        for (int i = 0; i < disposition[4].size(); ++i) disposition[4][i].setVisibilite(true);
        for (int i = 0; i < disposition[6].size(); ++i) disposition[6][i].setVisibilite(true);
    }

    return disposition;

}



Carte ChoixDeCartes(phase_jeu phase, std::vector<Carte>& cartes){

    std::vector<std::vector<Carte>> disposition = dispositionDesCartes(phase, cartes);
    int a,b = 0;
    if (phase == phase_jeu::AGE_I){
        while (true) {
            // Afficher les noms des cartes dans le premier vecteur (premier étage)
            std::cout << "Les cartes visibles sont :" << std::endl;
            for (size_t i = 0; i < disposition.size(); ++i) {
                for (size_t j = 0; j < disposition[i].size(); ++i){
                    if(disposition[i][j].getVsibilite() == true){
                    std::cout << disposition[i][j].getNom() << std::endl;
                    }
                }
            }

            // Demander au joueur de choisir une carte
            std::cout << "Entrez la position de la carte que vous souhaitez sélectionner : ";
            std::cin<< a << b;


            if( b > 6-a || b < 0 || a < 0 || a > 4 ){
                std::cout << "Position non existante !";
            }

            else {

                // Utiliser une série de if-else pour émuler un switch case
                if(disposition[a][b].getVisibilite() == true){

                    if(a == 0) {
                        if(disposition[a][b].getSelection() == false){
                            disposition[a][b].setSelection(true) ;
                            return disposition[a][b];
                        }
                    }
                    else{
                        if(disposition[a-1][b].getSelection() == true && disposition[a-1][b+1].getSelection() == true && disposition[a][b].getSelection()== false){
                            disposition[a][b].setSelection(true);
                            return disposition[a][b];
                        }

                    }

                }

            }
        }
    }
    if (phase == phase_jeu::AGE_II){
        while (true) {
            // Afficher les noms des cartes dans le premier vecteur (premier étage)
            std::cout << "Les cartes visibles sont :" << std::endl;
            for (size_t i = 0; i < disposition.size(); ++i) {
                for (size_t j = 0; j < disposition[i].size(); ++i){
                    if(disposition[i][j].getVsibilite() == true){
                    std::cout << disposition[i][j].getNom() << std::endl;
                    }
                }
            }

            // Demander au joueur de choisir une carte
            std::cout << "Entrez la position de la carte que vous souhaitez sélectionner : ";
            std::cin<< a << b;


            if( b > a+1 || b < 0 || a < 0 || a > 4 ){
                std::cout << "Position non existante !";
            }

            else {

                // Utiliser une série de if-else pour émuler un switch case
                if(disposition[a][b].getVisibilite() == true){

                    if(a == 0) {
                        if(disposition[a][b].getSelection() == false){
                            disposition[a][b].setSelection(true) ;
                            return disposition[a][b];
                        }
                    }
                    else{
                        if(b == 0 && disposition[a-1][b].getSelection() = true && disposition[a][b].getSelection() == false){
                            disposition[a][b].setSelection(true) ;
                            return disposition[a][b];
                        }
                        else if(b == a+1 && disposition[a-1][b-1].getSelection() = true && disposition[a][b].getSelection() == false){
                            disposition[a][b].setSelection(true) ;
                            return disposition[a][b];
                        }
                        else if(b != 0 && b != a+1){
                            if(disposition[a-1][b-1].getSelection() = true && disposition[a-1][b].getSelection() = true && disposition[a][b].getSelection() == false){
                                disposition[a][b].setSelection(true) ;
                                return disposition[a][b];
                            }
                        }

                    }

                }

            }
        }
    }
    if (phase == phase_jeu::AGE_III){
        while (true) {
            // Afficher les noms des cartes dans le premier vecteur (premier étage)
            std::cout << "Les cartes visibles sont :" << std::endl;
            for (size_t i = 0; i < disposition.size(); ++i) {
                for (size_t j = 0; j < disposition[i].size(); ++i){
                    if(disposition[i][j].getVsibilite() == true){
                    std::cout << disposition[i][j].getNom() << std::endl;
                    }
                }
            }

            // Demander au joueur de choisir une carte
            std::cout << "Entrez la position de la carte que vous souhaitez sélectionner : ";
            std::cin<< a << b;


            if( a > 6 || a < 0 || b < 0 || (a < 3 && b>a+1) || (a == 3 && b > 1) || (a > 3 && b > 7 - a)){
                std::cout << "Position non existante !";
            }

            else {
                // Utiliser une série de if-else pour émuler un switch case
                if(disposition[a][b].getVisibilite() == true){

                    if(a < 3 ){
                        if(a == 0) {
                            if(disposition[a][b].getSelection() == false){
                                disposition[a][b].setSelection(true) ;
                                return disposition[a][b];
                            }
                        }
                        else{
                            if(b == 0 && disposition[a-1][b].getSelection() = true && disposition[a][b].getSelection() == false){
                                disposition[a][b].setSelection(true) ;
                                return disposition[a][b];
                            }
                            else if(b == a+1 && disposition[a-1][b-1].getSelection() = true && disposition[a][b].getSelection() == false){
                                disposition[a][b].setSelection(true) ;
                                return disposition[a][b];
                            }
                            else if(b != 0 && b != a+1){
                                if(disposition[a-1][b-1].getSelection() = true && disposition[a-1][b].getSelection() = true && disposition[a][b].getSelection() == false){
                                    disposition[a][b].setSelection(true) ;
                                    return disposition[a][b];
                                }
                            }

                        }

                    }

                    else if(a == 3){
                            if(b == 0 && disposition[2][b].getSelection() = true && disposition[2][b+1].getSelection() = true && disposition[a][b].getSelection() == false){
                                disposition[a][b].setSelection(true) ;
                                return disposition[a][b];
                            }
                            else if(b == 1 && disposition[2][b+1].getSelection() = true && disposition[2][b+2].getSelection() = true && disposition[a][b].getSelection() == false){
                                disposition[a][b].setSelection(true) ;
                                return disposition[a][b];
                            }

                    }

                    else{
                        if(a == 4 ) {
                            int q = b/2;
                            if(disposition[3][q].getSelection() == true && disposition[a][b].getSelection() == false){
                                disposition[a][b].setSelection(true) ;
                                return disposition[a][b];
                            }
                        }
                        else{
                            if(disposition[a-1][b].getSelection() == true && disposition[a-1][b+1].getSelection() == true && disposition[a][b].getSelection() == false){
                                disposition[a][b].setSelection(true);
                                return disposition[a][b];
                            }
                        }
                    }
                }
            }
        }
    }
}
