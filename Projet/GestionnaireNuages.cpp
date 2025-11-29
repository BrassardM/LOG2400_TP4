/**
* \brief  Implementation de GestionnaireNuage.
* \file   GestionnaireNuages.cpp
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#include "GestionnaireNuages.h"
std::shared_ptr<GestionnaireNuages> GestionnaireNuages::obtenirInstance(){
    static std::shared_ptr<GestionnaireNuages> instance(new GestionnaireNuages()); 
    return instance;
}

void GestionnaireNuages::miseAJour(){
    for (const std::pair<const unsigned int,std::shared_ptr<NuageDePoints>>& nuage : m_nuages){
        nuage.second->restaurerElement();
        nuage.second->retirerPointInvalide();
    }
}

bool GestionnaireNuages::creerNuage(std::vector<int> ids){
    std::shared_ptr<GestionnairePoints> points = GestionnairePoints::obtenirInstance();
    std::list<std::weak_ptr<Element>> elements;
    for (int id : ids){
        std::weak_ptr<Element> element = points->obtenirPoint(id).lock();
        if (element.expired()){
            if (m_nuages.find(id) == m_nuages.end()){
                return false;
            }
            element = m_nuages[id];
        }
        elements.emplace_back(element);
    }
    
    if (m_indexTexture >= m_textures.size()) {
        return false;
    }

    std::shared_ptr<NuageDePoints> nuage = std::make_shared<NuageDePoints>(elements, m_textures[m_indexTexture]);
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