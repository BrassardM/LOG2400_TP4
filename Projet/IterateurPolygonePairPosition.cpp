/**
* \brief  Implementation de l'iterateur concret iterateur polygone pair position.
* \file   IterateurPolygonePairPosition.cpp
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#include "IterateurPolygonePairPosition.h"
IterateurPolygonePairPosition::IterateurPolygonePairPosition(std::vector<Position>& positions) : m_positions(positions), m_indexPremier(0), m_indexDeuxieme(1) {
    m_courant = std::make_unique<std::pair<Position,Position>>(m_positions[m_indexPremier], m_positions[m_indexDeuxieme % m_positions.size()]);
}

bool IterateurPolygonePairPosition::fin() const {
    return m_indexPremier > m_positions.size() || (m_positions.size() <= 1);
}

std::weak_ptr<std::pair<Position,Position>> IterateurPolygonePairPosition::obtenirCourant() { 
    return m_courant;
}

void IterateurPolygonePairPosition::suivant(){
    m_courant = std::make_shared<std::pair<Position,Position>>(m_positions[m_indexPremier], m_positions[m_indexDeuxieme % m_positions.size()]);
    m_indexPremier++;
    m_indexDeuxieme++;
}