#include "DecorateurPointTexture.h"
DecorateurPointTexture::DecorateurPointTexture(ComposantPoint* composant) : DecorateurPoint(composant) {}

std::string DecorateurPointTexture::obtenirInformation() const {
    return  m_composant->obtenirInformation() + "t" + '\''+ obtenirTexture() + '\'';
}