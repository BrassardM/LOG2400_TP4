/**
* \brief  Implementation de NuageDePoints.
* \file   NuageDePoints.cpp
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#include "NuageDePoints.h"
#include "Point.h"
NuageDePoints::NuageDePoints(const std::list<std::weak_ptr<Element>>& elements, char texture) : m_elements{elements}, m_elementRetire{0,{}}, m_texture(std::make_shared<Texture>(texture)) {
    for (std::weak_ptr<Element> element : m_elements){
        for (std::weak_ptr<Point> point : element.lock()->obtenirPoints()){
            point.lock()->ajouterTexture(m_texture);
        }
    }
}

std::list<std::weak_ptr<Point>> NuageDePoints::obtenirPoints(){
    std::list<std::weak_ptr<Point>> points = {};
    for (std::weak_ptr<Element> element : m_elements)
        points.splice(points.end(),element.lock()->obtenirPoints());
    return points;
}

void NuageDePoints::restaurerElement(){
    std::shared_ptr<Element> elementRestaurer = m_elementRetire.second.lock();
    if (elementRestaurer != nullptr && !(elementRestaurer->estRetire())) {
        auto it = m_elements.begin();
        std::advance(it,m_elementRetire.first);
        m_elements.emplace(it,m_elementRetire.second);
        elementRestaurer->ajouterTexture(m_texture);
        m_elementRetire = {0,{}};
    }
}

void NuageDePoints::retirerPointInvalide(){
    int indexElement{};
    bool found = false;
    for (auto it = m_elements.begin(); it != m_elements.end(); ++it) {
        std::shared_ptr<Element> element = (*it).lock();
        if (element->estRetire()){
            m_elementRetire = {indexElement,element};
            element->retirerTexture(m_texture);
            m_elements.erase(it);
            found = true;
            break;
        }
        indexElement++;
    }
    if (!found){
        m_elementRetire = {0,{}};
    }
}

std::string NuageDePoints::obtenirInformation() const{
    return "n" +std::to_string(obtenirId()) + ":";
}

std::string NuageDePoints::obtenirTexture() const {
    return std::string{m_texture->obtenirCharactere()};
}

std::vector<int> NuageDePoints::obtenirIDElements() const {
    std::vector<int> sortie;
    for (std::weak_ptr<Element> element : m_elements) {
        sortie.push_back(element.lock()->obtenirId());
    }
    return sortie;
}