// GrilleConfig.hpp
#ifndef GRILLECONFIG_HPP
#define GRILLECONFIG_HPP

#include <vector>

class GrilleConfig {
public:
    GrilleConfig(int width, int height);
    void initializeGrid();
    void displayGrid();
    // Ajoutez d'autres fonctions au besoin
    int getGRID_WIDTH() const; // Ajoutez une fonction pour obtenir GRID_WIDTH
    int getGRID_HEIGHT() const; // Ajoutez une fonction pour obtenir GRID_HEIGHT
    std::vector<std::vector<char> >& getGrid();  // Retiré le const pour permettre la modification
    const std::vector<std::vector<char> >& getGrid() const;  // Gardé la version const
    static const char WALL; // Déclarez WALL comme une constante statique
    // ... autres membres et fonctions

private:
    int GRID_WIDTH;
    int GRID_HEIGHT;
    std::vector<std::vector<char> > grid;
};

#endif
