#include "ConstructeurPolygoneVide.h"

Position ConstructeurPolygoneVide::choisirProchainePosition(Position courante, std::list<std::weak_ptr<Point>>& points) const {
    points = {};
    Position sortie{{0,0}};
    return sortie;
}

Position ConstructeurPolygoneVide::choisirPremier(std::list<std::weak_ptr<Point>>& points) const {
    Position sortie = points.front().lock()->obtenirPosition();
    points.pop_front();
    return sortie;
}