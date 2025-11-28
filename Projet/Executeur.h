#pragma once
#include "Commande.h"
#include <memory>
class Executeur{
public:
    Executeur();
    ~Executeur() = default;
    
    void executerCommande(std::unique_ptr<Commande> commande);
    bool reappliquer();
    bool annuler();
    void vider();
private:
    std::unique_ptr<Commande> m_commande;
    bool reapplicationPossible;
};