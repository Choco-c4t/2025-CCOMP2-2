#include <iostream>
#include "IntegerArray.h"

using namespace std;

int main()
{
    IntegerArray array1(3);
    array1.setData(10,0);
    array1.setData(20,1);
    array1.setData(30,2);
    array1.print();

    return 0;
}
