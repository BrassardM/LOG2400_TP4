#include "DecorateurNuageElements.h"
DecorateurNuageElements::DecorateurNuageElements(ComposantNuage* composant) : DecorateurNuage(composant) {}

std::string DecorateurNuageElements::obtenirInformation() const {
    std::string sortie; 
    for (int id : obtenirIDElements()){
        sortie += std::to_string(id);
        sortie += " ";
    }
    sortie.pop_back();
    return  m_composant->obtenirInformation() + 'i' + sortie;
}