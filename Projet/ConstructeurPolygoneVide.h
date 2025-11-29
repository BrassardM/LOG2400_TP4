/**
* \brief  Classe concrete representant l'implementation specifique du
* patron de methode permettant de ne pas construire de polygone.
* \file   ConstructeurPolygoneVide.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#pragma once
#include "ConstructeurPolygone.h"
class ConstructeurPolygoneVide : public ConstructeurPolygone {
public:
    ConstructeurPolygoneVide() = default;
    ~ConstructeurPolygoneVide() override = default;
protected:
    Position choisirProchainePosition(Position courante, std::list<std::weak_ptr<Point>>& points) const override; 
    Position choisirPremier(std::list<std::weak_ptr<Point>>& points) const override;
};