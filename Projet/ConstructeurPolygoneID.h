#pragma once
#include "ConstructeurPolygone.h"
class ConstructeurPolygoneID : public ConstructeurPolygone {
public:
    ConstructeurPolygoneID() = default;
    ~ConstructeurPolygoneID() override = default;
protected:
    Position choisirProchainePosition(Position courante, std::list<Point*>& points) const override; 
    Position choisirPremier(std::list<Point*>& points) const override;
};