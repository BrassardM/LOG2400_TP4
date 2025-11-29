#include "ConstructeurPolygoneID.h"

Position ConstructeurPolygoneID::choisirProchainePosition(Position courante, std::list<std::weak_ptr<Point>>& points) const {
    std::list<std::weak_ptr<Point>>::iterator it = points.begin();
    std::list<std::weak_ptr<Point>>::iterator itMinimale = points.begin();
    int idMinimale = (*itMinimale).lock()->obtenirId();
    while (it != points.end()){
        int id = (*it).lock()->obtenirId();
        if (id < idMinimale){
            idMinimale = id;
            itMinimale = it;
        }
        ++it;
    }

    Position sortie = (*itMinimale).lock()->obtenirPosition();
    points.erase(itMinimale);
    return sortie;
}

Position ConstructeurPolygoneID::choisirPremier(std::list<std::weak_ptr<Point>>& points) const {
    std::list<std::weak_ptr<Point>>::iterator it = points.begin();
    std::list<std::weak_ptr<Point>>::iterator itMinimale = points.begin();
    int idMinimale = (*itMinimale).lock()->obtenirId();
    while (it != points.end()){
        int id = (*it).lock()->obtenirId();
        if (id < idMinimale){
            idMinimale = id;
            itMinimale = it;
        }
        ++it;
    }

    Position sortie = (*itMinimale).lock()->obtenirPosition();
    points.erase(itMinimale);
    return sortie;
}