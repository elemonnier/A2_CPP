#include <iostream>
#include "exercise3.h"
using namespace std;

bool JeuMorpion::placer_coup(int ligne, int colonne, Content c) {
    switch (c){
        case ROND:
            grille[ligne][colonne] = ROND;
            return true;
        case CROIX:
            grille[ligne][colonne] = CROIX;
            return true;
        default:
            return true;
    }
}

void JeuMorpion::init() {
    for (auto i = 0; i < 3; i++){
        for (auto j = 0; j < 3; j++){
            this->grille[i][j] = VIDE;
        }
    }
}

bool JeuMorpion::placer_rond(int ligne, int colonne) {
    return placer_coup(ligne, colonne, ROND);
}

bool JeuMorpion::placer_croix(int ligne, int colonne) {
    return placer_coup(ligne, colonne, CROIX);
}

void JeuMorpion::afficher_grille() {
    for (auto i = 0; i < 3; i++){
        cout << "| ";
        for (auto j = 0; j < 3; j++){
            switch (this->grille[i][j]){
                case VIDE:
                    cout << "  | ";
                    break;
                case ROND:
                    cout << "O | ";
                    break;
                case CROIX:
                    cout << "X | ";
                    break;
                default:
                    break;
            }
        }
        cout << "\n";
    }
}

int JeuMorpion::getGrille(int ligne, int colonne) {
    return this->grille[ligne][colonne];
}

bool JeuMorpion::gameEnds(JeuMorpion jeu) {
    return (jeu.getGrille(0, 0) == ROND && jeu.getGrille(1, 0) == ROND && jeu.getGrille(2, 0) == ROND) ||
           (jeu.getGrille(0, 1) == ROND && jeu.getGrille(1, 1) == ROND && jeu.getGrille(2, 1) == ROND) ||
           (jeu.getGrille(0, 2) == ROND && jeu.getGrille(1, 2) == ROND && jeu.getGrille(2, 2) == ROND) ||
           (jeu.getGrille(0, 0) == ROND && jeu.getGrille(0, 1) == ROND && jeu.getGrille(0, 2) == ROND) ||
           (jeu.getGrille(1, 0) == ROND && jeu.getGrille(1, 1) == ROND && jeu.getGrille(1, 2) == ROND) ||
           (jeu.getGrille(2, 0) == ROND && jeu.getGrille(2, 1) == ROND && jeu.getGrille(2, 2) == ROND) ||
           (jeu.getGrille(0, 0) == ROND && jeu.getGrille(1, 1) == ROND && jeu.getGrille(2, 2) == ROND) ||
           (jeu.getGrille(0, 2) == ROND && jeu.getGrille(1, 1) == ROND && jeu.getGrille(2, 0) == ROND) ||
           (jeu.getGrille(0, 0) == CROIX && jeu.getGrille(1, 0) == CROIX && jeu.getGrille(2, 0) == CROIX) ||
           (jeu.getGrille(0, 1) == CROIX && jeu.getGrille(1, 1) == CROIX && jeu.getGrille(2, 1) == CROIX) ||
           (jeu.getGrille(0, 2) == CROIX && jeu.getGrille(1, 2) == CROIX && jeu.getGrille(2, 2) == CROIX) ||
           (jeu.getGrille(0, 0) == CROIX && jeu.getGrille(0, 1) == CROIX && jeu.getGrille(0, 2) == CROIX) ||
           (jeu.getGrille(1, 0) == CROIX && jeu.getGrille(1, 1) == CROIX && jeu.getGrille(1, 2) == CROIX) ||
           (jeu.getGrille(2, 0) == CROIX && jeu.getGrille(2, 1) == CROIX && jeu.getGrille(2, 2) == CROIX) ||
           (jeu.getGrille(0, 0) == CROIX && jeu.getGrille(1, 1) == CROIX && jeu.getGrille(2, 2) == CROIX) ||
           (jeu.getGrille(0, 2) == CROIX && jeu.getGrille(1, 1) == CROIX && jeu.getGrille(2, 0) == CROIX);
}