/**
* \brief  Classe representant l'interface d'un composant de type point
* abstrait du patron Decorateur.
* \file   ComposantPoint.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#pragma once
#include "Position.h"
#include "Composant.h"
class ComposantPoint : public Composant{
public:
    virtual Position obtenirPosition() const = 0;
};