/**
* \brief  Implementation du decorateur concret DecorateurPointTexture.
* \file   DecorateurPointTexture.cpp
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#include "DecorateurPointTexture.h"
DecorateurPointTexture::DecorateurPointTexture(std::weak_ptr<ComposantPoint> composant) : DecorateurPoint(composant) {}

std::string DecorateurPointTexture::obtenirInformation() const {
    return  m_composant.lock()->obtenirInformation() + "t" + '\''+ obtenirTexture() + '\'';
}