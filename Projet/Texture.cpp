/**
* \brief  Implementation de texture.
* \file   Texture.cpp
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#include "Texture.h"

Texture::Texture(char charactere) : m_charactere{charactere} {}

char Texture::obtenirCharactere() const {
    return m_charactere;
}

void Texture::changerCharactere(char charactere) {
    m_charactere = charactere;
}