#pragma once
#include "Element.h"
#include "Position.h"
#include "Texture.h"
#include "ComposantPoint.h"

class Point : public Element, public ComposantPoint {
public:
    Point(const std::pair<int,int>& position);
    ~Point() override = default;
    
    void ajouterTexture(Texture* texture) override;
    void retirerTexture(Texture* texture) override;
    
    void retirer() override;
    void annulerRetire() override;
    bool estRetire() const override;
     
    void changerPosition(const std::pair<int,int>& position);
    Position obtenirPosition() const override;

    std::list<Point*> obtenirPoints() override; //retorune des pointeurs non possesifs de soi meme

    std::string obtenirInformation() const override;
    std::string obtenirTexture() const override;
private:
    Position m_position;
    bool m_retire;
    std::list<Texture*> m_textures; //tableau de pointeurs non possesifs de textures
};