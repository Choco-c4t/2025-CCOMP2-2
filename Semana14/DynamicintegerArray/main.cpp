#include <iostream>
#include "DinamicIntegerArray.h"

using namespace std;

int main()
{
    DynamicIntegerArray da;
    da.print();
    da.push_back(1);
    da.push_back(2);
    da.push_back(3);
    da.push_back(4);
    da.push_back(5);
    cout<<endl;
    da.print();

    if(true){
        DynamicIntegerArray b = da; //construir un objeto por copia
    }

    cout<<endl;
    da.print();
    return 0;
}
