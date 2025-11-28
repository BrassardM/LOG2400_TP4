#include "NuageDePoints.h"
#include "Point.h"
NuageDePoints::NuageDePoints(const std::list<Element*>& elements, char texture) : m_elements{elements}, m_elementRetire{0,nullptr}, m_texture(std::make_unique<Texture>(texture)) {
    Texture* textureNonPossessif = m_texture.get();
    for (Element* element : m_elements){
        for (Point* point : element->obtenirPoints()){
            point->ajouterTexture(textureNonPossessif);
        }
    }
}

std::list<Point*> NuageDePoints::obtenirPoints(){
    std::list<Point*> points = {};
    for (Element* element : m_elements)
        points.splice(points.end(),element->obtenirPoints());
    return points;
}

void NuageDePoints::restaurerElement(){
    if (m_elementRetire.second != nullptr && !(m_elementRetire.second->estRetire())) {
        auto it = m_elements.begin();
        std::advance(it,m_elementRetire.first);
        m_elements.emplace(it,m_elementRetire.second);
        m_elementRetire.second->ajouterTexture(m_texture.get());
        m_elementRetire = {0,nullptr};
    }
}

void NuageDePoints::retirerPointInvalide(){
    int indexElement{};
    bool found = false;
    for (auto it = m_elements.begin(); it != m_elements.end(); ++it) {
        Element* element = (*it);
        if (element->estRetire()){
            m_elementRetire = {indexElement,element};
            element->retirerTexture(m_texture.get());
            m_elements.erase(it);
            found = true;
            break;
        }
        indexElement++;
    }
    if (!found){
        m_elementRetire = {0,nullptr};
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
    for (Element* element : m_elements) {
        sortie.push_back(element->obtenirId());
    }
    return sortie;
}