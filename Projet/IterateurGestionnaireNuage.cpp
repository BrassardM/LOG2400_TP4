#include "IterateurGestionnaireNuage.h"
IterateurGestionnaireNuage::IterateurGestionnaireNuage(std::map<unsigned int, std::unique_ptr<NuageDePoints>>& nuages) : m_nuages{nuages}, m_iterateurMappe{m_nuages.begin()}{}

bool IterateurGestionnaireNuage::fin() const{
    return (m_iterateurMappe == m_nuages.end());
}

NuageDePoints* IterateurGestionnaireNuage::obtenirCourant(){
    return m_iterateurMappe->second.get();
}

void IterateurGestionnaireNuage::suivant(){
    ++m_iterateurMappe;
}