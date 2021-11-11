#include <iostream>
#include <cstdlib>
#include <ctime>
#include "exercise1.h"
#include "exercise2.h"
#include "exercise3.h"
using namespace std;

double randomDouble(double min, double max) {
    return (rand() / ((double)RAND_MAX)) * (max-min) + min;
}

Point1* createRandomPath(int nbSteps, double minX, double maxX, double minY, double maxY){
    auto tabpoints = new Point1[nbSteps];
    for (auto i = 0; i < nbSteps; i++){
        tabpoints[i].setXdyn(randomDouble(minX, maxX));
        tabpoints[i].setYdyn(randomDouble(minY, maxY));
    }
    return tabpoints;
}

void showRandomPath(Point1* pathPoints, int nbSteps){
    cout << "Le chemin aléatoire généré est : ";
    for (auto i = 0; i < nbSteps; i++){
        pathPoints[i].afficherDyn();
    }
}

double followPath(Point1* point, Point1* path, int nbSteps){
    double distance = 0;
    for (auto i = 1; i <= nbSteps - 1; i++){
        *point = path[i];
        distance += point->distanceDyn(path[i - 1]);
    }
    return distance;
}

void testsEx1(){
    Equation e;
    double r1, r2;
    e.set();
    e.displayEquation();
    e.solveEquation(r1, r2);
}

void testsEx2(){
    auto *a = new Point1;
    auto *b = new Point1;
    auto *e = new Point1;
    cout << "** SAISIE DU POINT A **\n";
    a->saisirDyn();
    a->afficherDyn();
    cout << "** SAISIE DU POINT B **\n";
    b->saisirDyn();
    b->afficherDyn();
    cout << "** Milieu de AB **\n";
    a->milieuDyn(*b).afficherDyn();
    cout << "La distance AB vaut : " << a->distanceDyn(*b) << "\n";
    auto array = createRandomPath(5, 0, 5, 0, 5);
    showRandomPath(array, 3);
    auto path = followPath(e, array, 3);
    cout << "\nLes coordonnées du point E après le déplacement dans le chemin aléatoire est : ";
    e->afficherDyn();
    cout << "et la distance parcourue est : " << path;
    delete(a);
    delete(b);
    delete(e);
}

void testsEx3(){
    JeuMorpion jeu;
    jeu.init();
    jeu.afficher_grille();
    int ligne, colonne; // todo float
    int n;
    for (auto i = 0; i < 9; i++) {
        n = 0;
        while (n != 1) {
            if (i%2 == 0) {
                cout << "Entrez une ligne (entre 0 et 2) : ";
                cin >> ligne;
                if (ligne != 0 && ligne != 1 && ligne != 2) {
                    cout << "Ce n'est pas un nombre compris entre 0 et 2\n";
                    break;
                }
                cout << "Entrez une colonne (entre 0 et 2) : ";
                cin >> colonne;
                if (colonne != 0 && colonne != 1 && colonne != 2) {
                    cout << "Ce n'est pas un nombre compris entre 0 et 2\n";
                    break;
                }
                if (jeu.getGrille(ligne, colonne) == ROND || jeu.getGrille(ligne, colonne) == CROIX) {
                    cout << "Cette case est déjà utilisée\n";
                    break;
                }
                if (jeu.getGrille(ligne, colonne) == VIDE) {
                    jeu.placer_croix(ligne, colonne);
                    jeu.afficher_grille();
                    n = 1;
                    if (jeu.gameEnds(jeu)){
                        cout << "X wins !";
                        return;
                    }
                }
            }
            else {
                cout << "Entrez une ligne (entre 0 et 2) : ";
                cin >> ligne;
                if (ligne != 0 && ligne != 1 && ligne != 2) {
                    cout << "Ce n'est pas un nombre compris entre 0 et 2\n";
                    break;
                }
                cout << "Entrez une colonne (entre 0 et 2) : ";
                cin >> colonne;
                if (colonne != 0 && colonne != 1 && colonne != 2) {
                    cout << "Ce n'est pas un nombre compris entre 0 et 2\n";
                    break;
                }
                if (jeu.getGrille(ligne, colonne) == ROND || jeu.getGrille(ligne, colonne) == CROIX) {
                    cout << "Cette case est déjà utilisée\n";
                }
                if (jeu.getGrille(ligne, colonne) == VIDE){
                    jeu.placer_rond(ligne, colonne);
                    jeu.afficher_grille();
                    n = 1;
                    if (jeu.gameEnds(jeu)){
                        cout << "O wins !";
                        return;
                    }
                }
            }
        }
        if (n == 0){
            i--;
        }
    }
    cout << "Draw!";
}

int main() {
    srand( time(NULL) );
//    testsEx1();
//    testsEx2();
      testsEx3();
    return 0;
}

// todo tout coder en anglais