#include "DecorateurPoint.h"
DecorateurPoint::DecorateurPoint(std::weak_ptr<ComposantPoint> composant) : m_composant(composant){}

std::string DecorateurPoint::obtenirInformation() const{
    return m_composant.lock()->obtenirInformation();
}

std::string DecorateurPoint::obtenirTexture() const{
    return m_composant.lock()->obtenirTexture();
}

Position DecorateurPoint::obtenirPosition() const{
    return m_composant.lock()->obtenirPosition();
}