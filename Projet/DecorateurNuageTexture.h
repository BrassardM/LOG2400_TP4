#pragma once
#include "DecorateurNuage.h"
class DecorateurNuageTexture : public DecorateurNuage {
public:
    DecorateurNuageTexture(std::weak_ptr<ComposantNuage> composant);
    ~DecorateurNuageTexture() = default;
    
    std::string obtenirInformation() const override;
};