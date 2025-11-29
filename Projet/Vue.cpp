/**
* \brief  Implementation de la Vue.
* \file   Vue.cpp
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#include "Vue.h"
#include "affichage.h"
#include "DecorateurNuageElements.h"
#include "DecorateurNuageTexture.h"
#include "DecorateurPointTexture.h"
#include "DecorateurPointPosition.h"
#include <iostream>

std::string Vue::capturerEntree() const {
    std::string entree;
    std::getline(std::cin, entree);
    return entree;
}

void Vue::afficherCommandePossibles() const{
    std::cout << "\nCommandes:\n"
                  << "a  - Afficher les points et les nuages\n"
                  << "o1 - Afficher l'orthèse avec les textures des points\n"
                  << "o2 - Afficher l'orthèse avec les IDs des points\n"
                  << "f  - Fusionner des points ou des nuages dans un nuage (et appliquer texture)\n"
                  << "d  - Deplacer un point (ID)\n"
                  << "s  - Supprimer un point (ID)\n"
                  << "c1 - Creer les surfaces selon l'ordre des IDs\n"
                  << "c2 - Creer les surfaces selon la distance minimale\n"
                  << "u  - Annuler le dernier deplacement de point ou la dernière suppression de point\n"
                  << "r  - Reappliquer le dernier deplacement de point ou la dernière suppression de point\n"
                  << "q  - Quitter\n> ";
}

void Vue::afficherTableau() const {
    {
        std::unique_ptr<IterateurGestionnairePoints> points = std::move(GestionnairePoints::obtenirInstance()->creerIterateur());
        while (!points->fin()) {
            std::weak_ptr<Point> point = points->obtenirCourant();
            std::shared_ptr<DecorateurPointPosition> pointPosition(std::make_shared<DecorateurPointPosition>(point));
            DecorateurPointTexture pointTexture(pointPosition);
            for (char c : pointTexture.obtenirInformation()){
                switch (c){
                case ('n'):
                    std::cout << '\n';
                    break;
                case ('p'):
                    std::cout << " ";
                    break;
                case ('t'):
                    std::cout << " textures: ";
                    break;
                default:
                    std::cout << c;
                    break;
                }
            } 
            points->suivant();
        }
    }
    {
        std::unique_ptr<Iterateur<NuageDePoints>> nuages = std::move(GestionnaireNuages::obtenirInstance()->creerIterateur());
        while (!nuages->fin()) {
            std::weak_ptr<NuageDePoints> nuage = nuages->obtenirCourant();
            std::shared_ptr<DecorateurNuageTexture> nuageTexture(std::make_shared<DecorateurNuageTexture>(nuage));
            DecorateurNuageElements nuageIds(nuageTexture);
            
            for (char c : nuageIds.obtenirInformation()){
                switch (c){
                case ('n'):
                    std::cout << '\n';
                    break;
                case ('t'):
                    std::cout << " Nuage ";
                    break;
                case ('i'):
                    std::cout << " contient les elements: ";
                    break;
                case (' '):
                    std::cout << ", ";
                default:
                    std::cout << c;
                    break;
                }
            } 
            nuages->suivant();
        }
    }
}

void Vue::afficherGrille() const {
    std::vector<std::vector<char>> grille(HAUTEUR, std::vector<char>(LARGEUR, ' '));
    
    std::unique_ptr<Iterateur<Polygone>> polygones = std::move(GestionnairePolygones::obtenirInstance()->creerIterateur());

    while (!polygones->fin()){
        std::unique_ptr<Iterateur<std::pair<Position,Position>>> iterateurPosition = std::move(polygones->obtenirCourant().lock()->creerIterateur());
        while (!iterateurPosition->fin()){
            std::shared_ptr<std::pair<Position,Position>> positions = iterateurPosition->obtenirCourant().lock();
            std::pair<int,int> premierePosition = positions->first.obtenirPair();
            std::pair<int,int> deuxiemePosition = positions->second.obtenirPair();
            tracerLigne(grille,premierePosition.first, premierePosition.second, deuxiemePosition.first,deuxiemePosition.second);
            iterateurPosition->suivant();
        }
        polygones->suivant();
    }

    m_strategie->insererPoints(grille,std::move(GestionnairePoints::obtenirInstance()->creerIterateur()));
    
    // On imprime la grille.
    for (int y = HAUTEUR - 1; y >= 0; --y) {
        for (int x = 0; x < LARGEUR; ++x)
            std::cout << grille[y][x];
        std::cout << '\n';
    }
}

void Vue::changerStrategie(std::unique_ptr<StrategieAfficher> strategie){
    m_strategie = std::move(strategie);
}

void Vue::afficherCommandeInvalide() const{
    std::cout << "Commande Invalide : Une erreur c'est produite!\n";
}

void Vue::afficherReapplicationImpossible() const{
    std::cout << "Impossible de faire la reapplication, est-ce que la derniere commande etait 'u'?\n";
}

void Vue::afficherAnnulerImpossible() const{
    std::cout << "Impossible d'annuler, est-ce que la derniere commande non-affichante etait 's' ou 'd'?\n";
}

void Vue::afficherNuageRequete() const{
    std::cout << "IDs des points a fusionner dans un nuage (ex : 0 2 4): ";
}

void Vue::afficherIDRequeteDeplacer() const{
    std::cout << "ID du point a deplacer: ";
}

void Vue::afficherPositionRequete() const{
    std::cout << "Nouvelle position \"x y\": ";
}

void Vue::afficherIDRequeteSupprimer() const{
    std::cout << "ID du point a supprimer: ";
}