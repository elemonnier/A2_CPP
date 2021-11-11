#include <iostream>
#include "exercise1.h"
#include "exercise2.h"
#include "exercise3.h"
#include "exercise4.h"
#include "exercise5.h"
using namespace std;

void tests(){
    int choice;
    cout << "Hello ! Which algorithm would you like to test (type a number) ?\n1) Sum of two integers\n2) Average values of an array\n3) Max of numbers\n4) Swap variables\n5) Sum between two integers" << endl;
    cin >> choice;
    switch (choice){
        case 1:
            sumOfTwoIntegers();
            break;
        case 2:
            averageValuesOfAnArray();
            break;
        case 3:
            maxTests();
            break;
        case 4:
            swapVariablesTests();
            break;
        case 5:
            sumTests();
            break;
        default:
            cout << "Error: you entered a wrong number !";
    }
}

int main() {
    tests();
    return 0;
}