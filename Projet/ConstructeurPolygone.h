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