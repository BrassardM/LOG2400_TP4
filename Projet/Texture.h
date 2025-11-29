/**
* \brief  Classe representant une texture d'un nuage de point et ses characteristiques.
* (Admet plus de modificabilite dans le futur, si on veux rajouter plus de characteristiques
* a une texture qui ne sont pas que des characteres.)
* \file   Texture.h
* \author Omar Cadoret et Matthew Brassard
* \date   29 novembre 2025
* Créé le 27 novembre 2025
*/

#pragma once
class Texture{
public:
    Texture(char charactere);    

    char obtenirCharactere() const;

    void changerCharactere(char charactere);
    
private:
    char m_charactere;
};