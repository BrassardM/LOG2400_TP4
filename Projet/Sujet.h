#pragma once
#include "Observateur.h"
#include <vector>
class Sujet {
public:
    Sujet();
    ~Sujet() = default;

    void ajouterObservateur(Observateur* observateur);
    void notifier() const;

private:
    std::vector<Observateur*> m_observateurs; //pointeurs non possessif sur les observateurs
};