/**
* \brief  Classe abstraite représentant une commande dans le patron Commande. 
* \file   Commande.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#pragma once
class Commande{
public:
    Commande() = default;
    virtual ~Commande() = default;

    virtual void executer() = 0;
    virtual void annuler() = 0;
};