#pragma once
#include "StrategieAfficher.h"
class StrategieAfficherTexture : public StrategieAfficher {
public:
    StrategieAfficherTexture() = default;
    ~StrategieAfficherTexture() override = default;
    void insererPoints(std::vector<std::vector<char>>& grille, std::unique_ptr<Iterateur<Point>> points) const override;
};