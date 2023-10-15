#include "pacman.hpp"

PacMan::PacMan(int initialX, int initialY) : x(initialX), y(initialY) {}

void PacMan::moveUp() {
    y--;
}

void PacMan::moveDown() {
    y++;
}

void PacMan::moveLeft() {
    x--;
}

void PacMan::moveRight() {
    x++;
}

int PacMan::getX() const {
    return x;
}

int PacMan::getY() const {
    return y;
}
