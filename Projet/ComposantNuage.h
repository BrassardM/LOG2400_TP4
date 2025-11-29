/**
* \brief  Classe representant l'interface d'un composant de type nuage
* abstrait du patron Decorateur.
* \file   ComposantNuage.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#pragma once
#include "Composant.h"
#include <vector>
class ComposantNuage : public Composant{
public:
    virtual std::vector<int> obtenirIDElements() const = 0;
};