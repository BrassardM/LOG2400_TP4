/**
* \brief  Classe representant une commande concrete du patron 
* commande permettant de supprimer un point.
* \file   Composant.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#pragma once
#include <string>
class Composant{
public:
    virtual std::string obtenirInformation() const = 0;
    virtual std::string obtenirTexture() const = 0;
};