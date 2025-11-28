#pragma once
#include "IterateurPolygonePairPosition.h"

class Polygone{
public:
    Polygone(const std::vector<Position>& sommets);
    ~Polygone() = default;

    std::unique_ptr<IterateurPolygonePairPosition> creerIterateur();
private:
    std::vector<Position> m_sommets;
};