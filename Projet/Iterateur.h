/**
* \brief  Classe generique abstrait representant un iterateur
* abstrait du patron iterateur. 
* \file   Iterateur.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#pragma once
#include <memory>
template <typename T>
class Iterateur{
public : 
    Iterateur() = default;
    virtual ~Iterateur() = default;
    virtual bool fin() const = 0;
    virtual std::weak_ptr<T> obtenirCourant() = 0; //reference non possessif
    virtual void suivant() = 0;
};