#pragma once
#include "DecorateurPoint.h"
class DecorateurPointPosition : public DecorateurPoint {
public:
    DecorateurPointPosition(std::weak_ptr<ComposantPoint> composant);
    ~DecorateurPointPosition() = default;
    
    std::string obtenirInformation() const override;
};