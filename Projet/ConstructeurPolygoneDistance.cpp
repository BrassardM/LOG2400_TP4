#include "ConstructeurPolygoneDistance.h"
Position ConstructeurPolygoneDistance::choisirProchainePosition(Position courante, std::list<Point*>& points) const {
    std::list<Point*>::iterator it = points.begin();
    std::list<Point*>::iterator itMinimale = points.begin();
    int distanceMinimale = courante.calculerDistanceCarre((*itMinimale)->obtenirPosition().obtenirPair());
    while (it != points.end()) {
        int distance = courante.calculerDistanceCarre((*it)->obtenirPosition());
        if (distance < distanceMinimale) {
            distanceMinimale = distance;
            itMinimale = it;
        }
        ++it;
    }
    Position sortie = (*itMinimale)->obtenirPosition();
    points.erase(itMinimale);
    return sortie;
}

Position ConstructeurPolygoneDistance::choisirPremier(std::list<Point*>& points) const {
    Position sortie = points.front()->obtenirPosition();
    points.pop_front();
    return sortie;
}