#pragma once
#include "ConstructeurPolygone.h"
class ConstructeurPolygoneVide : public ConstructeurPolygone {
public:
    ConstructeurPolygoneVide() = default;
    ~ConstructeurPolygoneVide() override = default;
protected:
    Position choisirProchainePosition(Position courante, std::list<std::weak_ptr<Point>>& points) const override; 
    Position choisirPremier(std::list<std::weak_ptr<Point>>& points) const override;
};