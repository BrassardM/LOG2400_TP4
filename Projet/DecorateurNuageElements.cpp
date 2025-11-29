/**
* \brief  Implementation du decorateur concret DecorateurNuageElement.
* \file   DecorateurNuageElements.cpp
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#include "DecorateurNuageElements.h"
DecorateurNuageElements::DecorateurNuageElements(std::weak_ptr<ComposantNuage> composant) : DecorateurNuage(composant) {}

std::string DecorateurNuageElements::obtenirInformation() const {
    std::string sortie; 
    for (int id : obtenirIDElements()){
        sortie += std::to_string(id);
        sortie += " ";
    }
    sortie.pop_back();
    return  m_composant.lock()->obtenirInformation() + 'i' + sortie;
}