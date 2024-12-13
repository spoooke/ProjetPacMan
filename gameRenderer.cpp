#include "gameRenderer.hpp"
#include <iostream>

GameRenderer::GameRenderer(int windowWidth, int windowHeight) 
    : window(sf::VideoMode(windowWidth, windowHeight), "Pacman Game"),
      mouthAngle(45.0f),
      mouthOpening(true) {
    window.setFramerateLimit(60);
    cellSize = std::min(windowWidth / 15.0f, windowHeight / 10.0f);
    offsetX = (windowWidth - 15 * cellSize) / 2;
    offsetY = (windowHeight - 10 * cellSize) / 2;
    
    // Chargement de la police
    if (!font.loadFromFile("/System/Library/Fonts/Supplemental/Arial.ttf")) {
        std::cerr << "Erreur lors du chargement de la police" << std::endl;
    }
    
    initializeShapes();
}

void GameRenderer::initializeShapes() {
    // Pacman
    pacmanShape.setRadius(cellSize / 2.5f);
    pacmanShape.setFillColor(sf::Color::Yellow);
    pacmanShape.setOrigin(pacmanShape.getRadius(), pacmanShape.getRadius());

    // Bouche de Pacman
    pacmanMouth.setPointCount(3);
    pacmanMouth.setPoint(0, sf::Vector2f(0, 0));
    pacmanMouth.setPoint(1, sf::Vector2f(cellSize / 2.0f, cellSize / 4.0f));
    pacmanMouth.setPoint(2, sf::Vector2f(cellSize / 2.0f, -cellSize / 4.0f));
    pacmanMouth.setFillColor(sf::Color::Black);

    // Ghost
    ghostShape.setRadius(cellSize / 2.5f);
    ghostShape.setFillColor(sf::Color::Red);
    ghostShape.setOrigin(ghostShape.getRadius(), ghostShape.getRadius());

    // Wall
    wallShape.setSize(sf::Vector2f(cellSize, cellSize));
    wallShape.setFillColor(sf::Color::Blue);

    // Normal point
    pointShape.setRadius(cellSize / 8.0f);
    pointShape.setFillColor(sf::Color::White);
    pointShape.setOrigin(pointShape.getRadius(), pointShape.getRadius());

    // Super point
    superPointShape.setRadius(cellSize / 4.0f);
    superPointShape.setFillColor(sf::Color::White);
    superPointShape.setOrigin(superPointShape.getRadius(), superPointShape.getRadius());
}

void GameRenderer::updatePacmanAnimation() {
    if (mouthOpening) {
        mouthAngle += 3.0f;
        if (mouthAngle >= 45.0f) mouthOpening = false;
    } else {
        mouthAngle -= 3.0f;
        if (mouthAngle <= 0.0f) mouthOpening = true;
    }
}

void GameRenderer::renderPacman(float x, float y, int direction) {
    pacmanShape.setPosition(x, y);
    pacmanShape.setRotation(direction);
    window.draw(pacmanShape);

    // Animation de la bouche
    pacmanMouth.setPosition(x, y);
    pacmanMouth.setRotation(direction);
    pacmanMouth.setPoint(1, sf::Vector2f(cellSize / 2.0f, cellSize / 4.0f - (mouthAngle / 90.0f * cellSize / 4.0f)));
    pacmanMouth.setPoint(2, sf::Vector2f(cellSize / 2.0f, -cellSize / 4.0f + (mouthAngle / 90.0f * cellSize / 4.0f)));
    window.draw(pacmanMouth);
}

void GameRenderer::render(const GrilleConfig& grid, const PacMan& pacman, const Ghost& ghost) {
    window.clear(sf::Color::Black);

    // Dessiner la grille
    const auto& gridData = grid.getGrid();
    for (int y = 0; y < grid.getGRID_HEIGHT(); ++y) {
        for (int x = 0; x < grid.getGRID_WIDTH(); ++x) {
            float posX = offsetX + x * cellSize;
            float posY = offsetY + y * cellSize;

            switch (gridData[y][x]) {
                case '#': // Mur
                    wallShape.setPosition(posX, posY);
                    window.draw(wallShape);
                    break;
                case '.': // Point normal
                    pointShape.setPosition(posX + cellSize/2, posY + cellSize/2);
                    window.draw(pointShape);
                    break;
                case 'o': // Super point
                    superPointShape.setPosition(posX + cellSize/2, posY + cellSize/2);
                    window.draw(superPointShape);
                    break;
            }
        }
    }

    // Mettre à jour l'animation de Pacman
    updatePacmanAnimation();

    // Dessiner Pacman avec animation
    float pacmanX = offsetX + pacman.getX() * cellSize + cellSize/2;
    float pacmanY = offsetY + pacman.getY() * cellSize + cellSize/2;
    renderPacman(pacmanX, pacmanY, pacman.getDirection());

    // Dessiner le fantôme
    ghostShape.setPosition(
        offsetX + ghost.getX() * cellSize + cellSize/2,
        offsetY + ghost.getY() * cellSize + cellSize/2
    );
    window.draw(ghostShape);

    window.display();
}

void GameRenderer::displayGameOver(int score) {
    sf::Text gameOverText;
    gameOverText.setFont(font);
    gameOverText.setString("Game Over!\nScore: " + std::to_string(score) + "\nAppuyez sur ESPACE pour recommencer\nou ECHAP pour quitter");
    gameOverText.setCharacterSize(30);
    gameOverText.setFillColor(sf::Color::White);
    gameOverText.setPosition(
        window.getSize().x / 2 - gameOverText.getGlobalBounds().width / 2,
        window.getSize().y / 2 - gameOverText.getGlobalBounds().height / 2
    );

    window.clear(sf::Color::Black);
    window.draw(gameOverText);
    window.display();
}

void GameRenderer::displayStartScreen() {
    sf::Text startText;
    startText.setFont(font);
    startText.setString("PACMAN\n\nUtilisez les flèches pour vous déplacer\nÉvitez le fantôme\nMangez les points pour marquer\n\nAppuyez sur ESPACE pour commencer");
    startText.setCharacterSize(30);
    startText.setFillColor(sf::Color::White);
    startText.setPosition(
        window.getSize().x / 2 - startText.getGlobalBounds().width / 2,
        window.getSize().y / 2 - startText.getGlobalBounds().height / 2
    );

    window.clear(sf::Color::Black);
    window.draw(startText);
    window.display();
}

bool GameRenderer::isWindowOpen() const {
    return window.isOpen();
}

void GameRenderer::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

sf::RenderWindow& GameRenderer::getWindow() {
    return window;
}
