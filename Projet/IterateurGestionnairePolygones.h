/**
* \brief  Classe representant un IterateurConcret du patron iterateur pour le GestionnairePolygone 
* permettant d'iterer sur les polygones sans exposer la structure.
* \file   IterateurGestionnairePolygones.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#pragma once
#include "Iterateur.h"
#include "Polygone.h"
class IterateurGestionnairePolygones : public Iterateur<Polygone>{
public:
    IterateurGestionnairePolygones(std::vector<std::shared_ptr<Polygone>>& polygones);
    ~IterateurGestionnairePolygones() override = default;
    bool fin() const override;
    std::weak_ptr<Polygone> obtenirCourant() override; //reference non possessive
    void suivant() override;    
private:
    std::vector<std::shared_ptr<Polygone>>& m_polygones;
    int m_index; 
};