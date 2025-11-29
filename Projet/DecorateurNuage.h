#pragma once
#include "ComposantNuage.h"
#include <memory>
class DecorateurNuage : public ComposantNuage {
public:
    DecorateurNuage(std::weak_ptr<ComposantNuage> composant);
    ~DecorateurNuage() = default;

    std::string obtenirInformation() const override;
    std::string obtenirTexture() const override;
    std::vector<int> obtenirIDElements() const override;
protected:
    std::weak_ptr<ComposantNuage> m_composant; // pointeur non possessif
};