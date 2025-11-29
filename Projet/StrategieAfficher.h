/**
* \brief  Classe abstraite representant la strategie abstraite du patron strategie. 
* \file   StrategieAfficher.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#pragma once
#include "Point.h"
#include "Polygone.h"
#include "Iterateur.h"
class StrategieAfficher{
public:
    StrategieAfficher() = default;
    virtual ~StrategieAfficher() = default;

    virtual void insererPoints(std::vector<std::vector<char>>& grille, std::unique_ptr<Iterateur<Point>> points) const = 0;
};