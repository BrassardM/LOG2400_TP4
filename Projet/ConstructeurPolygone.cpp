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