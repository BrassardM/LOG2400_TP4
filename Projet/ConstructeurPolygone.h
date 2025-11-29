/**
* \brief  Classe abstraite representant le cadre d'application du patron
* de methode. 
* \file   ConstructeurPolygone.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#pragma once
#include <list>
#include "Point.h"
#include "Polygone.h"
class ConstructeurPolygone{
public:
    ConstructeurPolygone() = default;
    virtual ~ConstructeurPolygone() = default;

    std::shared_ptr<Polygone> creerPolygone(std::list<std::weak_ptr<Point>> points) const;
protected:
    virtual Position choisirProchainePosition(Position courante, std::list<std::weak_ptr<Point>>& points) const = 0; 
    virtual Position choisirPremier(std::list<std::weak_ptr<Point>>& points) const = 0;
};