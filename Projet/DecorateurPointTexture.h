/**
* \brief  Classe representant un decorateur concret du patron decorateur permettant
* d'ajouter les textures d'un point a ces informations disponibles.
* \file   DecorateurPointTexture.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#pragma once
#include "DecorateurPoint.h"
class DecorateurPointTexture : public DecorateurPoint {
public:
    DecorateurPointTexture(std::weak_ptr<ComposantPoint> composant);
    ~DecorateurPointTexture() = default;
    
    std::string obtenirInformation() const override;
};