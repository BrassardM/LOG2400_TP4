#pragma once
#include "Vue.h"
#include "Executeur.h"
class Controlleur{
public:
    Controlleur(Vue& vue);
    ~Controlleur() = default;
    
    bool decoderEtExecuterEntree(const std::string& entree); // donne true si on continue a avoir des commandes
                                                             // donne faux sinon

private:
    void afficherListe() const;
    void afficherPointsID() const;
    void afficherPointsTexture() const;
    void creerNuage(const std::vector<int>& points);
    void deplacerPoint(int id, std::pair<int,int> position);
    void supprimerPoint(int id);
    void annulerOperationPoint();
    void refaireOperationPoint();
    void creerSurfaceID();
    void creerSurfaceDistance();

    Vue& m_vue;
    Executeur m_executeur;
};