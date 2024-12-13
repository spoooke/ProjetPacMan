# Pacman Game

Un jeu Pacman en C++ utilisant la bibliothèque SFML pour les graphismes.

## Fonctionnalités

### Gameplay
- Déplacement fluide de Pacman avec animation de la bouche
- Fantôme qui se déplace aléatoirement
- Collecte de points (10 points) et super points (50 points)
- Système de score
- Détection des collisions avec les murs et le fantôme

### Interface Utilisateur
- Animation fluide de Pacman (bouche qui s'ouvre et se ferme)
- Rotation de Pacman en fonction de la direction
- Écran de démarrage avec instructions
- Écran de Game Over avec score final
- Affichage du score en temps réel

### Contrôles
- Flèches directionnelles : déplacer Pacman
- ESPACE : Commencer une nouvelle partie / Recommencer après Game Over
- ÉCHAP : Quitter le jeu

## Prérequis
- C++ compiler
- SFML 2.6.2
- CMake

## Installation

1. Cloner le repository
2. Créer un dossier build :
```bash
mkdir build
cd build
```

3. Compiler le projet :
```bash
cmake ..
make
```

4. Lancer le jeu :
```bash
./pacman
```

## Structure du Projet

### Classes Principales
- `PacMan` : Gestion du personnage principal
- `Ghost` : Logique du fantôme
- `GrilleConfig` : Configuration et gestion de la grille de jeu
- `GameRenderer` : Rendu graphique et animations

### Fichiers
- `main.cpp` : Point d'entrée et boucle principale du jeu
- `pacman.hpp/cpp` : Classe Pacman
- `ghost.hpp/cpp` : Classe Ghost
- `grilleConfig.hpp/cpp` : Classe GrilleConfig
- `gameRenderer.hpp/cpp` : Classe GameRenderer

## Dernières Mises à Jour (13/12/2023)

### Nouvelles Fonctionnalités
1. Animation de Pacman
   - Bouche qui s'ouvre et se ferme
   - Rotation selon la direction

2. Système de Game Over
   - Écran de fin avec score
   - Possibilité de recommencer

3. Interface Améliorée
   - Écran de démarrage
   - Instructions de jeu
   - Affichage du score

### Améliorations Techniques
- Optimisation des collisions
- Animation fluide (16ms de délai)
- Meilleure organisation du code

## Prochaines Améliorations Possibles
- [ ] Ajout de sons
- [ ] Plusieurs niveaux
- [ ] Différents types de fantômes
- [ ] Power-ups spéciaux
- [ ] High scores
- [ ] Menu de configuration

## Auteur
Sébastien GILLIO

## Licence
Ce projet est sous licence MIT.
