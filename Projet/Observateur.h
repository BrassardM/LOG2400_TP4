/**
* \brief  Classe representant l'observateur abstrait du patron observateur.
* \file   Observateur.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#pragma once
class Observateur{
public:
    Observateur() = default;
    ~Observateur() = default;
    
    virtual void miseAJour() = 0;
};