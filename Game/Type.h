//
// Created by Mattéo on 31/03/2024.
//

#ifndef INC_7_WONDERS_TYPE_H
#define INC_7_WONDERS_TYPE_H

enum Ressources { bois, argile, pierre };

enum class JetonsProgres{
    Agriculture, Architecture, Economie, Loi, Maconnerie, Mathematiques,
    Philosophie, Strategie, Theologie, Urbanisme
};

enum class SymboleScientifiques{
    Roue, Compas, Mortier_Pilon, Tablette, Lyre, Mesure, Telescope
};
enum class produitManufacture{
    Verre, Papyrus
};

enum class Types{
    Scientifique, Commerce, Militaire, Civil, Premiere, Manufacture
};
enum class Couleurs{ marron, gris, bleu, vert, jaune, rouge
};

enum class Chainage{
    Livre, Engrenage, Masque, Lune, Eau, Sabot, Epee, Tour, Cible, Chevalier, Lyre, Theiere,
    Soleil, Colonne, Tambour, Vase, Batiment
};

#endif //INC_7_WONDERS_TYPE_H
