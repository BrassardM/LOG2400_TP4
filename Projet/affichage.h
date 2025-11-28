#pragma once
#include <string>
#include <vector>
#include <utility>

const int LARGEUR = 35;
const int HAUTEUR = 35;

std::vector<std::pair<int,int>> creerPoints(const std::string& ligne);
void tracerLigne(std::vector<std::vector<char>>& grille, int x0, int y0, int x1, int y1);
