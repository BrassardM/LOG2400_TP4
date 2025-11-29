/**
* \brief  Implementation de GestionnairePoints.
* \file   GestionnairePoints.cpp
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#include "GestionnairePoints.h"
std::shared_ptr<GestionnairePoints> GestionnairePoints::obtenirInstance(){
    static std::shared_ptr<GestionnairePoints> instance(new GestionnairePoints());
    return instance;
}

void GestionnairePoints::intialiserPoints(std::vector<std::pair<int,int>> points){
    for (const std::pair<int,int>& pos : points) {
        std::shared_ptr<Point> point = std::make_shared<Point>(pos);
        m_points.emplace(point->obtenirId(),std::move(point));
    }
}

void GestionnairePoints::ajouterPoint(std::shared_ptr<Point> point){
    point->annulerRetire();
    m_points.emplace(point->obtenirId(),std::move(point));
    notifier();
}

void GestionnairePoints::deplacerPoint(unsigned int id, const std::pair<int,int>& position) {
    if (m_points.find(id) == m_points.end()){
        return;
    }
    m_points[id]->changerPosition(position);
    notifier();
}

std::weak_ptr<Point> GestionnairePoints::obtenirPoint(unsigned int id) {
    // si le ID existe pas en tant que point
    if (m_points.find(id) == m_points.end()){
        return {};
    }
    return m_points[id];
}

std::unique_ptr<IterateurGestionnairePoints> GestionnairePoints::creerIterateur(){
    return std::move(std::make_unique<IterateurGestionnairePoints>(m_points));
}

std::shared_ptr<Point> GestionnairePoints::retirerPoint(unsigned int id){
    if (m_points.find(id) == m_points.end()){
        return nullptr;
    }
    std::shared_ptr<Point> point = std::move(m_points[id]);
    m_points.erase(id);
    point->retirer();
    notifier();
    return std::move(point);
}