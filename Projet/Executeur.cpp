/**
* \brief  Implementation de l'executeur de commandes.
* \file   Executeur.cpp
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#include "Executeur.h"
Executeur::Executeur() : reapplicationPossible(false){}

void Executeur::executerCommande(std::unique_ptr<Commande> commande){
    m_commande = std::move(commande);
    reapplicationPossible = false;
    m_commande->executer();
}

bool Executeur::annuler(){
    if ((m_commande != nullptr) && reapplicationPossible){
        return false;
    }
    reapplicationPossible = true;
    m_commande->annuler();
    return true;
}

bool Executeur::reappliquer(){
    if (!reapplicationPossible){
        return false;
    }
    reapplicationPossible = false;
    m_commande->executer();
    return true;
}

void Executeur::vider(){
    m_commande.reset();
    reapplicationPossible = false;
}