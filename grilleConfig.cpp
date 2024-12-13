#include "grilleConfig.hpp"
#include <iostream>

const char GrilleConfig::WALL = '#';
const char POINT = '.';
const char SUPER_POINT = 'o';
const char PACMAN = 'P';
const char GHOST = 'G';

GrilleConfig::GrilleConfig(int width, int height) : GRID_WIDTH(width), GRID_HEIGHT(height) {
    grid.resize(GRID_HEIGHT, std::vector<char>(GRID_WIDTH, WALL));
}

void GrilleConfig::initializeGrid() {
    // Remplir les bords avec des murs
    for (int i = 0; i < GRID_HEIGHT; ++i) {
        for (int j = 0; j < GRID_WIDTH; ++j) {
            if (i == 0 || i == GRID_HEIGHT-1 || j == 0 || j == GRID_WIDTH-1) {
                grid[i][j] = WALL;
            } else {
                grid[i][j] = POINT;  // Remplir l'intérieur avec des points
            }
        }
    }

    // Ajouter quelques murs pour rendre le labyrinthe plus intéressant
    grid[2][2] = WALL;
    grid[2][3] = WALL;
    grid[3][2] = WALL;
    grid[5][5] = WALL;
    grid[5][6] = WALL;
    grid[6][5] = WALL;
    
    // Ajouter quelques super points
    grid[3][7] = SUPER_POINT;
    grid[7][3] = SUPER_POINT;
}

void GrilleConfig::displayGrid() {
    for (int i = 0; i < GRID_HEIGHT; ++i) {
        for (int j = 0; j < GRID_WIDTH; ++j) {
            std::cout << grid[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int GrilleConfig::getGRID_WIDTH() const {
    return GRID_WIDTH;
}

int GrilleConfig::getGRID_HEIGHT() const {
    return GRID_HEIGHT;
}

std::vector<std::vector<char>>& GrilleConfig::getGrid() {
    return grid;
}

const std::vector<std::vector<char>>& GrilleConfig::getGrid() const {
    return grid;
}
