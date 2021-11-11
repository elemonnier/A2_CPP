#include <iostream>
#include <ctime>
#include "exercise1.h"
#include <fstream>
#define WIDTH 100
#define HEIGHT 100
#define MIN 0
#define MAX 255

using namespace std;

int main() {
    srand(time (NULL));
    PGM pgm(WIDTH, HEIGHT, MIN, MAX);
    pgm.initImage(WIDTH, HEIGHT);
    pgm.createImage();
//    pgm.drawline(6, 16, 7, 255);
//    pgm.drawrect(3, 3, 8, 8, 255);
//    pgm.drawcross(5, 4);
    char filename1[9] = "lena.pgm";
    pgm.readFile(filename1);
    char filename[13] = "filename.pgm";
    pgm.writeFile(filename1);
    pgm.thresholding(1, filename1);

    pgm.printImage();
}