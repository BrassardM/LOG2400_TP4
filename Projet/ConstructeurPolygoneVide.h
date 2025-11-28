#pragma once
#include "ConstructeurPolygone.h"
class ConstructeurPolygoneVide : public ConstructeurPolygone {
public:
    ConstructeurPolygoneVide() = default;
    ~ConstructeurPolygoneVide() override = default;
protected:
    Position choisirProchainePosition(Position courante, std::list<Point*>& points) const override; 
    Position choisirPremier(std::list<Point*>& points) const override;
};