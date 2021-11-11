#include "exercise5.h"
#include <iostream>
using namespace std;

int sum1(int n){
    return (n * (n + 1)) / 2;
}

int sum2(int n, int k){
    return ((n * (n + 1)) / 2) - (((k - 1) * k) / 2);
}

void sum3(int n, int &s, int k){
    s = ((n * (n + 1)) / 2) - (((k - 1) * k) / 2);
}

void sum4(int n, int &s, int k){
    if (n >= k){
        s = ((n * (n + 1)) / 2) - (((k - 1) * k) / 2);
    }
}

void sum5(int n, int &a, bool &valid, int k){
    if (k <= n) {
        a = ((n * (n + 1)) / 2) - (((k - 1) * (k)) / 2);
        valid = true;
    }
    else {
        valid = false;
    }
}

void sumTests(){
    int s, k, n, choice;
    bool valid;
    cout << "Which function would you like to test ?\n1) sum1\n2) sum2\n3) sum3\n4) sum4\n5) sum5";
    cin >> choice;
    switch (choice) {
        case 1:
            cout << "Enter a positive integer: ";
            cin >> n;
            if (n < 1) {
                cout << "Error: this is not a positive integer !" << endl;
                return;
            }
            s = sum1(n);
            cout << "The result of the sum from 1 to " << n << " is: " << s << endl;
            break;
        case 2:
            cout << "Enter a positive integer: ";
            cin >> k;
            if (k < 1) {
                cout << "Error: this is not a positive integer !" << endl;
                return;
            }
            cout << "Enter an another positive integer which is bigger or equal than the previous one: ";
            cin >> n;
            if (n < 1) {
                cout << "Error: this is not a positive integer !" << endl;
                return;
            }
            s = sum2(n, k);
            if (n >= k) {
                cout << "The result of the sum from " << k << " to " << n << " is: " << s << endl;
            }
            else {
                cout << "Error: the second integer you entered is smaller than the first !";
            }
            break;
        case 3:
            cout << "Enter a positive integer: ";
            cin >> k;
            if (k < 1) {
                cout << "Error: this is not a positive integer !" << endl;
                return;
            }
            cout << "Enter an another positive integer which is bigger or equal than the previous one: ";
            cin >> n;
            if (n < 1) {
                cout << "Error: this is not a positive integer !" << endl;
                return;
            }
            sum3(n, s, k);
            if (n >= k) {
                cout << "The result of the sum from " << k << " to " << n << " is: " << s << endl;
            }
            else {
                cout << "Error: the second integer you entered is smaller than the first !" << endl;
            }
            break;
        case 4:
            cout << "Enter a positive integer: ";
            cin >> k;
            if (k < 1) {
                cout << "Error: this is not a positive integer !" << endl;
                return;
            }
            cout << "Enter an another positive integer which is bigger or equal than the previous one: ";
            cin >> n;
            if (n < 1) {
                cout << "Error: this is not a positive integer !" << endl;
                return;
            }
            sum4(n, s, k);
            if (k <= n) {
                cout << "The result of the sum from " << k << " to " << n << " is: " << s << endl;
            }
            else {
                cout << "Error: the second integer you entered is smaller than the first !" << endl;
            }
            break;
        case 5:
            cout << "Enter a positive integer: ";
            cin >> k;
            if (k < 1){
                cout << "Error: this is not a positive integer !" << endl;
                return;
            }
            cout << "Enter an another positive integer which is bigger or equal than the previous one: ";
            cin >> n;
            if (n < 1){
                cout << "Error: this is not a positive integer !" << endl;
                return;
            }
            sum5(n, s, valid, k);
            if (valid){
                cout << "The result of the sum from " << k << " to " << n << " is: " << s << endl;
            }
            else {
                cout << "Error: the second integer you entered is smaller than the first !" << endl;
            }
            break;
        default:
            cout << "Error: this is not an integer between 1 and 5 !";
            break;
    }
}
