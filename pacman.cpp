#include "pacman.hpp"

PacMan::PacMan(int initialX, int initialY, GrilleConfig& grille) 
    : x(initialX), y(initialY), score(0), direction(0), grid(grille) {}

void PacMan::moveUp() {
    if (canMove(x, y - 1)) {
        y--;
        direction = 270;
        checkAndCollectPoint();
    }
}

void PacMan::moveDown() {
    if (canMove(x, y + 1)) {
        y++;
        direction = 90;
        checkAndCollectPoint();
    }
}

void PacMan::moveLeft() {
    if (canMove(x - 1, y)) {
        x--;
        direction = 180;
        checkAndCollectPoint();
    }
}

void PacMan::moveRight() {
    if (canMove(x + 1, y)) {
        x++;
        direction = 0;
        checkAndCollectPoint();
    }
}

int PacMan::getX() const {
    return x;
}

int PacMan::getY() const {
    return y;
}

int PacMan::getScore() const {
    return score;
}

int PacMan::getDirection() const {
    return direction;
}

void PacMan::reset(int initialX, int initialY) {
    x = initialX;
    y = initialY;
    score = 0;
    direction = 0;
}

bool PacMan::canMove(int newX, int newY) const {
    if (newX < 0 || newX >= grid.getGRID_WIDTH() || 
        newY < 0 || newY >= grid.getGRID_HEIGHT()) {
        return false;
    }
    return grid.getGrid()[newY][newX] != GrilleConfig::WALL;
}

void PacMan::checkAndCollectPoint() {
    auto& gridData = const_cast<std::vector<std::vector<char>>&>(grid.getGrid());
    char& currentCell = gridData[y][x];
    
    if (currentCell == '.') {  // Point normal
        score += 10;
        currentCell = ' ';  // Le point est collecté
    }
    else if (currentCell == 'o') {  // Super point
        score += 50;
        currentCell = ' ';  // Le super point est collecté
    }
}
