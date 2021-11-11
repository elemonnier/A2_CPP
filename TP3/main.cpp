#include <iostream>
#include "exercise1.h"

void test1(){ /// 0/0
    Point p;
}
void test2(){ /// error
    Point p();
}
void test3(){ /// 1/2
    Point p(1,2);
}
void test4(){ /// 4/8
    Point p(4);
}
void test5(){ /// 0/0
    Point* p = new Point;
}
void test6(){ /// 0/0
    Point* p = new Point();
}
void test7(){ /// 4/8
    Point* p = new Point(4);
}
void test8(){ /// 1/2
    Point* p = new Point(1,2);
}

void test9(){ /// 1/2
    Point p = {1,2};
}

void test10(){ /// 1/2 1/2
    Point p1(1,2);
    Point p2 = p1;
}

void test11(){ /// 0/0 0/0
    Point p1(1,2);
    Point p2;
    p1 = p2;
}

void test12(){ /// 1/2 1/2
    Point* p1 = new Point(1,2);
    Point* p2 = p1;
}

int main() {
    test1();
//    test2();
//    test3();
//    test4();
//    test5();
//    test6();
//    test7();
//    test8();
//    test9();
//    test10();
//    test11();
//    test12();
    return 0;
}