#include "ConstructeurPolygoneDistance.h"
Position ConstructeurPolygoneDistance::choisirProchainePosition(Position courante, std::list<std::weak_ptr<Point>>& points) const {
    std::list<std::weak_ptr<Point>>::iterator it = points.begin();
    std::list<std::weak_ptr<Point>>::iterator itMinimale = points.begin();
    int distanceMinimale = courante.calculerDistanceCarre((*itMinimale).lock()->obtenirPosition().obtenirPair());
    while (it != points.end()) {
        int distance = courante.calculerDistanceCarre((*it).lock()->obtenirPosition());
        if (distance < distanceMinimale) {
            distanceMinimale = distance;
            itMinimale = it;
        }
        ++it;
    }
    Position sortie = (*itMinimale).lock()->obtenirPosition();
    points.erase(itMinimale);
    return sortie;
}

Position ConstructeurPolygoneDistance::choisirPremier(std::list<std::weak_ptr<Point>>& points) const {
    Position sortie = points.front().lock()->obtenirPosition();
    points.pop_front();
    return sortie;
}