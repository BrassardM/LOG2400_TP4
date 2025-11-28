#include "ConstructeurPolygoneVide.h"

Position ConstructeurPolygoneVide::choisirProchainePosition(Position courante, std::list<Point*>& points) const {
    points = {};
    Position sortie{{0,0}};
    return sortie;
}

Position ConstructeurPolygoneVide::choisirPremier(std::list<Point*>& points) const {
    Position sortie = points.front()->obtenirPosition();
    points.pop_front();
    return sortie;
}