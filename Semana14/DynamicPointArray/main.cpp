#include <iostream>
#include "Point.h"
using namespace std;

int main()
{
    //arreglo de puntos;
    Point p1(2,3);
    Point p2(4,5);
    Point p3(6,7);
    Point arr[4] = {p1,p2,p3};
    for(int i=0; i < 3;i++){
        arr[i].print();
    }


    return 0;
}
