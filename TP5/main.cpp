#include <iostream>

int pgcd(int a, int b) {
    if (a == b){
        return a;
    }
    return pgcd(b, a-b);
}

int main() {
//    int a = 20;/
//    int b = 5;
    int a = pgcd(20, 5);
    std::cout << a;
    return 0;
}