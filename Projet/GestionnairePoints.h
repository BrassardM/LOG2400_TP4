/**
* \brief  Classe qui possede tous les points, et qui gere
* leurs operations et leur initialization. Cette classe est un singleton du 
* patron singleton, et un sujet du patron observateur.
* \file   GestionnairePoints.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#pragma once
#include "Sujet.h"
#include "Point.h"
#include "IterateurGestionnairePoints.h"
#include <map>
class GestionnairePoints : public Sujet {
public:
    ~GestionnairePoints() = default;

    static std::shared_ptr<GestionnairePoints> obtenirInstance();

    void intialiserPoints(std::vector<std::pair<int,int>> points);
    
    void ajouterPoint(std::shared_ptr<Point> point);
    void deplacerPoint(unsigned int id, const std::pair<int,int>& position);
    
    std::weak_ptr<Point> obtenirPoint(unsigned int id); // non possessif

    std::unique_ptr<IterateurGestionnairePoints> creerIterateur();

    std::shared_ptr<Point> retirerPoint(unsigned int id);
    
private:
    GestionnairePoints() = default;
    GestionnairePoints(const GestionnairePoints&) = delete;            
    GestionnairePoints& operator=(const GestionnairePoints&) = delete; 
    GestionnairePoints(GestionnairePoints&&) = delete;
    GestionnairePoints& operator=(GestionnairePoints&&) = delete;      

    std::map<unsigned int, std::shared_ptr<Point>> m_points;
};