/**
* \brief  Implementation de la classe controleur.
* \file   Controlleur.cpp
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#include "Controlleur.h"
#include "StrategieAfficherTexture.h"
#include "StrategieAfficherID.h"
#include "CommandeSupprimerPoint.h"
#include "CommandeDeplacerPoint.h"
#include <sstream>

Controlleur::Controlleur(Vue& vue) : m_vue(vue) {}

bool Controlleur::decoderEtExecuterEntree(const std::string& entree) {
    switch (entree[0]){
    case ('a') : {
        afficherListe();
        return true;
    }
    case ('o') : {
        switch (entree[1]){
        case ('1'):
            afficherPointsTexture();
            break;
        case ('2'):
            afficherPointsID();
            break;
        default : 
            m_vue.afficherCommandeInvalide();
            break;
        }
        return true;
    }
    case ('f') : {
        std::string nuagesTexte;
        if (entree.size() == 1){
            m_vue.afficherNuageRequete();
            nuagesTexte = m_vue.capturerEntree();
        }
        else {
            nuagesTexte = entree.substr(1);  
        }
        
        std::istringstream iss(nuagesTexte);
        std::vector<int> nuagesID;
        int value;
        while (iss >> value) {
            nuagesID.push_back(value);
        }
        creerNuage(nuagesID);
        return true;
    }
    case ('d'): {
        m_vue.afficherIDRequeteDeplacer();
        std::string idTexte = m_vue.capturerEntree();
        m_vue.afficherPositionRequete();
        std::string positionTexte = m_vue.capturerEntree();

        std::istringstream iss(positionTexte);

        int first, second;
        iss >> first >> second;

        std::pair<int,int> position(first, second);
        deplacerPoint(std::stoi(idTexte), position);
        
        return true;
    }
    case ('s'): {
        std::string idTexte;
        if (entree.size() == 1){
            m_vue.afficherIDRequeteSupprimer();
            idTexte = m_vue.capturerEntree();
        }
        else {
            idTexte = entree.substr(1);  
        }

        supprimerPoint(std::stoi(idTexte));
        return true;
    }
    case ('u') : {
        annulerOperationPoint();
        return true;
    }
    case ('r') : {
        refaireOperationPoint();
        return true;
    }
    case ('c') : {
        switch (entree[1]){
        case('1'):
            creerSurfaceID();
            break;
        case('2'):
            creerSurfaceDistance();
            break;
        default: 
            m_vue.afficherCommandeInvalide();
            return false;
        }
        return true;
    }
    case ('q') :
        return false;
    default:
        m_vue.afficherCommandeInvalide();
        return true;
    }
}

void Controlleur::afficherListe() const {
    m_vue.afficherTableau();
}

void Controlleur::afficherPointsID() const {
    m_vue.changerStrategie(std::move(std::make_unique<StrategieAfficherID>()));
    m_vue.afficherGrille();
}

void Controlleur::afficherPointsTexture() const {
    m_vue.changerStrategie(std::move(std::make_unique<StrategieAfficherTexture>()));
    m_vue.afficherGrille();
}

void Controlleur::creerNuage(const std::vector<int>& points) {
    m_executeur.vider();
    if (!GestionnaireNuages::obtenirInstance()->creerNuage(points)){
        m_vue.afficherCommandeInvalide();
    }
}

void Controlleur::deplacerPoint(int id, std::pair<int,int> position){
    m_executeur.executerCommande(std::move(std::make_unique<CommandeDeplacerPoint>(id, position)));
}

void Controlleur::supprimerPoint(int id){
    m_executeur.executerCommande(std::move(std::make_unique<CommandeSupprimerPoint>(id)));
}

void Controlleur::annulerOperationPoint() {
    if(!m_executeur.annuler()){
        m_vue.afficherAnnulerImpossible();
    }
}

void Controlleur::refaireOperationPoint(){
    if(!m_executeur.reappliquer()){
        m_vue.afficherReapplicationImpossible();
    }
}

void Controlleur::creerSurfaceID(){
    GestionnairePolygones::obtenirInstance()->changerConstructeurID();
}

void Controlleur::creerSurfaceDistance(){
    GestionnairePolygones::obtenirInstance()->changerConstructeurDistance();
}
