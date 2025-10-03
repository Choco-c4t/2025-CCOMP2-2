#include <iostream>

using namespace std;

/**
* El nombre de un arreglo es un puntero al primer elemento del arreglo
*
*   ARITMETICA DE PUNTEROS
* ============================
* A los punteros se les puede incrementar/decrementar usando los operadores ++ / --, respectivamente.
*/
int main()
{
    cout << "=============================="<<endl;
    int arr[] ={1,2,3,4,5};
    cout << arr << endl; //->direccion de arr[0]
    cout << &arr[0]<< endl; //->direccion de arr[0]
    cout << &arr[1]<< endl; //->direccion de arr[1]
    cout << &arr[2]<< endl; //->direccion de arr[2]
    cout << &arr[3]<< endl; //->direccion de arr[3]
    cout << &arr[4]<< endl; //->direccion de arr[4]

    cout << "=============================="<<endl;
    int* ptr;
    ptr = &arr[0];
    ptr = arr; //expresiones son lo mismo
    cout<<*ptr<<endl; //-->1
    ptr++;
    cout <<*ptr << endl; //-->2
    ptr++;
    cout<<*ptr<<endl; //-->3
    ptr++;
    cout<<*ptr<<endl; //-->4
    ptr++;
    cout<<*ptr<<endl; //-->5
    ptr++;
    //se pueden recorrer los elementos de un arreglo usando un puntero.

    cout << "=============================="<<endl;
    int* ptr2= arr;
    for (int i=0; i < 5;i++ , ptr2++){
        cout << *ptr2 << " ";
    cout<< endl;
    }

    cout << "=============================="<<endl;
//Para imprimir el valor de cada elemento
    cout<<*(arr+0)<<endl;
    cout<<*(arr+2)<<endl;
    cout<<*(arr+3)<<endl;
    cout<<*(arr+4)<<endl;

    cout << "=============================="<<endl;
//Imprimir de menor a mayor (con for)

    int *ptr3 = arr+4;
    for(int i=0;i<5;i++, ptr3--){
        cout<< *ptr3 <<""<<endl;
    }

    cout << "=============================="<<endl;
// Imprimir de menor a mayor (con while)
    int *ptr4 = arr; //apunta al 1er elemento
    while (ptr4 < (arr+5)){
        cout<<*ptr4<<""<<endl;
        ptr4++;
    } //luego de cumplir el while, el puntero apunta a una direccion DESPUES que la del ultimo elemento |_1_|_2_|_3_|_4_|_5_|_ptr4_|

    cout << "=============================="<<endl;
// Imprimir de mayor a menor (con while)
    int *ptr5 = arr+4; //apunta al ultimo elemento
    while(ptr5 >= arr){
        cout << *ptr5 << ""<<endl;
        ptr5--;
    } //luego de cumplir el while, el puntero apunta a una direccion ANTES que la del primer elemento |_ptr5_|_1_|_2_|_3_|_4_|_5_|

    return 0;
}
