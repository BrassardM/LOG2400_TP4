/**
* \brief  Implementation de point.
* \file   Point.cpp
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#include "Point.h"

Point::Point(const std::pair<int,int>& position) : m_retire(false), m_position{position} {}

void Point::ajouterTexture(std::weak_ptr<Texture> texture) {
    m_textures.push_back(texture);
}

void Point::retirerTexture(std::weak_ptr<Texture> texture){
    for (auto it = m_textures.begin(); it != m_textures.end(); ++it){
        if (texture.lock() == it->lock()) {
            m_textures.erase(it);
            break;
        }
    }
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

std::list<std::weak_ptr<Point>> Point::obtenirPoints() {
    std::weak_ptr<Point> self = shared_from_this();
    return {self};
}

std::string Point::obtenirInformation() const{
    return "n" + std::to_string(obtenirId()) + ':';
}

std::string Point::obtenirTexture() const {
    std::string out;
    for (std::weak_ptr<Texture> texture : m_textures) {
        out += texture.lock()->obtenirCharactere();
    }
    return out;
}
