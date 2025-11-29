/**
* \brief  Classe representant une commande concrete du patron 
* commande permettant de supprimer un point.
* \file   CommandeSupprimerPoint.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#pragma once
#include "Commande.h"
#include "GestionnairePoints.h"
class CommandeSupprimerPoint : public Commande{
public:
    CommandeSupprimerPoint(int id);
    ~CommandeSupprimerPoint() override = default;

    void executer() override;
    void annuler() override;
private:
    std::shared_ptr<Point> m_point;
    int m_id;
};