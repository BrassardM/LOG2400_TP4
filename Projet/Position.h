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