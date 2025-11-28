#pragma once
#include "DecorateurPoint.h"
class DecorateurPointTexture : public DecorateurPoint {
public:
    DecorateurPointTexture(ComposantPoint* composant);
    ~DecorateurPointTexture() = default;
    
    std::string obtenirInformation() const override;
};