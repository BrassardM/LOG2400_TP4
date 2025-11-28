#include "GestionnairePolygones.h"
GestionnairePolygones* GestionnairePolygones::obtenirInstance(){
    static GestionnairePolygones instance;
    return &instance;
}

void GestionnairePolygones::miseAJour(){
    creerPolygones();
}

std::unique_ptr<IterateurGestionnairePolygones> GestionnairePolygones::creerIterateur() {
    return std::move(std::make_unique<IterateurGestionnairePolygones>(m_polygones));
}

void GestionnairePolygones::changerConstructeurDistance(){
    m_constructeur = std::make_unique<ConstructeurPolygoneDistance>();
    creerPolygones();
}

void GestionnairePolygones::changerConstructeurID(){
    m_constructeur = std::make_unique<ConstructeurPolygoneID>();
    creerPolygones();
}

GestionnairePolygones::GestionnairePolygones() : m_constructeur(std::make_unique<ConstructeurPolygoneVide>()) {}

void GestionnairePolygones::creerPolygones(){
    m_polygones.clear();
    std::unique_ptr<Iterateur<NuageDePoints>> it = GestionnaireNuages::obtenirInstance()->creerIterateur();
    while (!it->fin()){
        m_polygones.push_back(std::move(m_constructeur->creerPolygone((it->obtenirCourant())->obtenirPoints())));
        it->suivant();
    }
}
