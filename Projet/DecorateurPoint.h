#pragma once
#include "ComposantPoint.h"
#include <memory>
class DecorateurPoint : public ComposantPoint {
public:
    DecorateurPoint(std::weak_ptr<ComposantPoint> composant);
    ~DecorateurPoint() = default;

    std::string obtenirInformation() const override;
    std::string obtenirTexture() const override;
    Position obtenirPosition() const override;
protected:
    std::weak_ptr<ComposantPoint> m_composant; // pointeur non possessif
};