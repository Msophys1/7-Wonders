#include <iostream>
#include "GameManager.h"

// Test de la construction  d'un batiment
        Batiment chantier = Batiment(
                "Chantier", // Nom du b�timent
                Types::Premiere, // Type du b�timent
                phase_jeu::AGE_I, // �ge de la carte
                {}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Bois}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment exploitation = Batiment(
                "Exploitation", // Nom du b�timent
                Types::Premiere, // Type du b�timent
                phase_jeu::AGE_I, // �ge de la carte
                {}, // Liste des ressources n�cessaires
                1, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Bois}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment bassin_argileux = Batiment(
                "Bassin argileux", // Nom du b�timent
                Types::Premiere, // Type du b�timent
                phase_jeu::AGE_I, // �ge de la carte
                {}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Argile}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment cavite = Batiment(
                "Cavite", // Nom du b�timent
                Types::Premiere, // Type du b�timent
                phase_jeu::AGE_I, // �ge de la carte
                {}, // Liste des ressources n�cessaires
                1, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Argile}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment gisement = Batiment(
                "Gisement", // Nom du b�timent
                Types::Premiere, // Type du b�timent
                phase_jeu::AGE_I, // �ge de la carte
                {}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Pierre}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment mine = Batiment(
                "Mine", // Nom du b�timent
                Types::Premiere, // Type du b�timent
                phase_jeu::AGE_I, // �ge de la carte
                {}, // Liste des ressources n�cessaires
                1, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Pierre}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment verrerie = Batiment(
                "Verrerie", // Nom du b�timent
                Types::Manufacture, // Type du b�timent
                phase_jeu::AGE_I, // �ge de la carte
                {}, // Liste des ressources n�cessaires
                1, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Verre}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment presse = Batiment(
                "Presse", // Nom du b�timent
                Types::Manufacture, // Type du b�timent
                phase_jeu::AGE_I, // �ge de la carte
                {}, // Liste des ressources n�cessaires
                1, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Verre}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment Tour_de_garde = Batiment(
                "Tour de garde", // Nom du b�timent
                Types::Militaire, // Type du b�timent
                phase_jeu::AGE_I, // �ge de la carte
                {}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Bouclier}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment Atelier = Batiment(
                "Atelier", // Nom du b�timent
                Types::Scientifique, // Type du b�timent
                phase_jeu::AGE_I, // �ge de la carte
                {Ressources::Papyrus}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                1, // Points de victoire
                {Ressources::Compas}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment apothicaire = Batiment(
                "apothicaire", // Nom du b�timent
                Types::Scientifique, // Type du b�timent
                phase_jeu::AGE_I, // �ge de la carte
                {Ressources::Verre}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                1, // Points de victoire
                {Ressources::Roue}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );




        Batiment Ecuries = Batiment(
                "Ecuries", // Nom du b�timent
                Types::Militaire, // Type du b�timent
                phase_jeu::AGE_I, // �ge de la carte
                {Ressources::Bois}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Bouclier}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment caserne = Batiment(
                "Caserne", // Nom du b�timent
                Types::Militaire, // Type du b�timent
                phase_jeu::AGE_I, // �ge de la carte
                {Ressources::Argile}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Bouclier}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment Palissade = Batiment(
                "Palissade", // Nom du b�timent
                Types::Militaire, // Type du b�timent
                phase_jeu::AGE_I, // �ge de la carte
                {}, // Liste des ressources n�cessaires
                2, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Bouclier}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment scriptorium = Batiment(
                "Scriptorium", // Nom du b�timent
                Types::Scientifique, // Type du b�timent
                phase_jeu::AGE_I, // �ge de la carte
                {}, // Liste des ressources n�cessaires
                2, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Plume}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment officine = Batiment(
                "Officine", // Nom du b�timent
                Types::Scientifique, // Type du b�timent
                phase_jeu::AGE_I, // �ge de la carte
                {}, // Liste des ressources n�cessaires
                2, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Pilon}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment theatre = Batiment(
                "Theatre", // Nom du b�timent
                Types::Civil, // Type du b�timent
                phase_jeu::AGE_I, // �ge de la carte
                {}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                3, // Points de victoire
                {}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment autel = Batiment(
                "Autel", // Nom du b�timent
                Types::Civil, // Type du b�timent
                phase_jeu::AGE_I, // �ge de la carte
                {}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                3, // Points de victoire
                {}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );


        Batiment bains = Batiment(
                "Bains", // Nom du b�timent
                Types::Civil, // Type du b�timent
                phase_jeu::AGE_I, // �ge de la carte
                {Ressources::Pierre}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                3, // Points de victoire
                {}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment scierie = Batiment(
                "Scierie", // Nom du b�timent
                Types::Premiere, // Type du b�timent
                phase_jeu::AGE_II, // �ge de la carte
                {}, // Liste des ressources n�cessaires
                2, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Bois,Ressources::Bois}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment briqueterie = Batiment(
                "Briqueterie", // Nom du b�timent
                Types::Premiere, // Type du b�timent
                phase_jeu::AGE_II, // �ge de la carte
                {}, // Liste des ressources n�cessaires
                2, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Argile,Ressources::Argile}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment carriere = Batiment(
                "Carriere", // Nom du b�timent
                Types::Premiere, // Type du b�timent
                phase_jeu::AGE_II, // �ge de la carte
                {}, // Liste des ressources n�cessaires
                2, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Pierre,Ressources::Pierre}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment soufflerie = Batiment(
                "Soufflerie", // Nom du b�timent
                Types::Manufacture, // Type du b�timent
                phase_jeu::AGE_II, // �ge de la carte
                {}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Verre}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment sechoir = Batiment(
                "Sechoir", // Nom du b�timent
                Types::Manufacture, // Type du b�timent
                phase_jeu::AGE_II, // �ge de la carte
                {}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Papyrus}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment muraille = Batiment(
                "Muraille", // Nom du b�timent
                Types::Militaire, // Type du b�timent
                phase_jeu::AGE_II, // �ge de la carte
                {Ressources::Pierre, Ressources::Pierre}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Bouclier, Ressources::Bouclier}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment tribunal = Batiment(
                "Tribunal", // Nom du b�timent
                Types::Civil, // Type du b�timent
                phase_jeu::AGE_II, // �ge de la carte
                {Ressources::Bois, Ressources::Bois, Ressources::Verre}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                5, // Points de victoire
                {}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment haras = Batiment(
                "Haras", // Nom du b�timent
                Types::Militaire, // Type du b�timent
                phase_jeu::AGE_II, // �ge de la carte
                {Ressources::Argile, Ressources::Bois}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Bouclier}, // Liste des ressources produites par le b�timent
                "Ecuries" // B�timent cha�n� (si applicable)
        );

        Batiment baraquements = Batiment(
                "Baraquements", // Nom du b�timent
                Types::Militaire, // Type du b�timent
                phase_jeu::AGE_II, // �ge de la carte
                {}, // Liste des ressources n�cessaires
                3, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Bouclier}, // Liste des ressources produites par le b�timent
                "Caserne" // B�timent cha�n� (si applicable)
        );

        Batiment champ_de_tir = Batiment(
                "Champ de tir", // Nom du b�timent
                Types::Militaire, // Type du b�timent
                phase_jeu::AGE_II, // �ge de la carte
                {Ressources::Pierre, Ressources::Bois, Ressources::Papyrus}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Bouclier, Ressources::Bouclier}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment place_d_armes = Batiment(
                "Place d'arme", // Nom du b�timent
                Types::Militaire, // Type du b�timent
                phase_jeu::AGE_II, // �ge de la carte
                {Ressources::Argile, Ressources::Argile, Ressources::Verre}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Bouclier, Ressources::Bouclier}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment bibliotheque = Batiment(
                "Bibliotheque", // Nom du b�timent
                Types::Scientifique, // Type du b�timent
                phase_jeu::AGE_II, // �ge de la carte
                {Ressources::Pierre, Ressources::Bois, Ressources::Verre}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                2, // Points de victoire
                {Ressources::Plume}, // Liste des ressources produites par le b�timent
                "Scriptorium" // B�timent cha�n� (si applicable)
        );

        Batiment dispensaire = Batiment(
                "Dispensaire", // Nom du b�timent
                Types::Scientifique, // Type du b�timent
                phase_jeu::AGE_II, // �ge de la carte
                {Ressources::Argile, Ressources::Argile, Ressources::Pierre}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                2, // Points de victoire
                {Ressources::Pilon}, // Liste des ressources produites par le b�timent
                "Officine" // B�timent cha�n� (si applicable)
        );

        Batiment ecole = Batiment(
                "Ecole", // Nom du b�timent
                Types::Scientifique, // Type du b�timent
                phase_jeu::AGE_II, // �ge de la carte
                {Ressources::Bois, Ressources::Papyrus, Ressources::Papyrus}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                1, // Points de victoire
                {Ressources::Roue}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment laboratoire = Batiment(
                "Laboratoire", // Nom du b�timent
                Types::Scientifique, // Type du b�timent
                phase_jeu::AGE_II, // �ge de la carte
                {Ressources::Bois, Ressources::Verre, Ressources::Verre}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                1, // Points de victoire
                {Ressources::Compas}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment statue = Batiment(
                "Statue", // Nom du b�timent
                Types::Civil, // Type du b�timent
                phase_jeu::AGE_II, // �ge de la carte
                {Ressources::Argile, Ressources::Argile}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                4, // Points de victoire
                {}, // Liste des ressources produites par le b�timent
                "Theatre" // B�timent cha�n� (si applicable)
        );

        Batiment temple = Batiment(
                "Temple", // Nom du b�timent
                Types::Civil, // Type du b�timent
                phase_jeu::AGE_II, // �ge de la carte
                {Ressources::Bois, Ressources::Papyrus}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                4, // Points de victoire
                {}, // Liste des ressources produites par le b�timent
                "Autel" // B�timent cha�n� (si applicable)
        );

        Batiment aqueduc = Batiment(
                "Aqueduc", // Nom du b�timent
                Types::Civil, // Type du b�timent
                phase_jeu::AGE_II, // �ge de la carte
                {Ressources::Pierre, Ressources::Pierre, Ressources::Pierre}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                5, // Points de victoire
                {}, // Liste des ressources produites par le b�timent
                "Bains" // B�timent cha�n� (si applicable)
        );

        Batiment rostres = Batiment(
                "Rostres", // Nom du b�timent
                Types::Civil, // Type du b�timent
                phase_jeu::AGE_II, // �ge de la carte
                {Ressources::Pierre, Ressources::Bois}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                4, // Points de victoire
                {}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment arsenal = Batiment(
                "Arsenal", // Nom du b�timent
                Types::Militaire, // Type du b�timent
                phase_jeu::AGE_III, // �ge de la carte
                {Ressources::Argile, Ressources::Argile, Ressources::Argile, Ressources::Bois, Ressources::Bois}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Bouclier, Ressources::Bouclier, Ressources::Bouclier}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment pretoire = Batiment(
                "Pretoire", // Nom du b�timent
                Types::Militaire, // Type du b�timent
                phase_jeu::AGE_III, // �ge de la carte
                {}, // Liste des ressources n�cessaires
                8, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Bouclier, Ressources::Bouclier, Ressources::Bouclier}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment academie = Batiment(
                "Academie", // Nom du b�timent
                Types::Scientifique, // Type du b�timent
                phase_jeu::AGE_III, // �ge de la carte
                {Ressources::Pierre, Ressources::Bois, Ressources::Verre, Ressources::Verre}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                3, // Points de victoire
                {Ressources::Cadran}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment etude = Batiment(
                "Etude", // Nom du b�timent
                Types::Scientifique, // Type du b�timent
                phase_jeu::AGE_III, // �ge de la carte
                {Ressources::Bois, Ressources::Bois, Ressources::Verre, Ressources::Papyrus}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                3, // Points de victoire
                {Ressources::Cadran}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment palace = Batiment(
                "Palace", // Nom du b�timent
                Types::Civil, // Type du b�timent
                phase_jeu::AGE_III, // �ge de la carte
                {Ressources::Argile, Ressources::Pierre, Ressources::Bois, Ressources::Verre, Ressources::Verre}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                7, // Points de victoire
                {}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment hotel_de_ville = Batiment(
                "Hotel de ville", // Nom du b�timent
                Types::Civil, // Type du b�timent
                phase_jeu::AGE_III, // �ge de la carte
                {Ressources::Pierre, Ressources::Pierre, Ressources::Pierre, Ressources::Bois, Ressources::Bois}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                7, // Points de victoire
                {}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment obelisque = Batiment(
                "Obelisque", // Nom du b�timent
                Types::Civil, // Type du b�timent
                phase_jeu::AGE_III, // �ge de la carte
                {Ressources::Pierre, Ressources::Pierre, Ressources::Verre}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                5, // Points de victoire
                {}, // Liste des ressources produites par le b�timent
                "" // B�timent cha�n� (si applicable)
        );

        Batiment fortifications = Batiment(
                "Fortifications", // Nom du b�timent
                Types::Militaire, // Type du b�timent
                phase_jeu::AGE_III, // �ge de la carte
                {Ressources::Pierre, Ressources::Pierre, Ressources::Argile, Ressources::Papyrus}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Bouclier, Ressources::Bouclier}, // Liste des ressources produites par le b�timent
                "Palissade" // B�timent cha�n� (si applicable)
        );

        Batiment atelier_de_siege = Batiment(
                "Atelier de siege", // Nom du b�timent
                Types::Militaire, // Type du b�timent
                phase_jeu::AGE_III, // �ge de la carte
                {Ressources::Bois, Ressources::Bois, Ressources::Bois, Ressources::Verre}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Bouclier, Ressources::Bouclier}, // Liste des ressources produites par le b�timent
                "Champ de tir" // B�timent cha�n� (si applicable)
        );

        Batiment crique = Batiment(
                "Cirque", // Nom du b�timent
                Types::Militaire, // Type du b�timent
                phase_jeu::AGE_III, // �ge de la carte
                {Ressources::Argile, Ressources::Argile, Ressources::Pierre, Ressources::Pierre}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                0, // Points de victoire
                {Ressources::Bouclier, Ressources::Bouclier}, // Liste des ressources produites par le b�timent
                "Place d'arme" // B�timent cha�n� (si applicable)
        );

        Batiment universite = Batiment(
                "Universite", // Nom du b�timent
                Types::Scientifique, // Type du b�timent
                phase_jeu::AGE_III, // �ge de la carte
                {Ressources::Argile, Ressources::Verre, Ressources::Papyrus}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                2, // Points de victoire
                {Ressources::Telescope}, // Liste des ressources produites par le b�timent
                "Ecole" // B�timent cha�n� (si applicable)
        );

        Batiment observatoire = Batiment(
                "Observatoire", // Nom du b�timent
                Types::Scientifique, // Type du b�timent
                phase_jeu::AGE_III, // �ge de la carte
                {Ressources::Pierre, Ressources::Papyrus, Ressources::Papyrus}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                2, // Points de victoire
                {Ressources::Telescope}, // Liste des ressources produites par le b�timent
                "Laboratoire" // B�timent cha�n� (si applicable)
        );

        Batiment jardins = Batiment(
                "Jardins", // Nom du b�timent
                Types::Civil, // Type du b�timent
                phase_jeu::AGE_III, // �ge de la carte
                {Ressources::Argile, Ressources::Argile, Ressources::Bois, Ressources::Bois}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                6, // Points de victoire
                {}, // Liste des ressources produites par le b�timent
                "Statue" // B�timent cha�n� (si applicable)
        );

        Batiment pantheon = Batiment(
                "Pantheon", // Nom du b�timent
                Types::Civil, // Type du b�timent
                phase_jeu::AGE_III, // �ge de la carte
                {Ressources::Argile, Ressources::Bois, Ressources::Papyrus, Ressources::Papyrus}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                6, // Points de victoire
                {}, // Liste des ressources produites par le b�timent
                "Temple" // B�timent cha�n� (si applicable)
        );

        Batiment senat = Batiment(
                "Senat", // Nom du b�timent
                Types::Civil, // Type du b�timent
                phase_jeu::AGE_III, // �ge de la carte
                {Ressources::Argile, Ressources::Argile, Ressources::Pierre, Ressources::Papyrus}, // Liste des ressources n�cessaires
                0, // Co�t en argent
                0, // R�compense en argent
                5, // Points de victoire
                {}, // Liste des ressources produites par le b�timent
                "Rostres" // B�timent cha�n� (si applicable)
        );
