#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include "exercise1.h"
#define WIDTH 512
#define HEIGHT 512
#define MAX 255
using namespace std;

void PGM::setWidth(int width) {
    this->width = width;
}

void PGM::setHeight(int height) {
    this->height = height;
}

void PGM::setMaxvalue(int maxvalue) {
    this->maxvalue = maxvalue;
}

void PGM::setData(int** data) {
    this->data = data;
}

int **PGM::initImage() {
    auto **data = new int *[height];
    for (auto i = 0; i < height; i++) {
        data[i] = new int[width];
    }
    return data;
}

void PGM::deleteImage(){
    delete data;
}

int **PGM::createImage(int minpix, int maxpix) {
    data = initImage();
    for (auto i = 0; i < height; i++) {
        for (auto j = 0; j < width; j++) {
            data[i][j] = rand() % (maxpix - minpix + 1) + minpix;
        }
    }
    return data;
}

PGM::PGM() {
    setWidth(WIDTH);
    setHeight(HEIGHT);
    setMaxvalue(MAX);
    setData(PGM::initImage());
}

PGM::PGM(int width, int height, int minpix, int maxpix) {
    setWidth(width);
    setHeight(height);
    setMaxvalue(maxpix);
    setData(createImage(minpix, maxpix));
}

PGM::~PGM() {
    delete data;
}

PGM::PGM(PGM const& pgm) {
    setWidth(pgm.width);
    setHeight(pgm.height);
    setMaxvalue(pgm.maxvalue);
    data = initImage();
    for (auto i = 0; i < width; i++){
        for (auto j = 0; j < height; j++){
            data[i][j] = pgm.data[i][j];
        }
    }
}

void PGM::afficherImage() {
    for (auto i = 0; i < height; i++) {
        for (auto j = 0; j < width; j++) {
            cout << data[i][j] << "\t";
        }
        cout << "\n";
    }
}

void PGM::writeFile(char* filename) {
    ofstream file;
    file.open(filename);
    file << "P2\n" << width << " " << height << "\n" << maxvalue << "\n";
    for (auto i = 0; i < height; i++) {
        for (auto j = 0; j < width; j++) {
            file << data[i][j];
            file << " ";
        }
        file << "\n";
    }
    file.close();
}

void PGM::drawrect(int x1, int y1, int x2, int y2, int val) {
    if (val >= 0 && val <= 255){
        if (x1 <= x2 && y1 <= y2) {
            for (auto i = x1; i <= x2; i++) {
                for (auto j = y1; j <= y2; j++) {
                    data[j][i] = val;
                }
            }
        }
        if (x1 >= x2 && y1 <= y2){
            for (auto i = x2; i <= x1; i++) {
                for (auto j = y1; j <= y2; j++) {
                    data[j][i] = val;
                }
            }
        }
        if (x1 <= x2 && y1 >= y2){
            for (auto i = x1; i <= x2; i++) {
                for (auto j = y2; j <= y1; j++) {
                    data[j][i] = val;
                }
            }
        }
        if (x1 >= x2 && y1 >= y2){
            for (auto i = x2; i <= x1; i++) {
                for (auto j = y2; j <= y1; j++) {
                    data[j][i] = val;
                }
            }
        }
    }
    else {
        cout << "error";
    }
    if(x1 <= x2 && y1 <= y2){
        for (int i = x1; i < x2; i++) {
            for (int j = y1; j < y2; j++) {
                data[i][j] = val;
            }
        }
    }
}

void PGM::drawline(int x1, int x2, int line, int val) {
    if (line <= height){
        if (x1 <= x2){
            for (auto i = x1; i <= x2; i++){
                data[line][i] = val;
            }
        }
        else{
            for (auto i = x2; i <= x1; i++){
                data[line][i] = val;
            }
        }
    }
    else{
        cout << "error";
    }
}

void PGM::drawcross(int x, int y, int val) {
    data[x][y] = val;
    data[x-1][y-1] = val;
    data[x-1][y+1] = val;
    data[x+1][y-1] = val;
    data[x+1][y+1] = val;
}

void PGM::readFile(char* filename) {
    ifstream myfile;
    string line;
    stringstream s;
    myfile.open(filename);
    if (myfile.is_open()){
        getline(myfile,line);
        s << myfile.rdbuf();
        s >> width >> height;
        s >> maxvalue;
        data = initImage();
        for (auto i = 0; i < height; i++){
            for (auto j = 0; j < width; j++){
                s >> data[i][j];
            }
        }
    }
    myfile.close();
}

void PGM::thresholding(int th, char *filename) {
    for (auto i = 0; i < height; i++){
        for (auto j = 0; j < width; j++){
            if (data[i][j] > th){
                data[i][j] = 255;
            }
            else{
                data[i][j] = 0;
            }
        }
    }
    writeFile(filename);
}

void PGM::filterImage(char* filename, int k) {

}