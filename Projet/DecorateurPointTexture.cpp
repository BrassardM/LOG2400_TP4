#include "DecorateurPointTexture.h"
DecorateurPointTexture::DecorateurPointTexture(std::weak_ptr<ComposantPoint> composant) : DecorateurPoint(composant) {}

std::string DecorateurPointTexture::obtenirInformation() const {
    return  m_composant.lock()->obtenirInformation() + "t" + '\''+ obtenirTexture() + '\'';
}