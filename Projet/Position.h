/**
* \brief  Position est une classe representant une position qui appartient a 
* un point. Selon le patron expert, il est le plus en mesure de calculer sa distance
* avec un autre point.
* \file   Position.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/
#pragma once
#include <utility>

class Position{
public:
    Position(const std::pair<int,int>& position);
    ~Position() = default;

    Position(const Position& autre) = default;
    
    std::pair<int,int> obtenirPair() const;

    void changerPosition(std::pair<int,int> position);

    int calculerDistanceCarre(Position autrePosition) const;   
private:
    std::pair<int,int> m_position;
};