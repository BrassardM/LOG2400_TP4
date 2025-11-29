/**
* \brief  Classe qui est une collection de positions representants les sommets d'un polygone, 
* ordonne selon les arcs, cette classe est un aggregat du patron iterateur. 
* \file   Polygone.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

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