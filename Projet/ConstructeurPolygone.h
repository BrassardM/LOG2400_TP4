#pragma once
#include <list>
#include "Point.h"
#include "Polygone.h"
class ConstructeurPolygone{
public:
    ConstructeurPolygone() = default;
    virtual ~ConstructeurPolygone() = default;

    std::unique_ptr<Polygone> creerPolygone(std::list<Point*> points) const;
protected:
    virtual Position choisirProchainePosition(Position courante, std::list<Point*>& points) const = 0; 
    virtual Position choisirPremier(std::list<Point*>& points) const = 0;
};