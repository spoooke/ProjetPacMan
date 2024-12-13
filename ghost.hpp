#ifndef GHOST_HPP
#define GHOST_HPP

#include "grilleConfig.hpp" // Incluez le fichier d'en-tête de GrilleConfig

class Ghost {
public:
    Ghost(int initialX, int initialY, GrilleConfig& grille);
    void move();
    int getX() const;
    int getY() const;
    void reset(int initialX, int initialY);
    bool isWall(int x, int y) const;

private:
    int x;
    int y;
    GrilleConfig& grid; // Membre de données pour stocker la référence à la grille
    bool canMove(int newX, int newY) const;
};

#endif
