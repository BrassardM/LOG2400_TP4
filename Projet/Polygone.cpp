/**
* \brief  Implementation de la classe Polygone.
* \file   Polygone.cpp
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#include "Polygone.h"
Polygone::Polygone(const std::vector<Position>& sommets) : m_sommets(sommets) {}

std::unique_ptr<IterateurPolygonePairPosition> Polygone::creerIterateur() {
    return std::move(std::make_unique<IterateurPolygonePairPosition>(m_sommets));
}