/**
* \brief  Implementaiton de IterateurGestionnairePoints.
* \file   IterateurGestionnairePoints.cpp
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#include "IterateurGestionnairePoints.h"
IterateurGestionnairePoints::IterateurGestionnairePoints(std::map<unsigned int, std::shared_ptr<Point>>& points) : m_points{points}, m_iterateurMappe{m_points.begin()}{}

bool IterateurGestionnairePoints::fin() const{
    return (m_iterateurMappe == m_points.end());
}

std::weak_ptr<Point> IterateurGestionnairePoints::obtenirCourant(){
    return m_iterateurMappe->second;
}

void IterateurGestionnairePoints::suivant(){
    ++m_iterateurMappe;
}