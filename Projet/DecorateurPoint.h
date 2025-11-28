#pragma once
#include "ComposantPoint.h"
class DecorateurPoint : public ComposantPoint {
public:
    DecorateurPoint(ComposantPoint* composant);
    ~DecorateurPoint() = default;

    std::string obtenirInformation() const override;
    std::string obtenirTexture() const override;
    Position obtenirPosition() const override;
protected:
    ComposantPoint* m_composant; // pointeur non possessif
};