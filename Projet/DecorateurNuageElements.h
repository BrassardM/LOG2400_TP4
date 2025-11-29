/**
* \brief  Classe representant un decorateur concret du patron decorateur permettant
* d'ajouter les ids des composants d'un nuage a ces informations disponibles.
* \file   DecorateurNuageElements.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#pragma once
#include "DecorateurNuage.h"
class DecorateurNuageElements : public DecorateurNuage {
public:
    DecorateurNuageElements(std::weak_ptr<ComposantNuage> composant);
    ~DecorateurNuageElements() = default;
    
    std::string obtenirInformation() const override;
};