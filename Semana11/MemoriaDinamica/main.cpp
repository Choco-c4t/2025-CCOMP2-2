#include <iostream>

using namespace std;

/**
* Operador new ->   tipo de dato *ptr = new tipodedato;
*       sirve para reservar memoria para una variable/objeto
*Operador delete
*       sirve para liberar la memoria de una variable/objeto
*/

int* fun(){
    int *ptr = new int;
    *ptr = 10;
    return ptr;
}

int main()
{
    int *ptr= fun(); //La direccion de la memoria es indeterminado, ya que al ser una funcion se borro.
    cout <<*ptr<<endl;

    delete ptr;
    /*int* ptr;
    if(true){
        int x=10;
        ptr =&x;
    }               //Luego de la condicion sigue existiendo el espacio de memoria de X, pero es indeterminada
    cout<< *ptr<<endl;
    */

    return 0;
}
