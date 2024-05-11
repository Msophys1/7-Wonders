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
// créer un type chainage ? enum ou enum class / dans type ou dans carte ou les deux ?
#endif //INC_7_WONDERS_TYPE_H
