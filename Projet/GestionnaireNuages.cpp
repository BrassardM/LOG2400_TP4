#include "GestionnaireNuages.h"
GestionnaireNuages* GestionnaireNuages::obtenirInstance(){
    static GestionnaireNuages instance; 
    return &instance;
}

void GestionnaireNuages::miseAJour(){
    for (const std::pair<const unsigned int,std::unique_ptr<NuageDePoints>>& nuage : m_nuages){
        nuage.second->restaurerElement();
        nuage.second->retirerPointInvalide();
    }
}

bool GestionnaireNuages::creerNuage(std::vector<int> ids){
    GestionnairePoints* points = GestionnairePoints::obtenirInstance();
    std::list<Element*> elements;
    for (int id : ids){
        Element* element = points->obtenirPoint(id);
        if (element == nullptr){
            if (m_nuages.find(id) == m_nuages.end()){
                return false;
            }
            element = m_nuages[id].get();
        }
        elements.emplace_back(element);
    }
    
    if (m_indexTexture >= m_textures.size()) {
        return false;
    }

    std::unique_ptr<NuageDePoints> nuage = std::make_unique<NuageDePoints>(elements, m_textures[m_indexTexture]);
    m_nuages[nuage->obtenirId()] = std::move(nuage);
    m_indexTexture++;
    return true;
}

void GestionnaireNuages::intialiserTextures(std::vector<char> textures){
    m_textures = textures;
    m_indexTexture = 0;
}

std::unique_ptr<IterateurGestionnaireNuage> GestionnaireNuages::creerIterateur() {
    return std::move(std::make_unique<IterateurGestionnaireNuage>(m_nuages));
}