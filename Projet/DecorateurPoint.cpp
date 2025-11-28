#include "DecorateurPoint.h"
DecorateurPoint::DecorateurPoint(ComposantPoint* composant) : m_composant(composant){}

std::string DecorateurPoint::obtenirInformation() const{
    return m_composant->obtenirInformation();
}

std::string DecorateurPoint::obtenirTexture() const{
    return m_composant->obtenirTexture();
}

Position DecorateurPoint::obtenirPosition() const{
    return m_composant->obtenirPosition();
}