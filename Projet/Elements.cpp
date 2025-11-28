#include "Element.h"

unsigned int Element::m_prochainId = 0;

Element::Element() : m_id{m_prochainId++} {}

//*note on ne peux pas simplement appeler retirer car retirer est virtuel.
Element::~Element() {
    comparerProchainID(); 
}

unsigned int Element::obtenirId() const{
    return m_id;
}


void Element::retirer(){
    comparerProchainID();
}

void Element::annulerRetire(){
    if (m_id == (m_prochainId)) {
        m_prochainId++;
    }
}

// fonction sans implementation par defaut
void Element::ajouterTexture(Texture* texture) {}
void Element::retirerTexture(Texture* texture) {}
bool Element::estRetire() const{ return false; }

void Element::comparerProchainID(){
    if (m_id == (m_prochainId-1)) {
        m_prochainId = m_id;
    }
}