#include "exercise1.h"
#include <iostream>
using namespace std;

void sumOfTwoIntegers(){
    int val1, val2;
    int result;
    bool sign;
    cout << "Enter two integers: ";
    cin >> val1;
    cin >> val2;
    result = val1 + val2;
    cout << val1 << " + " << val2 << " = " << result << endl;
    if (result > 0){
        sign = true;
    }
    else {
        sign = false;
    }
    cout << "Is the result positive ? " << boolalpha << sign << " !" << endl;
}