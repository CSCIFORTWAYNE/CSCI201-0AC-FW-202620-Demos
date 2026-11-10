#include <iostream>
#include "clock.h"

int main()
{

    int *p = nullptr;
    int q = 7;
    p = &q;

    std::cout << &q << std::endl;
    std::cout << *p << std::endl;

    Clock *c = nullptr;
    std::cout << c << std::endl;
    // c->incrementSeconds();
    // std::cout << c->printTime() << std::endl;

    Clock c1(18, 40, 00);
    c = &c1;
    (*c).incrementMinutes();
    std::cout << c1.printTime() << std::endl;
    std::cout << c->printTime() << std::endl;
}