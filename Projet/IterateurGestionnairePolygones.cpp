#include "IterateurGestionnairePolygones.h"
IterateurGestionnairePolygones::IterateurGestionnairePolygones(std::vector<std::unique_ptr<Polygone>>& polygones) : m_polygones(polygones), m_index{0}{}

bool IterateurGestionnairePolygones::fin() const{
    return (m_index >= m_polygones.size());
}

Polygone* IterateurGestionnairePolygones::obtenirCourant(){
    return m_polygones[m_index].get();
}

void IterateurGestionnairePolygones::suivant(){
    m_index++;
}