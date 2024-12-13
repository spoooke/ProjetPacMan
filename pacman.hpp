#ifndef PACMAN_HPP
#define PACMAN_HPP

#include "grilleConfig.hpp"

class PacMan {
public:
    PacMan(int initialX, int initialY, GrilleConfig& grille);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    int getX() const;
    int getY() const;
    int getScore() const;
    int getDirection() const;
    void reset(int initialX, int initialY);
    void checkAndCollectPoint();

private:
    int x;
    int y;
    int score;
    int direction; // 0=right, 90=down, 180=left, 270=up
    GrilleConfig& grid;
    bool canMove(int newX, int newY) const;
};

#endif
