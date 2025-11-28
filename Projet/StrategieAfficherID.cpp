#include "StrategieAfficherID.h"
#include "affichage.h"
void StrategieAfficherID::insererPoints(std::vector<std::vector<char>>& grille, std::unique_ptr<Iterateur<Point>> points) const {
    while (!points->fin()){
        Point* point = points->obtenirCourant();
        std::pair<int,int> position = point->obtenirPosition().obtenirPair();
        if (position.first < HAUTEUR && position.first >= 0 && position.second < LARGEUR && position.second >= 0){
            std::string nombre = std::to_string(point->obtenirId());
            for (int i{}; i < nombre.size(); i++){
                if (position.first + i > LARGEUR) {
                    break;
                }
                grille[position.second][position.first + i] = nombre[i];   
            } 
        }
        points->suivant();
    }
}