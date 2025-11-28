#pragma once
#include "StrategieAfficher.h"
#include "GestionnairePolygones.h"
#include "GestionnairePoints.h"
#include "GestionnaireNuages.h"

class Vue{
public:
    Vue() = default;
    ~Vue() = default;
    
    std::string capturerEntree() const;
    void afficherCommandePossibles() const;
    void afficherTableau() const;
    void afficherGrille() const;

    void changerStrategie(std::unique_ptr<StrategieAfficher> strategie);

    void afficherCommandeInvalide() const;
    void afficherReapplicationImpossible() const;
    void afficherAnnulerImpossible() const;

    void afficherNuageRequete() const;
    void afficherIDRequeteDeplacer() const;
    void afficherPositionRequete() const;
    void afficherIDRequeteSupprimer() const;
private:
    std::unique_ptr<StrategieAfficher> m_strategie;
};