#pragma once
#include "Sujet.h"
#include "Point.h"
#include "IterateurGestionnairePoints.h"
#include <map>
class GestionnairePoints : public Sujet {
public:
    ~GestionnairePoints() = default;

    static GestionnairePoints* obtenirInstance();

    void intialiserPoints(std::vector<std::pair<int,int>> points);
    
    void ajouterPoint(std::unique_ptr<Point> point);
    void deplacerPoint(unsigned int id, const std::pair<int,int>& position);
    
    Point* obtenirPoint(unsigned int id); // non possessif

    std::unique_ptr<IterateurGestionnairePoints> creerIterateur();

    std::unique_ptr<Point> retirerPoint(unsigned int id);
    
private:
    GestionnairePoints() = default;
    GestionnairePoints(const GestionnairePoints&) = delete;            
    GestionnairePoints& operator=(const GestionnairePoints&) = delete; 
    GestionnairePoints(GestionnairePoints&&) = delete;
    GestionnairePoints& operator=(GestionnairePoints&&) = delete;      

    std::map<unsigned int, std::unique_ptr<Point>> m_points;
};