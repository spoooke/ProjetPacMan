#ifndef GRILLECONFIG_HPP
#define GRILLECONFIG_HPP

#include <vector>

class GrilleConfig {
public:
    GrilleConfig(int width, int height);
    void initializeGrid();
    void displayGrid();
    // Ajoutez d'autres fonctions au besoin

private:
    int GRID_WIDTH;
    int GRID_HEIGHT;
    std::vector<std::vector<char> > grid;
};

#endif
