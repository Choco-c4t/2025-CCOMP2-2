#include <iostream>

using namespace std;

/**
*    PUNTEROS
*   ==========
*Es una variable que almacena DIRECCIONES DE MEMORIA de otra variable del mismo ti´p
*Para declarar un puntero -> Tipo_de_dato* = Nombre_puntero
*
* -Operador de direccion: (&)
*   Sirve para obtener la direccion de memoria de una variable/objeto.
*   Operador unario. Ejm: &var -> me retorna la direccion de la variable var.
*
* -Operador de indireccion: (*)
*   Sirve para obtener el valor de una direccion de memoria.
*   Operador unario. Ejm: *ptr -> me retorna el valor de la variable ptr
*/
int main()
{
    int* ptr1; //declarar la variable de tipo puntero a entero
    int x; //declarando la variable x
    x = 10; //Inicializando la variable x con el valor 10
    ptr1 = &x; //Asignarle la direccion de x al puntero
    cout << "=============================="<<endl;
    cout << "Direccion de la variable x: "<< &x << endl; //--> direccion de x
    cout << "Direccion de la variable ptr: "<< ptr1 << endl; //--> direccion de x
    cout << "El valor de la direccion de la variable ptr es: "<< *ptr1 << endl; //--> 10

/**
* En la memoria ram. (todas las variables tiene direccion de memoria)
*ptr| xx06| -> xx04            osea:            ptr | xx10| xx06     osea:
*    -----                     ptr -----> x          -----
*  x| 10  | -> xx08                               y | 20  | xx10     ptr -----> y
*    -----                                           -----
*   |     |                                         |     |
*    -----                                           -----
*   |     |
*    -----
**/
    int y =20;  //los punteros pueden cambiar de "variable"
    ptr1 = &y;
    cout << "=============================="<<endl;
    cout<<"Direccion de la variable y es: " << ptr1<<endl;
    cout << "El valor de la direccion de la variable ptr es "<<*ptr1 <<endl;


    int z = 100;
    ptr1 = &z;
    cout << "=============================="<<endl;
    cout<<"Direccion de la variable z es: " << ptr1<<endl;
    cout << "El valor de la direccion de la variable ptr es "<<*ptr1 <<endl;

    int* ptr2;
    ptr2 = &z;

    cout << "=============================="<<endl;
    if (ptr1 == ptr2){
        cout << "ptr1 y ptr2 tienen el mismo valor" <<endl;
    }
    cout << "=============================="<<endl;
    if (*ptr1 == *ptr2){
        cout << "ptr1 tiene el valor de: " <<*ptr1<< " y ptr2 tiene el valor de: " << *ptr2 <<endl;
    }
    return 0;
}
