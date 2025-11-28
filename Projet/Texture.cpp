#include "Texture.h"

Texture::Texture(char charactere) : m_charactere{charactere} {}

char Texture::obtenirCharactere() const {
    return m_charactere;
}

void Texture::changerCharactere(char charactere) {
    m_charactere = charactere;
}