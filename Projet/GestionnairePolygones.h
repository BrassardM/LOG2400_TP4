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