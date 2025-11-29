/**
* \brief  Classe abstraite representant le sujet abstrait du patron observateur. 
* \file   Sujet.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#pragma once
#include "Observateur.h"
#include <vector>
#include <memory>

class Sujet {
public:
    Sujet();
    ~Sujet() = default;

    void ajouterObservateur(std::weak_ptr<Observateur> observateur);
    void notifier() const;

private:
    std::vector<std::weak_ptr<Observateur>> m_observateurs; //pointeurs non possessif sur les observateurs
};