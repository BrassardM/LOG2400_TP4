#pragma once
#include "Element.h"
#include "Texture.h"
#include "ComposantNuage.h"
#include <memory>

class NuageDePoints : public Element, public ComposantNuage {
public:
    NuageDePoints(const std::list<Element*>& elements, char texture);
    ~NuageDePoints() override = default;

    std::list<Point*> obtenirPoints() override; // appelle la fonction pour tout ses elements

    void restaurerElement();
    void retirerPointInvalide();

    std::string obtenirInformation() const override;
    std::string obtenirTexture() const override;
protected:
    std::vector<int> obtenirIDElements() const override;
private:
    std::pair<int,Element*> m_elementRetire; //index dans la liste & pointeur non possessif
    std::list<Element*> m_elements;          //pointeurs non possessifs
    std::unique_ptr<Texture> m_texture;      //pointeur possessif
};