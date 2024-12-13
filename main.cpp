#include "pacman.hpp"
#include "ghost.hpp"
#include "grilleConfig.hpp"
#include "gameRenderer.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <chrono>
#include <thread>

enum class GameState {
    START_SCREEN,
    PLAYING,
    GAME_OVER
};

void resetGame(GrilleConfig& grille, PacMan& pacman, Ghost& ghost) {
    grille.initializeGrid();
    pacman.reset(7, 5);
    ghost.reset(1, 1);
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Création de la grille 15x10
    GrilleConfig grille(15, 10);
    grille.initializeGrid();

    // Création de Pacman au centre de la grille
    PacMan pacman(7, 5, grille);

    // Création d'un fantôme
    Ghost ghost(1, 1, grille);

    // Création du renderer
    GameRenderer renderer(800, 600);

    // Variables pour le contrôle de la vitesse
    const std::chrono::milliseconds moveDelay(150);
    const std::chrono::milliseconds ghostDelay(300);
    auto lastMoveTime = std::chrono::steady_clock::now();
    auto lastGhostMoveTime = std::chrono::steady_clock::now();

    GameState gameState = GameState::START_SCREEN;
    renderer.displayStartScreen();

    while (renderer.isWindowOpen()) {
        renderer.handleEvents();

        // Gestion des événements clavier
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            renderer.getWindow().close();
            continue;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            if (gameState == GameState::START_SCREEN || gameState == GameState::GAME_OVER) {
                resetGame(grille, pacman, ghost);
                gameState = GameState::PLAYING;
            }
        }

        if (gameState == GameState::PLAYING) {
            auto currentTime = std::chrono::steady_clock::now();

            // Gestion des entrées avec délai
            if (currentTime - lastMoveTime >= moveDelay) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                    pacman.moveUp();
                    lastMoveTime = currentTime;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                    pacman.moveDown();
                    lastMoveTime = currentTime;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    pacman.moveLeft();
                    lastMoveTime = currentTime;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    pacman.moveRight();
                    lastMoveTime = currentTime;
                }
            }

            // Déplacer le fantôme avec délai
            if (currentTime - lastGhostMoveTime >= ghostDelay) {
                ghost.move();
                lastGhostMoveTime = currentTime;
            }

            // Vérifier la collision avec le fantôme
            if (pacman.getX() == ghost.getX() && pacman.getY() == ghost.getY()) {
                gameState = GameState::GAME_OVER;
                renderer.displayGameOver(pacman.getScore());
                continue;
            }

            // Mettre à jour l'affichage
            renderer.render(grille, pacman, ghost);

            // Afficher le score dans la console
            std::cout << "\rScore: " << pacman.getScore() << std::flush;
        }

        // Petit délai pour éviter une utilisation excessive du CPU
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }

    return 0;
}
