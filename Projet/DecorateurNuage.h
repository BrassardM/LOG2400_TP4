#pragma once
#include "ComposantNuage.h"
class DecorateurNuage : public ComposantNuage {
public:
    DecorateurNuage(ComposantNuage* composant);
    ~DecorateurNuage() = default;

    std::string obtenirInformation() const override;
    std::string obtenirTexture() const override;
    std::vector<int> obtenirIDElements() const override;
protected:
    ComposantNuage* m_composant; // pointeur non possessif
};