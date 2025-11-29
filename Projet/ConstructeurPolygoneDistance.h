/** 
* \brief  Classe concrete representant l'implementation specifique du
* patron de methode permettant de construire les polygones par rapport
* a leur distance l'un de l'autre.
* \file   ConstructeurPolygoneDistance.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#pragma once
#include "ConstructeurPolygone.h"
class ConstructeurPolygoneDistance : public ConstructeurPolygone {
public:
    ConstructeurPolygoneDistance() = default;
    ~ConstructeurPolygoneDistance() override = default;
protected:
    Position choisirProchainePosition(Position courante, std::list<std::weak_ptr<Point>>& points) const override; 
    Position choisirPremier(std::list<std::weak_ptr<Point>>& points) const override;
};