#pragma once
#include "DecorateurPoint.h"
class DecorateurPointPosition : public DecorateurPoint {
public:
    DecorateurPointPosition(ComposantPoint* composant);
    ~DecorateurPointPosition() = default;
    
    std::string obtenirInformation() const override;
};