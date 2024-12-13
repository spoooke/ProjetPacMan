#include "ghost.hpp"
#include "grilleConfig.hpp"
#include <cstdlib>

Ghost::Ghost(int initialX, int initialY, GrilleConfig& grille) 
    : x(initialX), y(initialY), grid(grille) {}

void Ghost::move() {
    int direction = std::rand() % 4;  // 0: haut, 1: droite, 2: bas, 3: gauche
    int newX = x;
    int newY = y;

    switch (direction) {
        case 0: newY--; break;  // Haut
        case 1: newX++; break;  // Droite
        case 2: newY++; break;  // Bas
        case 3: newX--; break;  // Gauche
    }

    if (canMove(newX, newY)) {
        x = newX;
        y = newY;
    }
}

int Ghost::getX() const {
    return x;
}

int Ghost::getY() const {
    return y;
}

void Ghost::reset(int initialX, int initialY) {
    x = initialX;
    y = initialY;
}

bool Ghost::canMove(int newX, int newY) const {
    if (newX < 0 || newX >= grid.getGRID_WIDTH() || 
        newY < 0 || newY >= grid.getGRID_HEIGHT()) {
        return false;
    }
    return grid.getGrid()[newY][newX] != GrilleConfig::WALL;
}
