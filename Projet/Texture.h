#pragma once
class Texture{
public:
    Texture(char charactere);    

    char obtenirCharactere() const;

    void changerCharactere(char charactere);
    
private:
    char m_charactere;
};