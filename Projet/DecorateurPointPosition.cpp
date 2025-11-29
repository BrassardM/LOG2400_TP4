#include "DecorateurPointPosition.h"
DecorateurPointPosition::DecorateurPointPosition(std::weak_ptr<ComposantPoint> composant) : DecorateurPoint(composant) {}

std::string DecorateurPointPosition::obtenirInformation() const {
    std::pair<int,int> position = obtenirPosition().obtenirPair();
    return  m_composant.lock()->obtenirInformation() + "p" + "(" + std::to_string(position.first) + "," + std::to_string(position.second) + ")";
}