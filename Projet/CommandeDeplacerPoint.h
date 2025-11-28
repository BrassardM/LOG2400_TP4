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