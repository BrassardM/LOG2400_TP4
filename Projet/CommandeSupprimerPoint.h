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
    std::unique_ptr<Point> m_point;
    int m_id;
};