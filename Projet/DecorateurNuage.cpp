/**
* \brief  Implementation du decorateur abstrait de base DecorateurNuage.
* \file   DecorateurNuage.cpp
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

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