#include <iostream>
#include "Punto.h"

using namespace std;

int main()
{
    Punto p1;
    Punto p2(3,4);

    p1.print();
    p2.print();

    Vector vg(p1,p2);
    vg.print();
    return 0;
}

//
