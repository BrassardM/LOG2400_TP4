/**
* \brief  Implementation du sujet abstrait Sujet.
* \file   Sujet.cpp
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#include "Sujet.h"
Sujet::Sujet(){}

void Sujet::ajouterObservateur(std::weak_ptr<Observateur> observateur){
    m_observateurs.push_back(observateur);
}

void Sujet::notifier() const{
    for (std::weak_ptr<Observateur> observateur : m_observateurs){
        observateur.lock()->miseAJour();
    }
}