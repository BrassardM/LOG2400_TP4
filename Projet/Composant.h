#pragma once
#include <string>
class Composant{
public:
    virtual std::string obtenirInformation() const = 0;
    virtual std::string obtenirTexture() const = 0;
};