#include "exercise2.h"
#include <iostream>
using namespace std;

void averageValuesOfAnArray(){
    auto n = 0;
    int sum = 0;
    cout << "Enter a positive value to build an array: ";
    cin >> n;
    if (n > 0){
        int *array = new int[n];
        cout << "Enter your " << n << " values: " << endl;
        for (int i = 0; i < n; i++) {
            cin >> array[i];
            sum += array[i];
        }
        int average = sum / n;
        cout << "The average of your array is: " << average << endl;
        delete[] array;
    }
    else {
        cout << "Error: this is not a positive value ! " << endl;
    }
}
