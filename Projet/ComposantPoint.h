#pragma once
#include "Position.h"
#include "Composant.h"
class ComposantPoint : public Composant{
public:
    virtual Position obtenirPosition() const = 0;
};