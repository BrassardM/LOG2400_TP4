#include "GestionnairePoints.h"
GestionnairePoints* GestionnairePoints::obtenirInstance(){
    static GestionnairePoints instance;
    return &instance;
}

void GestionnairePoints::intialiserPoints(std::vector<std::pair<int,int>> points){
    for (const std::pair<int,int>& pos : points) {
        std::unique_ptr<Point> point = std::make_unique<Point>(pos);
        m_points.emplace(point->obtenirId(),std::move(point));
    }
}

void GestionnairePoints::ajouterPoint(std::unique_ptr<Point> point){
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

Point* GestionnairePoints::obtenirPoint(unsigned int id) {
    // si le ID existe pas en tant que point
    if (m_points.find(id) == m_points.end()){
        return nullptr;
    }
    return (m_points[id].get());
}

std::unique_ptr<IterateurGestionnairePoints> GestionnairePoints::creerIterateur(){
    return std::move(std::make_unique<IterateurGestionnairePoints>(m_points));
}

std::unique_ptr<Point> GestionnairePoints::retirerPoint(unsigned int id){
    if (m_points.find(id) == m_points.end()){
        return nullptr;
    }
    std::unique_ptr<Point> point = std::move(m_points[id]);
    m_points.erase(id);
    point->retirer();
    notifier();
    return std::move(point);
}