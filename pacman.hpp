#ifndef PACMAN_HPP
#define PACMAN_HPP

class PacMan {
public:
    PacMan(int initialX, int initialY);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    int getX() const;
    int getY() const;

private:
    int x;
    int y;
};

#endif
