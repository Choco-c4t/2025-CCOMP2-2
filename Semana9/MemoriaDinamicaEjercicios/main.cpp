#include <iostream>

using namespace std;


/*
*Memoria dinamica:
*   Reservar 1 valor ->	int* p = new int;
*   Liberar 1 valor	-> delete p;
*   Reservar arreglo ->	int* a = new int[n];
*   Liberar arreglo	-> delete[] a;
*/
int main()
{
    int num = 3;
    int* puntero = nullptr;  // Reserva espacio para 1 entero
    puntero = new num;           // Asigna un valor a esa posición

    cout << "Valor: " << *puntero << endl;

    delete puntero;          // Libera la memoria
    puntero = nullptr;       // Buen hábito: anular el puntero

    return 0;
}
