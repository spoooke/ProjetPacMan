#include "grilleConfig.hpp"
#include <iostream>

const char WALL = '#';
const char POINT = '.';
const char SUPER_POINT = 'o';
const char PACMAN = 'P';
const char GHOST = 'G';

GrilleConfig::GrilleConfig(int width, int height) : GRID_WIDTH(width), GRID_HEIGHT(height) {
    grid.resize(GRID_HEIGHT, std::vector<char>(GRID_WIDTH, WALL));
}

void GrilleConfig::initializeGrid() {
    for (int i = 0; i < GRID_HEIGHT; ++i) {
        for (int j = 0; j < GRID_WIDTH; ++j) {
            grid[i][j] = WALL;
        }
    }

    grid[1][1] = POINT;
    grid[1][13] = POINT;
    grid[8][3] = POINT;
    grid[6][7] = SUPER_POINT;
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

const std::vector<std::vector<char> >& GrilleConfig::getGrid() const {
    return grid;
}
