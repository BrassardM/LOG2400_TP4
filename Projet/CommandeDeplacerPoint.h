/**
* \brief  Classe representant une commande concrete du patron 
* commande permettant de deplacer un point.
* \file   CommandeDeplacerPoint.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#pragma once
#include "Commande.h"
#include "GestionnairePoints.h"
class CommandeDeplacerPoint : public Commande{
public:
    CommandeDeplacerPoint(int id, std::pair<int,int> position);
    ~CommandeDeplacerPoint() override = default;

    void executer() override;
    void annuler() override;
private:
    std::pair<int,int> m_positionInitiale;
    std::pair<int,int> m_positionFinale;
    int m_id;
};