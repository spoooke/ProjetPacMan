#ifndef GHOST_HPP
#define GHOST_HPP

#include "grilleConfig.hpp" // Incluez le fichier d'en-tête de GrilleConfig

class Ghost {
public:
    Ghost(int initialX, int initialY, GrilleConfig& grille);
    void move();
    int getX() const;
    int getY() const;
    bool isWall(int x, int y) const;

private:
    int x;
    int y;
    GrilleConfig& grid; // Membre de données pour stocker la référence à la grille
};

#endif