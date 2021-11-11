#include "exercise1.h"
#include <ctime>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <sstream>
#include <algorithm>

using namespace std;

void PGM::setWidth(int width) {
    this->width = width;
}

void PGM::setHeight(int height) {
    this->height = height;
}

void PGM::setMinValue(int minValue) {
    this->minValue = minValue;
}

void PGM::setMaxValue(int maxValue) {
    this->maxValue = maxValue;
}

void PGM::setData(int **data) {
    this->data = data;
}

int PGM::getWidth() {
    return this->width;
}

int PGM::getHeight() {
    return this->height;
}

int **PGM::getData() {
    return this->data;
}

int **PGM::initImage(int width, int height) {
    setWidth(width);
    setHeight(height);
    int **data = new int *[height];
    for (auto i = 0; i < height; i++) {
        data[i] = new int[width];
    }
    setData(data);
    return data;
}

void PGM::deleteImage() {
    delete getData();
}

void PGM::createImage(int minpix, int maxpix) {
    setMinValue(minpix);
    setMaxValue(maxpix);
    for (auto i = 0; i < getHeight(); i++) {
        for (auto j = 0; j < getWidth(); j++) {
            getData()[i][j] = rand() % (maxpix - minpix + 1) + minpix;
//            getData()[i][j] = 0;
        }
    }
}

void PGM::printImage() {
    for (auto i = 0; i < getHeight(); i++) {
        for (auto j = 0; j < getWidth(); j++) {
            cout << getData()[i][j] << "\t";
        }
        cout << "\n";
    }
}

PGM::PGM() {
    setWidth(10);
    setHeight(10);
    setMinValue(0);
    setMaxValue(255);
}

PGM::PGM(int width, int height, int minValue, int maxValue) {
    setWidth(width);
    setHeight(height);
    setMinValue(minValue);
    setMaxValue(maxValue);
}

PGM::~PGM() {
    deleteImage();
}

//PGM::PGM(PGM const& pgm) {
//    setWidth(pgm.width);
//    setHeight(pgm.height);
//    setMaxValue(pgm.maxValue);
//    data = initImage();
//    for (auto i = 0; i < width; i++){
//        for (auto j = 0; j < height; j++){
//            data[i][j] = data[i][j];
//        }
//    }
//}

void PGM::writeFile(char *filename) {
    ofstream file;
    file.open(filename);
    file << "P2\n" << getWidth() << " " << getHeight() << "\n" << getMaxValue() << "\n";
    for (auto i = 0; i < getWidth(); i++) {
        for (auto j = 0; j < getHeight(); j++) {
            file << getData()[i][j];
            file << " ";
        }
        file << "\n";
    }
    file.close();
}

int PGM::getMaxValue() {
    return this->maxValue;
}

void PGM::drawrect(int x1, int y1, int x2, int y2, int val) {
    if (val >= 0 && val <= 255){
        if (x1 <= x2 && y1 <= y2) {
            for (auto i = x1; i <= x2; i++) {
                for (auto j = y1; j <= y2; j++) {
                    getData()[j][i] = val;
                }
            }
        }
        if (x1 >= x2 && y1 <= y2){
            for (auto i = x2; i <= x1; i++) {
                for (auto j = y1; j <= y2; j++) {
                    getData()[j][i] = val;
                }
            }
        }
        if (x1 <= x2 && y1 >= y2){
            for (auto i = x1; i <= x2; i++) {
                for (auto j = y2; j <= y1; j++) {
                    getData()[j][i] = val;
                }
            }
        }
        if (x1 >= x2 && y1 >= y2){
            for (auto i = x2; i <= x1; i++) {
                for (auto j = y2; j <= y1; j++) {
                    getData()[j][i] = val;
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
    if (line <= getHeight()){
        if (x1 <= x2){
            for (auto i = x1; i <= x2; i++){
                getData()[line][i] = val;
            }
        }
        else{
            for (auto i = x2; i <= x1; i++){
                getData()[line][i] = val;
            }
        }
    }
    else{
        cout << "error";
    }
}

void PGM::drawcross(int x, int y, int val) {
    getData()[x][y] = val;
    getData()[x-1][y] = val;
    getData()[x-2][y] = val;
    getData()[x-2][y+1] = val;
    getData()[x-2][y+2] = val;
    getData()[x][y+1] = val;
    getData()[x][y+2] = val;
    getData()[x+1][y+2] = val;
    getData()[x+2][y+2] = val;
    getData()[x+1][y] = val;
    getData()[x+2][y] = val;
    getData()[x][y-1] = val;
    getData()[x][y-2] = val;
    getData()[x-1][y-2] = val;
    getData()[x-2][y-2] = val;
    getData()[x+2][y-1] = val;
    getData()[x+2][y-2] = val;
}

void PGM::readFile(char* filename) {
    ifstream myfile;
    string line;
    stringstream s;
    myfile.open(filename);
    if (myfile.is_open()){
        getline(myfile, line);
        s << myfile.rdbuf();
        s >> width >> height;
        s >> maxValue;
        data = initImage();
        for(int i = 0; i < width;i++){
            for(int j=0; j< height; j++){
                s >> data[i][j];
            }
        }
    }
    myfile.close();
}

void PGM::thresholding(int th, char *filename) {
    for (auto i = 0; i < getHeight(); i++){
        for (auto j = 0; j < getWidth(); j++){
            if (getData()[i][j] > th){
                getData()[i][j] = 255;
            }
            else{
                getData()[i][j] = 0;
            }
        }
    }
    writeFile(filename);
}

void PGM::filterImage(char *filename, int k) {

}