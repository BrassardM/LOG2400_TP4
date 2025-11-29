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