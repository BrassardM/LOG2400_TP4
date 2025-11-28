#include "CommandeDeplacerPoint.h"
CommandeDeplacerPoint::CommandeDeplacerPoint(int id, std::pair<int,int> position) : m_id(id), m_positionInitiale(0,0), m_positionFinale(position){}

void CommandeDeplacerPoint::executer(){
    GestionnairePoints* gestionnaire = GestionnairePoints::obtenirInstance(); 
    Point* point = gestionnaire->obtenirPoint(m_id);
    if (!point) {
        return;
    }

    m_positionInitiale = point->obtenirPosition().obtenirPair();
    gestionnaire->deplacerPoint(m_id, m_positionFinale);
}

void CommandeDeplacerPoint::annuler(){
    GestionnairePoints::obtenirInstance()->deplacerPoint(m_id,m_positionInitiale);
}