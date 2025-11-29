#pragma once
#include "Observateur.h"
#include <vector>
#include <memory>

class Sujet {
public:
    Sujet();
    ~Sujet() = default;

    void ajouterObservateur(std::weak_ptr<Observateur> observateur);
    void notifier() const;

private:
    std::vector<std::weak_ptr<Observateur>> m_observateurs; //pointeurs non possessif sur les observateurs
};