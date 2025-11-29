/**
* \brief  Classe representant l'invocateur ou executeur du patron commande.
* \file   Executeur.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#pragma once
#include "Commande.h"
#include <memory>
class Executeur{
public:
    Executeur();
    ~Executeur() = default;
    
    void executerCommande(std::unique_ptr<Commande> commande);
    bool reappliquer();
    bool annuler();
    void vider();
private:
    std::unique_ptr<Commande> m_commande;
    bool reapplicationPossible;
};