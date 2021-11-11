//
// Created by upupu on 12/12/2019.
//

#ifndef TP7_POINT_H
#define TP7_POINT_H


#include <iostream>
#include <vector>
#include <map>

using namespace std;

template<class T> class Point {
private:
    T x;
    T y;
public:
    Point(T, T);

    Point(T const &P);

    T getX();

    T getY();

    void setX(T);

    void setY(T);

    ~Point();
};

template<class T> Point<T>::Point(T x, T y){
    setX(x);
    setY(y);
    std::cout << "Point(T, T) : " << this;
}

template<class T> Point<T>::Point(const T &P) {
    setX(P.x);
    setY(P.y);
}

template<class T> T Point<T>::getX() {
    return this->x;
}

template<class T> T Point<T>::getY() {
    return this->y;
}

template<class T> void Point<T>::setX(T x) {
    this->x = x;
}

template<class T> void Point<T>::setY(T y) {
    this->y = y;
}

template<class T> Point<T>::~Point() {
    std::cout << "~Point() : " << this << "\n";
}

template <class T> void pointTest() {
    Point<T> p(3.6,7.2);
    std::cout << "\n(" << p.getX() << ", " << p.getY() << ")\n";
}

void pointTests();
template <class T> void printVector(vector<T>);
void printNumbers();
void printLetters();
bool isNumber(string);
void isNumberTests();
void keepNumbersOnly(vector<string>&);
void filterVectorTest();
vector<string> splitString(string, string = " ");
void splitTests();
void printAges();
template <class T1, class T2> void printMap(map<T1, T2> m);
void printMapTests();
void printRights();
void filterMapTest();
void keepMalesOnly(map<string, bool>&);
void splitMapTest();
void splitOnGender(map<string, bool>, vector<string>&, vector<string>&);
void statsTest();
map<string, float> computeStatistics(vector<int>);
void statsTest2();
map<string, float> computeStatistics2(vector<int>);

#endif //TP7_POINT_H