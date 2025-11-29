/**
* \brief  Classe representant un IterateurConcret du patron iterateur pour le GestionnairePoints 
* permettant d'iterer sur les points sans exposer la structure.
* \file   IterateurGestionnairePoints.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

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