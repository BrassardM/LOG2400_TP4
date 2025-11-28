#pragma once
#include "ConstructeurPolygone.h"
class ConstructeurPolygoneDistance : public ConstructeurPolygone {
public:
    ConstructeurPolygoneDistance() = default;
    ~ConstructeurPolygoneDistance() override = default;
protected:
    Position choisirProchainePosition(Position courante, std::list<Point*>& points) const override; 
    Position choisirPremier(std::list<Point*>& points) const override;
};