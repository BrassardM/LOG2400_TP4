/**
* \brief  Implementation de la classe cadre d'application ConstructeurPolygone. 
* \file   ConstructeurPolygone.cpp
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#include "ConstructeurPolygone.h"
#include <vector>

std::shared_ptr<Polygone> ConstructeurPolygone::creerPolygone(std::list<std::weak_ptr<Point>> points) const{
    std::vector<Position> sommets;

    Position courante = choisirPremier(points);
    sommets.push_back(courante);
    
    while (points.size() > 0) {
        courante = choisirProchainePosition(courante, points);
        sommets.push_back(courante);
    } 

    if (sommets.size() <= 1) {
        return nullptr;
    }
    else {
        return std::move(std::make_unique<Polygone>(sommets));
    }
}