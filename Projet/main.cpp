#include "affichage.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Vue.h"
#include "Controlleur.h"
#include "GestionnaireNuages.h"
#include "GestionnairePoints.h"
#include "GestionnairePolygones.h"


int main(int argc, char* argv[]) {


    std::string args;
    // On accepte des points en entrée.
    if (argc > 1) {
        std::ostringstream oss;
        for (int i = 1; i < argc; ++i) oss << argv[i] << " ";
        args = oss.str();
    } else {
        std::cout << "Entrez les points au format (x,y) :\n> ";
        getline(std::cin, args);
    }
    
    // Voici des fonctions utiles pour réaliser le TP. 
    std::vector<std::pair<int,int>> points = creerPoints(args);
    
    // Ce sont différentes textures possibles. Seules les 2 premières sont utilisées dans les scénarios du TP.
    std::vector<char> texturesNuages = {'o', '#', '$'};
    std::string cmd;
    
    //Intialiser les points et tout les observateurs (du patron observateur)
    {
        std::shared_ptr<GestionnairePoints> gestionnairePoints = GestionnairePoints::obtenirInstance();
        std::shared_ptr<GestionnaireNuages> gestionnaireNuages = GestionnaireNuages::obtenirInstance();
        gestionnaireNuages->intialiserTextures(texturesNuages);
        gestionnairePoints->intialiserPoints(points);
        gestionnairePoints->ajouterObservateur(gestionnaireNuages);
        gestionnairePoints->ajouterObservateur(GestionnairePolygones::obtenirInstance());
    }
    
    // Initializer la vue et le controlleur
    Vue vue;
    Controlleur controlleur(vue);
    
    bool continuerLaBoucle = true;

    while (continuerLaBoucle) {
        vue.afficherCommandePossibles();
        continuerLaBoucle = controlleur.decoderEtExecuterEntree(vue.capturerEntree());
    }

    return 0;
}