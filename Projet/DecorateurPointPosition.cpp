#include "DecorateurPointPosition.h"
DecorateurPointPosition::DecorateurPointPosition(ComposantPoint* composant) : DecorateurPoint(composant) {}

std::string DecorateurPointPosition::obtenirInformation() const {
    std::pair<int,int> position = obtenirPosition().obtenirPair();
    return  m_composant->obtenirInformation() + "p" + "(" + std::to_string(position.first) + "," + std::to_string(position.second) + ")";
}