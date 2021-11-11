#include <iostream>
#include <ctime>
#include "exercise1.h"
#include <fstream>
#define WIDTH 10
#define HEIGHT 10
#define MIN 0
#define MAX 255

using namespace std;

//int main() {
//    srand(time (NULL));
////    PGM p(WIDTH, HEIGHT, MIN, MAX);
////    p.drawcross(3, 3, 0);
////    p.afficherImage();
////    char filename[13] = "filename.pgm";
////    p.writeFile(filename);
//    PGM p2;
//    char file[9] = "lena.pgm";
//    p2.readFile(file);
////    p2.afficherImage();
//    p2.drawrect(10, 10, 500, 500, 255);
//    char filename2[13] = "lenarect.pgm";
//    p2.writeFile(filename2);
//    p2.readFile(file);
//    p2.drawline(0, 512, 265, 255);
//    char filename3[13] = "lenaline.pgm";
//    p2.writeFile(filename3);
//    p2.readFile(file);
//    p2.drawcross(250, 315, 255);
//    char filename4[14] = "lenacross.pgm";
//    p2.writeFile(filename4);
//
//    return 0;
//}

int main() { int number1 = 88, number2 = 22;
    //pointeurs
    int* pNumber1 = &number1;
    *pNumber1 = 99;
    cout << *pNumber1 << endl;
    cout << &number1 << endl;
    cout << pNumber1 << endl;
    cout << &pNumber1 << endl;
    pNumber1 = &number2;
    //références
    int& refNumber1 = number1;
    refNumber1 = 11;
    cout << refNumber1 << endl;
    cout << &number1 << endl;
    cout << &refNumber1 << endl;
    //refNumber1 = &number2;
    refNumber1 = number2;
    number2++;
    cout << refNumber1 << endl;
    cout << number1 << endl;
    cout << number2 << endl; }