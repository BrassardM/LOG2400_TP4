/**
* \brief  Implementaiton de IterateurGestionnairePolygones.
* \file   IterateurGestionnairePolygones.cpp
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#include "IterateurGestionnairePolygones.h"
IterateurGestionnairePolygones::IterateurGestionnairePolygones(std::vector<std::shared_ptr<Polygone>>& polygones) : m_polygones(polygones), m_index{0} {}

bool IterateurGestionnairePolygones::fin() const{
    return (m_index >= m_polygones.size());
}

std::weak_ptr<Polygone> IterateurGestionnairePolygones::obtenirCourant(){
    return m_polygones[m_index];
}

void IterateurGestionnairePolygones::suivant(){
    m_index++;
}