#pragma once
#include "DecorateurNuage.h"
class DecorateurNuageTexture : public DecorateurNuage {
public:
    DecorateurNuageTexture(ComposantNuage* composant);
    ~DecorateurNuageTexture() = default;
    
    std::string obtenirInformation() const override;
};