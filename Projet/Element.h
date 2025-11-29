#pragma once
#include <list>
#include <string>
#include <memory>
#include "Texture.h"
class Point; //declaration anticipée de Point

class Element {
public:
    Element();
    virtual ~Element();

    virtual void retirer();
    virtual void annulerRetire();
    virtual void ajouterTexture(std::weak_ptr<Texture> texture);
    virtual void retirerTexture(std::weak_ptr<Texture> texture);
    virtual bool estRetire() const;
    
    unsigned int obtenirId() const;
    
    virtual std::list<std::weak_ptr<Point>> obtenirPoints() = 0; //retorune des pointeurs non possesifs de points
private:
    void comparerProchainID();

    unsigned int m_id;
    static unsigned int m_prochainId;
}; 