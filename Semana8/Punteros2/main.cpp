#include <iostream>

using namespace std;

int main()
{
    cout << "=============================="<<endl;
    int* ptr1;
    //cout << *ptr1 <<endl; -->se quiere imprimir el valor del ptr1, pero aqui no tiene nada
    int x =10;
    ptr1 = &x;
    cout << *ptr1 <<endl; //--> todo puntero tiene que apuntar a una variable

    cout << "=============================="<<endl;
    *ptr1= 1000;
    cout << x << endl; //--> 1000 porq cambia el valor de x atravez del puntero ptr1 (*ptr1 == x)

    cout << "=============================="<<endl;
    int *ptr2 = &x;
    *ptr2 =5000;
    cout << x << endl;
    cout <<*ptr1 << endl; //--> 5000
    cout << *ptr2 << endl;//--> 5000, los dos punteros apuntan a la misma variable, por lo q si se cambia x, se cambia el valor de los dos punteros

    cout << "=============================="<<endl;
    double y = 14.5;
    double *ptr3 = &y; //
    cout << *ptr3 << endl; //-->14.5
    *y = 3.14 ;
    cout << *ptr3 << endl; //-->3.14



    return 0;
}
