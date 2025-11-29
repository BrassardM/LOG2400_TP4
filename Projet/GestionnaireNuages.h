#pragma once
#include "GestionnairePoints.h"
#include "Observateur.h"
#include "IterateurGestionnaireNuage.h"
 
class GestionnaireNuages : public Observateur {
public:
    ~GestionnaireNuages() = default;

    static std::shared_ptr<GestionnaireNuages> obtenirInstance(); //retourne pointeur non possedant

    void miseAJour() override;

    bool creerNuage(std::vector<int> ids);
    void intialiserTextures(std::vector<char> textures);

    std::unique_ptr<IterateurGestionnaireNuage> creerIterateur();


private:
    GestionnaireNuages() = default;
    GestionnaireNuages(const GestionnaireNuages&) = delete;            
    GestionnaireNuages& operator=(const GestionnaireNuages&) = delete; 
    GestionnaireNuages(GestionnaireNuages&&) = delete;
    GestionnaireNuages& operator=(GestionnaireNuages&&) = delete;      

    std::map<unsigned int,std::shared_ptr<NuageDePoints>> m_nuages;
    std::vector<char> m_textures;
    int m_indexTexture;
};