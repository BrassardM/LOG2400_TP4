#include "DecorateurNuage.h"
DecorateurNuage::DecorateurNuage(std::weak_ptr<ComposantNuage> composant) : m_composant(composant) {}

std::string DecorateurNuage::obtenirInformation() const {
    return m_composant.lock()->obtenirInformation();
}

std::string DecorateurNuage::obtenirTexture() const {
    return m_composant.lock()->obtenirTexture();
}

std::vector<int> DecorateurNuage::obtenirIDElements() const {
    return m_composant.lock()->obtenirIDElements();
}