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