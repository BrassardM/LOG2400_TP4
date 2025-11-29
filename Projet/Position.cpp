/**
* \brief  Implementation de Position.
* \file   Position.cpp
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#include "Position.h"
Position::Position(const std::pair<int,int>& position) : m_position{position} {}

std::pair<int,int> Position::obtenirPair() const{
    return m_position;
}

void Position::changerPosition(std::pair<int,int> position){
    m_position = position;
}

int Position::calculerDistanceCarre(Position autrePosition) const{
    int deltaX = autrePosition.m_position.first - m_position.first;
    int deltaY = autrePosition.m_position.second - m_position.second;
    return (deltaX*deltaX) + (deltaY*deltaY); 
}