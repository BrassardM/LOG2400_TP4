#pragma once
#include "DecorateurNuage.h"
class DecorateurNuageElements : public DecorateurNuage {
public:
    DecorateurNuageElements(ComposantNuage* composant);
    ~DecorateurNuageElements() = default;
    
    std::string obtenirInformation() const override;
};