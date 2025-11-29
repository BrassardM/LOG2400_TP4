/**
* \brief  Implementation du decorateur concret DecorateurNuageTexture.
* \file   DecorateurNuageTexture.cpp
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#include "DecorateurNuageTexture.h"
DecorateurNuageTexture::DecorateurNuageTexture(std::weak_ptr<ComposantNuage> composant) : DecorateurNuage(composant) {}

std::string DecorateurNuageTexture::obtenirInformation() const {
    return  m_composant.lock()->obtenirInformation() + "t" + '\''+ obtenirTexture() + '\'';
}