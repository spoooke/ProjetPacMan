#ifndef GAMERENDERER_HPP
#define GAMERENDERER_HPP

#include <SFML/Graphics.hpp>
#include "grilleConfig.hpp"
#include "pacman.hpp"
#include "ghost.hpp"

class GameRenderer {
public:
    GameRenderer(int windowWidth, int windowHeight);
    void render(const GrilleConfig& grid, const PacMan& pacman, const Ghost& ghost);
    bool isWindowOpen() const;
    void handleEvents();
    sf::RenderWindow& getWindow();
    void displayGameOver(int score);
    void displayStartScreen();

private:
    sf::RenderWindow window;
    sf::CircleShape pacmanShape;
    sf::CircleShape ghostShape;
    sf::RectangleShape wallShape;
    sf::CircleShape pointShape;
    sf::CircleShape superPointShape;
    sf::ConvexShape pacmanMouth;
    sf::Font font;
    
    float cellSize;
    float offsetX;
    float offsetY;
    float mouthAngle;
    bool mouthOpening;
    
    void initializeShapes();
    void updatePacmanAnimation();
    void renderPacman(float x, float y, int direction);
};

#endif
