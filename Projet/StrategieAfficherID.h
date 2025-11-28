#pragma once
#include "StrategieAfficher.h"

class StrategieAfficherID : public StrategieAfficher {
public:
    StrategieAfficherID() = default;
    ~StrategieAfficherID() override = default;
    void insererPoints(std::vector<std::vector<char>>& grille, std::unique_ptr<Iterateur<Point>> points) const override;
};