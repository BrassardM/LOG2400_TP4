/**
* \brief  Classe representant une strategie concrete du patron strategie, permettant
* d'afficher les points avec leurs textures.
* \file   StrategieAfficherTexture.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#pragma once
#include "StrategieAfficher.h"
class StrategieAfficherTexture : public StrategieAfficher {
public:
    StrategieAfficherTexture() = default;
    ~StrategieAfficherTexture() override = default;
    void insererPoints(std::vector<std::vector<char>>& grille, std::unique_ptr<Iterateur<Point>> points) const override;
};