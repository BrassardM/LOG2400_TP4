/**
* \brief  Classe abstraite representant un decorateur general d'un composant point
* dans le patron decorateur. 
* \file   DecorateurPoint.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

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