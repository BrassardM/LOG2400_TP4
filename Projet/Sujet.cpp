#include "Sujet.h"
Sujet::Sujet(){}

void Sujet::ajouterObservateur(Observateur* observateur){
    m_observateurs.push_back(observateur);
}

void Sujet::notifier() const{
    for (Observateur* observateur : m_observateurs){
        observateur->miseAJour();
    }
}