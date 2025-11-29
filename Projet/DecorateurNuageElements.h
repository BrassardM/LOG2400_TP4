#pragma once
#include "DecorateurNuage.h"
class DecorateurNuageElements : public DecorateurNuage {
public:
    DecorateurNuageElements(std::weak_ptr<ComposantNuage> composant);
    ~DecorateurNuageElements() = default;
    
    std::string obtenirInformation() const override;
};