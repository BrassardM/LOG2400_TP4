/**
* \brief  Classe representant un decorateur concret du patron decorateur permettant
* d'ajouter la texture d'un nuage a ces informations disponibles.
* \file   DecorateurNuageTexture.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#pragma once
#include "DecorateurNuage.h"
class DecorateurNuageTexture : public DecorateurNuage {
public:
    DecorateurNuageTexture(std::weak_ptr<ComposantNuage> composant);
    ~DecorateurNuageTexture() = default;
    
    std::string obtenirInformation() const override;
};