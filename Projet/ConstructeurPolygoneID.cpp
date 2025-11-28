#include "ConstructeurPolygoneID.h"

Position ConstructeurPolygoneID::choisirProchainePosition(Position courante, std::list<Point*>& points) const {
    std::list<Point*>::iterator it = points.begin();
    std::list<Point*>::iterator itMinimale = points.begin();
    int idMinimale = (*itMinimale)->obtenirId();
    while (it != points.end()){
        int id = (*it)->obtenirId();
        if (id < idMinimale){
            idMinimale = id;
            itMinimale = it;
        }
        ++it;
    }

    Position sortie = (*itMinimale)->obtenirPosition();
    points.erase(itMinimale);
    return sortie;
}

Position ConstructeurPolygoneID::choisirPremier(std::list<Point*>& points) const {
    std::list<Point*>::iterator it = points.begin();
    std::list<Point*>::iterator itMinimale = points.begin();
    int idMinimale = (*itMinimale)->obtenirId();
    while (it != points.end()){
        int id = (*it)->obtenirId();
        if (id < idMinimale){
            idMinimale = id;
            itMinimale = it;
        }
        ++it;
    }

    Position sortie = (*itMinimale)->obtenirPosition();
    points.erase(itMinimale);
    return sortie;
}