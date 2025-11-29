/**
* \brief Classe qui possede tous les polygones, et qui gere
* leur creation et leur mise a jour. Cette classe est un singleton du 
* patron singleton, et un observateur du patron observateur.
* \file   GestionnairePolygones.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#pragma once
#include "Observateur.h"
#include "ConstructeurPolygoneDistance.h"
#include "ConstructeurPolygoneID.h"
#include "ConstructeurPolygoneVide.h"
#include "GestionnaireNuages.h"
#include "IterateurGestionnairePolygones.h"
#include <vector>
class GestionnairePolygones : public Observateur {
public:
    ~GestionnairePolygones() = default;

    static std::shared_ptr<GestionnairePolygones> obtenirInstance();

    void miseAJour() override;
    
    std::unique_ptr<IterateurGestionnairePolygones> creerIterateur();

    void changerConstructeurDistance();
    void changerConstructeurID();
    
private:
    GestionnairePolygones();
    
    void creerPolygones();

    std::vector<std::shared_ptr<Polygone>> m_polygones;
    std::unique_ptr<ConstructeurPolygone> m_constructeur;
};