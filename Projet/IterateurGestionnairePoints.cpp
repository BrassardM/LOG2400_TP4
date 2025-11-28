#include "IterateurGestionnairePoints.h"
IterateurGestionnairePoints::IterateurGestionnairePoints(std::map<unsigned int, std::unique_ptr<Point>>& points) : m_points{points}, m_iterateurMappe{m_points.begin()}{}

bool IterateurGestionnairePoints::fin() const{
    return (m_iterateurMappe == m_points.end());
}

Point* IterateurGestionnairePoints::obtenirCourant(){
    return m_iterateurMappe->second.get();
}

void IterateurGestionnairePoints::suivant(){
    ++m_iterateurMappe;
}