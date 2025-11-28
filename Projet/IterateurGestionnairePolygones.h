#pragma once
#include "Iterateur.h"
#include "Polygone.h"
class IterateurGestionnairePolygones : public Iterateur<Polygone>{
public:
    IterateurGestionnairePolygones(std::vector<std::unique_ptr<Polygone>>& polygones);
    ~IterateurGestionnairePolygones() override = default;
    bool fin() const override;
    Polygone* obtenirCourant() override; //reference non possessive
    void suivant() override;    
private:
    std::vector<std::unique_ptr<Polygone>>& m_polygones;
    int m_index; 
};