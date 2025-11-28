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