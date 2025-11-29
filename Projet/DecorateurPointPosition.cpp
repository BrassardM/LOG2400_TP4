/**
* \brief  Implementation du decorateur concret DecorateurPointPosition.
* \file   DecorateurPointPosition.cpp
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#include "DecorateurPointPosition.h"
DecorateurPointPosition::DecorateurPointPosition(std::weak_ptr<ComposantPoint> composant) : DecorateurPoint(composant) {}

std::string DecorateurPointPosition::obtenirInformation() const {
    std::pair<int,int> position = obtenirPosition().obtenirPair();
    return  m_composant.lock()->obtenirInformation() + "p" + "(" + std::to_string(position.first) + "," + std::to_string(position.second) + ")";
}