#include "Point.h"

Point::Point(const std::pair<int,int>& position) : m_retire(false), m_position{position} {}

void Point::ajouterTexture(Texture* texture) {
    m_textures.push_back(texture);
}

void Point::retirerTexture(Texture* texture){
    m_textures.remove(texture);
}

void Point::retirer(){
    m_retire = true;
    Element::retirer();
}

void Point::annulerRetire(){
    m_retire = false;
    Element::annulerRetire();
}

bool Point::estRetire() const {
    return m_retire;
}

void Point::changerPosition(const std::pair<int,int>& position) {
    m_position.changerPosition(position);
}

Position Point::obtenirPosition() const {
    return m_position;
}

std::list<Point*> Point::obtenirPoints() {
    return {this};
}

std::string Point::obtenirInformation() const{
    return "n" + std::to_string(obtenirId()) + ':';
}

std::string Point::obtenirTexture() const {
    std::string out;
    for (Texture* texture : m_textures) {
        out += texture->obtenirCharactere();
    }
    return out;
}
