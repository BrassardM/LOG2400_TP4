#include "DecorateurNuageTexture.h"
DecorateurNuageTexture::DecorateurNuageTexture(std::weak_ptr<ComposantNuage> composant) : DecorateurNuage(composant) {}

std::string DecorateurNuageTexture::obtenirInformation() const {
    return  m_composant.lock()->obtenirInformation() + "t" + '\''+ obtenirTexture() + '\'';
}