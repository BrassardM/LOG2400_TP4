#pragma once
class Observateur{
public:
    Observateur() = default;
    ~Observateur() = default;
    
    virtual void miseAJour() = 0;
};