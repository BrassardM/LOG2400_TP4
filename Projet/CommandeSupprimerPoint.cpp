/**
* \brief  Implementation de la commande concrete CommandeDeplacerPoint
* \file   CommandeSupprimerPoint.cpp
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#include "CommandeSupprimerPoint.h"

CommandeSupprimerPoint::CommandeSupprimerPoint(int id): m_id(id){}

void CommandeSupprimerPoint::executer(){
    m_point = std::move(GestionnairePoints::obtenirInstance()->retirerPoint(m_id));
}

void CommandeSupprimerPoint::annuler(){
    if (m_point != nullptr){
        GestionnairePoints::obtenirInstance()->ajouterPoint(std::move(m_point));
    }
}