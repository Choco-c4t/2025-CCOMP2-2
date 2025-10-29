#include <iostream>
#include "Punto.h"
using namespace std;

/**
*   Constructor
*       Es el metodo que se invoca cuando se crea una instancia
*       Es el metodo que se invoca cuando se asigna memoria a una instancia
*
*   Destructor (tiene el mismo nombre que la clase, pero la anteede (colita de chancho)
*       Es el metodo que se invoca cuando se libera la memoria
*
*/
int main()
{
    Punto p1;  //Creamos una instancia
    cout << endl;
    p1.print();
    cout << endl;

    Punto* ptr1 = new Punto; //reservar la memoria para un nuevo punto
    cout << endl;
    ptr1 -> print();  //flecha para los punteros al llamar una funcion de una clase (1ra forma)
    (*ptr1).print();  //utilizndo el operador de indireccion (2da forma)
    cout << endl;

    Punto p3(4,5);  //Creamos otra nueva instancia
    cout << endl;
    p3.print();
    cout << endl;

    Punto* ptr2 = new Punto(4,5); //reservar memoria para un nuevo punto con argumentos
    cout << endl;
    ptr2 -> print();
    (*ptr2).print();
    cout << endl;

    delete ptr1;
    delete ptr2;
    return 0;
}

//
