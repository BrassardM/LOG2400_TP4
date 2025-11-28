#pragma once
#include "Composant.h"
#include <vector>
class ComposantNuage : public Composant{
public:
    virtual std::vector<int> obtenirIDElements() const = 0;
};