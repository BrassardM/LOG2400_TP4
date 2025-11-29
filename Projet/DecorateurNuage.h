/**
* \brief  Classe abstraite representant un decorateur general d'un composant nuage
* dans le patron decorateur. 
* \file   DecorateurNuage.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

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