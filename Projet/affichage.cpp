#include "affichage.h"
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>



void tracerLigne(std::vector<std::vector<char>>& grille, int x0, int y0, int x1, int y1) {
    // algorithme de Bresenham
    char caractereLigne = ( abs(y1 - y0) < abs(x1 - x0)/4 ) ? '-' 
                        : ( ( abs(x1 - x0) < abs(y1 - y0)/4 ) ? '|' 
                        : ( (x1 - x0)*(y1 - y0) >= 0 ? '/' : '\\') );

    int deltaX = abs(x1 - x0);
    int deltaY = abs(y1 - y0);
    int pasX = (x0 < x1) ? 1 : -1;
    int pasY = (y0 < y1) ? 1 : -1;
    int erreur = deltaX - deltaY;

    while (true) {
        if (x0 >= 0 && x0 < LARGEUR && y0 >= 0 && y0 < HAUTEUR)
            grille[y0][x0] = caractereLigne;

        if (x0 == x1 && y0 == y1) break;
        int erreurDouble = 2 * erreur;
        if (erreurDouble > -deltaY) { erreur -= deltaY; x0 += pasX; }
        if (erreurDouble < deltaX)  { erreur += deltaX; y0 += pasY; }
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