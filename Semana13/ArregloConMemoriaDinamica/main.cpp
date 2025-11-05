#include <iostream>
#include "DinamicInteguerArray.h"

using namespace std;

int main()
{
    DinamicInteguerArray dia;
    cout<< dia.getsize()<<endl;
    dia.print();

    int arr[]={1,2,3,4,5};
    DinamicInteguerArray dia2(arr,2);
    cout<<dia2.getsize()<<endl;
    dia2.print();
    return 0;
}
