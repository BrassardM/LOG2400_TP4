/**
* \brief  Classe representant un IterateurConcret du patron iterateur pour le GestionnaireNuage 
* permettant d'iterer sur les nuages de points sans exposer la structure.
* \file   IterateurGestionnaireNuage.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#pragma once
#include "Iterateur.h"
#include "NuageDePoints.h"
#include <map>

class IterateurGestionnaireNuage : public Iterateur<NuageDePoints>{
public:
    IterateurGestionnaireNuage(std::map<unsigned int, std::shared_ptr<NuageDePoints>>& nuages);
    ~IterateurGestionnaireNuage() override = default;
    bool fin() const override;
    std::weak_ptr<NuageDePoints> obtenirCourant() override; //reference non possessif
    void suivant() override;
private:
    std::map<unsigned int, std::shared_ptr<NuageDePoints>>& m_nuages;
    std::map<unsigned int, std::shared_ptr<NuageDePoints>>::iterator m_iterateurMappe; 
};