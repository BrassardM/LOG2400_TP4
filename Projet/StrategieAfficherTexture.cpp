/**
* \brief  Implementation de la strategie concrete StrategieAfficherTexture.
* \file   StrategieAfficherTexture.cpp
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#include "StrategieAfficherTexture.h"
#include "affichage.h"
void StrategieAfficherTexture::insererPoints(std::vector<std::vector<char>>& grille, std::unique_ptr<Iterateur<Point>> points) const {
    while (!points->fin()){
        std::shared_ptr<Point> point = points->obtenirCourant().lock();
        std::pair<int,int> position = point->obtenirPosition().obtenirPair();
        if (position.first < HAUTEUR && position.first >= 0 && position.second < LARGEUR && position.second >= 0){
            std::string texture = point->obtenirTexture();
            if (texture.empty()){
                texture = '.';
            }
            for (int i{}; i < texture.size(); i++){
                if (position.first + i > LARGEUR) {
                    break;
                }
                grille[position.second][position.first + i] = texture[i];   
            } 
        }
        points->suivant();
    }
}