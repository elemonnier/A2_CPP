#include "exercise4.h"
#include <iostream>
using namespace std;

void swapVariablesWithAddresses(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void swapVariablesWithReferences(int &a, int &b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void swapVariablesTests(){
    int a, b, choice;
    cout << "Enter two integers ('a' then 'b'): ";
    cin >> a;
    cin >> b;
    cout << "Swap them with (enter 1 or 2): \n1) addresses\n2) references" << endl;
    cin >> choice;
    switch (choice){
        case 1:
            swapVariablesWithAddresses(&a, &b);
            cout << "Now a = " << a << " and b = " << b << endl;
            break;
        case 2:
            swapVariablesWithReferences(a, b);
            cout << "Now a = " << a << " and b = " << b << endl;
            break;
        default:
            cout << "Error: this is not 1 or 2 !" << endl;
    }
}