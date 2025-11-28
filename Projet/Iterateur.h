#pragma once
template <typename T>
class Iterateur{
public : 
    Iterateur() = default;
    virtual ~Iterateur() = default;
    virtual bool fin() const = 0;
    virtual T* obtenirCourant() = 0; //reference non possessif
    virtual void suivant() = 0;
};