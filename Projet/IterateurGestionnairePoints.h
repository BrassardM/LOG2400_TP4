#pragma once
#include "Iterateur.h"
#include "Point.h"
#include <map>

class IterateurGestionnairePoints : public Iterateur<Point>{
public:
    IterateurGestionnairePoints(std::map<unsigned int, std::unique_ptr<Point>>& points);
    ~IterateurGestionnairePoints() override = default;
    bool fin() const override;
    Point* obtenirCourant() override; //reference non possessif
    void suivant() override;    
private:
    std::map<unsigned int, std::unique_ptr<Point>>& m_points;
    std::map<unsigned int, std::unique_ptr<Point>>::iterator m_iterateurMappe; 
};