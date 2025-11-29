#pragma once
#include "ConstructeurPolygone.h"
class ConstructeurPolygoneID : public ConstructeurPolygone {
public:
    ConstructeurPolygoneID() = default;
    ~ConstructeurPolygoneID() override = default;
protected:
    Position choisirProchainePosition(Position courante, std::list<std::weak_ptr<Point>>& points) const override; 
    Position choisirPremier(std::list<std::weak_ptr<Point>>& points) const override;
};