#include "DecorateurNuage.h"
DecorateurNuage::DecorateurNuage(ComposantNuage* composant) : m_composant(composant) {}

std::string DecorateurNuage::obtenirInformation() const {
    return m_composant->obtenirInformation();
}

std::string DecorateurNuage::obtenirTexture() const {
    return m_composant->obtenirTexture();
}

std::vector<int> DecorateurNuage::obtenirIDElements() const {
    return m_composant->obtenirIDElements();
}