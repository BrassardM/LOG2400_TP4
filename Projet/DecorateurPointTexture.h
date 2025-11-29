#pragma once
#include "DecorateurPoint.h"
class DecorateurPointTexture : public DecorateurPoint {
public:
    DecorateurPointTexture(std::weak_ptr<ComposantPoint> composant);
    ~DecorateurPointTexture() = default;
    
    std::string obtenirInformation() const override;
};