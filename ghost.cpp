#include "ghost.hpp"
#include "grilleConfig.hpp"
#include <cstdlib>

// Déclarer la constante WALL de la même manière que dans grilleConfig.cpp
const char GrilleConfig::WALL = '#';

Ghost::Ghost(int initialX, int initialY, GrilleConfig& grille) : x(initialX), y(initialY), grid(grille) {}

void Ghost::move() {
    int randomDirection = rand() % 4;

    int newX = x;
    int newY = y;

    switch (randomDirection) {
        case 0:
            newY--;
            break;
        case 1:
            newY++;
            break;
        case 2:
            newX--;
            break;
        case 3:
            newX++;
            break;
    }

    if (!isWall(newX, newY)) {
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

bool Ghost::isWall(int x, int y) const {
    if (x < 0 || x >= grid.getGRID_WIDTH() || y < 0 || y >= grid.getGRID_HEIGHT()) {
        return true;
    }

    if (grid.getGrid()[y][x] == GrilleConfig::WALL) {
        return true;
    } else {
        return false;
    }
}
