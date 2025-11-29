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