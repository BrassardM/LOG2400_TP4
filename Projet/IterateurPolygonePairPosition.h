#pragma once
#include "Position.h"
#include <utility>
#include "Iterateur.h"
#include <vector>
#include <memory>

// L'iterateur va iterer sur des pairs de positions.  
// ex: soit la liste {pos0, pos1, pos2}, l'iterateur va donner initialement {pos0, pos1}, 
// {pos1,pos2} et finalement {pos2,pos0}.
class IterateurPolygonePairPosition : public Iterateur<std::pair<Position,Position>>{
public:
    IterateurPolygonePairPosition(std::vector<Position>& positions);
    ~IterateurPolygonePairPosition() override = default;
    
    bool fin() const override;
    //va donner comme dernier pair le dernier et le premier
    std::weak_ptr<std::pair<Position,Position>> obtenirCourant() override; //reference non possessif
    void suivant() override;
private:
    std::vector<Position>& m_positions;
    std::shared_ptr<std::pair<Position,Position>> m_courant;
    int m_indexPremier;
    int m_indexDeuxieme;
};