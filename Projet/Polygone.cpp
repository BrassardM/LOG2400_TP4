#include "Polygone.h"
Polygone::Polygone(const std::vector<Position>& sommets) : m_sommets(sommets) {}

std::unique_ptr<IterateurPolygonePairPosition> Polygone::creerIterateur() {
    return std::move(std::make_unique<IterateurPolygonePairPosition>(m_sommets));
}