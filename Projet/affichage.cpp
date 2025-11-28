#include "affichage.h"
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>



void tracerLigne(std::vector<std::vector<char>>& grille, int x0, int y0, int x1, int y1) {
    // J'ai ajouter cette ligne au code donnée pour que ca soit plus beau.
    char lineChar = ( abs(y1 - y0) < abs(x1 - x0)/4 ) ? '-' : (( abs(x1 - x0) < abs(y1 - y0)/4 ) ? '|' : ((x1 - x0)*(y1 - y0) >= 0) ? '/' : '\\');
    // Distance verticale
    int lignes = abs(y1 - y0);
    // Si la ligne est horizontale 
    if (lignes == 0) {
        // On prend distance horizontale 
        lignes = abs(x1 - x0);
        for (int i = 0; i <= lignes; ++i) {
            // On trace chaque point de la ligne, de gauche à droite ou de droite à gauche selon la direction.
            int x = (x0 < x1) ? x0 + i : x0 - i;
            if (y1 >= 0 && y1 < HAUTEUR && x >= 0 && x < LARGEUR)
                grille[y1][x] = lineChar;
        }
    } else {
        // Si la ligne est verticale ou diagonale 
        for (int i = 0; i <= lignes; ++i) {
            double t = (double)i / lignes;
            // On fait une interpolation lineaire
            int x = round(x0 + t * (x1 - x0));
            int y = round(y0 + t * (y1 - y0));
            if (x >= 0 && x < LARGEUR && y >= 0 && y < HAUTEUR)
                grille[y][x] = lineChar;
        }
    }
}



std::vector<std::pair<int,int>> creerPoints(const std::string& ligne) {
    std::vector<std::pair<int,int>> points;
    // On crée un flux de lecture (istringstream) à partir de la chaîne ligne.
    std::istringstream iss(ligne);
    std::string token;
    // On lit chaque point de la ligne (séparé par des espaces).
    while (iss >> token) {
        // On vérifie que le point est entre parenthèses
        if (token.size() >= 3 && token.front() == '(' && token.back() == ')') {
            // On enlève les parenthèses au début et à la fin.
            token = token.substr(1, token.size() - 2);
            // On remplace la virgule par un espace.
            replace(token.begin(), token.end(), ',', ' ');
            // On crée un flux de lecture pour chaque point
            std::istringstream pair(token);
            int x, y;
            // On ajoute un point {x, y} au vecteur de points.
            if (pair >> x >> y) {
                points.push_back({x, y});
            }
        }
    }
    return points;
}