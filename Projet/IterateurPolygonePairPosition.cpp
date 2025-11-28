#include "IterateurPolygonePairPosition.h"
IterateurPolygonePairPosition::IterateurPolygonePairPosition(std::vector<Position>& positions) : m_positions(positions), m_indexPremier(0), m_indexDeuxieme(1) {
    m_courant = std::make_unique<std::pair<Position,Position>>(m_positions[m_indexPremier], m_positions[m_indexDeuxieme % m_positions.size()]);
}

bool IterateurPolygonePairPosition::fin() const {
    return m_indexPremier > m_positions.size() || (m_positions.size() <= 1);
}

std::pair<Position,Position>* IterateurPolygonePairPosition::obtenirCourant() { 
    return m_courant.get();
}

void IterateurPolygonePairPosition::suivant(){
    m_courant = std::make_unique<std::pair<Position,Position>>(m_positions[m_indexPremier], m_positions[m_indexDeuxieme % m_positions.size()]);
    m_indexPremier++;
    m_indexDeuxieme++;
}