/**
* \brief  Classe representant un composant concrete du patron decorateur et
* une feuille du patron composite. Cet element est la base de tout le
* systeme, le systeme a comme but de manipuler ses points et d'afficher
* les points. Cette classe possede les positions (qui sont utilisé par les polygones). 
* \file   Point.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#pragma once
#include "Element.h"
#include "Position.h"
#include "Texture.h"
#include "ComposantPoint.h"

class Point : public Element, public ComposantPoint, public std::enable_shared_from_this<Point>  {
public:
    Point(const std::pair<int,int>& position);
    ~Point() override = default;
    
    void ajouterTexture(std::weak_ptr<Texture> texture) override;
    void retirerTexture(std::weak_ptr<Texture> texture) override;
    
    void retirer() override;
    void annulerRetire() override;
    bool estRetire() const override;
     
    void changerPosition(const std::pair<int,int>& position);
    Position obtenirPosition() const override;

    std::list<std::weak_ptr<Point>> obtenirPoints() override; //retorune des pointeurs non possesifs de soi meme

    std::string obtenirInformation() const override;
    std::string obtenirTexture() const override;
private:
    Position m_position;
    bool m_retire;
    std::list<std::weak_ptr<Texture>> m_textures; //tableau de pointeurs non possesifs de textures
};