#include "DecorateurNuageTexture.h"
DecorateurNuageTexture::DecorateurNuageTexture(ComposantNuage* composant) : DecorateurNuage(composant) {}

std::string DecorateurNuageTexture::obtenirInformation() const {
    return  m_composant->obtenirInformation() + "t" + '\''+ obtenirTexture() + '\'';
}