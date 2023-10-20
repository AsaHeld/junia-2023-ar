#include <iostream>
#include <vector>

//// On veut représenter l'environnement dans lequel circuleront des robots.
//
// L'environnement est une grille 2D
//Chaque élément de la grille peut contenir un autre robot, un obstacle, ou être vide.

class Environnement {
private:
    int largeur;
    int hauteur;
    std::vector<std::vector<int>> grille;

public:
    // Constructeur pour créer un environnement avec une grille vide
    Environnement(int largeur, int hauteur) : largeur(largeur), hauteur(hauteur) {
        grille = std::vector<std::vector<int>>(largeur, std::vector<int>(hauteur, 0));
    }

    // Méthode pour placer un robot dans la cellule spécifiée
    void placerRobot(int x, int y) {
        if (x >= 0 && x < largeur && y >= 0 && y < hauteur) {
            grille[x][y] = 1; // 1 représente un robot
        } else {
            std::cout << "Coordonnées hors de la grille." << std::endl;
        }
    }

    // Méthode pour placer un obstacle dans la cellule spécifiée
    void placerObstacle(int x, int y) {
        if (x >= 0 && x < largeur && y >= 0 && y < hauteur) {
            grille[x][y] = 2; // 2 représente un obstacle
        } else {
            std::cout << "Coordonnées hors de la grille." << std::endl;
        }
    }

    // Méthode pour afficher l'environnement
    void afficherEnvironnement() {
        for (int y = 0; y < hauteur; y++) {
            for (int x = 0; x < largeur; x++) {
                if (grille[x][y] == 0) {
                    std::cout << " ."; // Cellule vide
                } else if (grille[x][y] == 1) {
                    std::cout << " R"; // Robot
                } else if (grille[x][y] == 2) {
                    std::cout << " X"; // Obstacle
                }
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // Créer un environnement de 10x10
    Environnement environnement(10, 10);

    // Placer un robot dans la cellule (2, 3)
    environnement.placerRobot(2, 3);

    // Placer un obstacle dans la cellule (5, 5)
    environnement.placerObstacle(5, 5);

    // Afficher l'environnement
    environnement.afficherEnvironnement();

    return 0;
}
