#include "IterateurGestionnaireNuage.h"
IterateurGestionnaireNuage::IterateurGestionnaireNuage(std::map<unsigned int, std::shared_ptr<NuageDePoints>>& nuages) : m_nuages{nuages}, m_iterateurMappe{m_nuages.begin()}{}

bool IterateurGestionnaireNuage::fin() const{
    return (m_iterateurMappe == m_nuages.end());
}

std::weak_ptr<NuageDePoints> IterateurGestionnaireNuage::obtenirCourant(){
    return m_iterateurMappe->second;
}

void IterateurGestionnaireNuage::suivant(){
    ++m_iterateurMappe;
}