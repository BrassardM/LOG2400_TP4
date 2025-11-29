/**
* \brief  Classe representant un decorateur concret du patron decorateur permettant
* d'ajouter la position d'un point a ces informations disponibles.
* \file   DecorateurPointPosition.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#pragma once
#include "DecorateurPoint.h"
class DecorateurPointPosition : public DecorateurPoint {
public:
    DecorateurPointPosition(std::weak_ptr<ComposantPoint> composant);
    ~DecorateurPointPosition() = default;
    
    std::string obtenirInformation() const override;
};