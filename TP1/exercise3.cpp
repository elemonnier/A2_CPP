#include "exercise3.h"
#include <iostream>
using namespace std;

int max(int n){
    return n;
}

int max(int m, int n){
    if (m < n){
        return n;
    }
    return m;
}

int max(int m, int n, int r){
    if (m >= n && m >= r){
        return m;
    }
    if (n >= m && n >= r){
        return n;
    }
    return r;
}

void maxTests(){
    int value;
    cout << "Enter a integer between 1 and 3: ";
    cin >> value;
    switch (value){
        case 1:
            int a;
            cout << "Enter an integer: ";
            cin >> a;
            a = max(a);
            cout << "The maximum value you entered is: " << a << endl;
            break;
        case 2:
            int b, c;
            cout << "Enter two integers: ";
            cin >> b;
            cin >> c;
            b = max(b, c);
            cout << "The maximum value you entered is: " << b << endl;
            break;
        case 3:
            int d, e, f;
            cout << "Enter three integers: ";
            cin >> d;
            cin >> e;
            cin >> f;
            d = max(d, e, f);
            cout << "The maximum value you entered is: " << d << endl;
            break;
        default:
            cout << "Error: this is not an integer between 1 and 3 !" << endl;
    }
}