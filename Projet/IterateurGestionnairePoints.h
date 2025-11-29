#pragma once
#include "Iterateur.h"
#include "Point.h"
#include <map>

class IterateurGestionnairePoints : public Iterateur<Point>{
public:
    IterateurGestionnairePoints(std::map<unsigned int, std::shared_ptr<Point>>& points);
    ~IterateurGestionnairePoints() override = default;
    bool fin() const override;
    std::weak_ptr<Point> obtenirCourant() override; //reference non possessif
    void suivant() override;    
private:
    std::map<unsigned int, std::shared_ptr<Point>>& m_points;
    std::map<unsigned int, std::shared_ptr<Point>>::iterator m_iterateurMappe; 
};