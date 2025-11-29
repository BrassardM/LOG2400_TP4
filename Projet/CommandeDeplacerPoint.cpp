/**
* \brief  Implementation de la commande concrete CommandeDeplacerPoint
* \file   CommandeDeplacerPoint.cpp
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#include "CommandeDeplacerPoint.h"
CommandeDeplacerPoint::CommandeDeplacerPoint(int id, std::pair<int,int> position) : m_id(id), m_positionInitiale(0,0), m_positionFinale(position){}

void CommandeDeplacerPoint::executer(){
    std::shared_ptr<GestionnairePoints> gestionnaire = GestionnairePoints::obtenirInstance(); 
    std::weak_ptr<Point> point = gestionnaire->obtenirPoint(m_id);
    if (point.expired()) {
        return;
    }

    m_positionInitiale = point.lock()->obtenirPosition().obtenirPair();
    gestionnaire->deplacerPoint(m_id, m_positionFinale);
}

void CommandeDeplacerPoint::annuler(){
    GestionnairePoints::obtenirInstance()->deplacerPoint(m_id,m_positionInitiale);
}