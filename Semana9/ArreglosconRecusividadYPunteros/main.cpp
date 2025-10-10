#include <iostream>
using namespace std;

// 🧩 Sumar elementos de un arreglo usando puntero++
int SumarRecursivo(int* arr, int n) {
    if (n == 0)
        return 0;

    int valor = *arr; // guarda el valor actual
    arr++; // avanza al siguiente elemento
    return valor + SumarRecursivo(arr, n - 1);
}

// 🧩 Mostrar los elementos de un arreglo en orden inverso con puntero++
void InversoRecursivo(int* arr, int n) {
    if (n == 0)
        return;

    int* siguiente = arr + 1; // guardamos el puntero siguiente
    InversoRecursivo(siguiente, n - 1); // primero llamamos hacia adelante
    cout << *arr << " "; // al regresar de la recursión, imprimimos
}

// 🧩 Contar cuántas veces aparece un número en un arreglo con puntero++
int ContarRecursivo(int* arr, int n, int numero) {
    if (n == 0)
        return 0;

    int conteo = (*arr == numero) ? 1 : 0;
    arr++; // avanzamos el puntero
    return conteo + ContarRecursivo(arr, n - 1, numero);
}

int main() {
    cout << "---------------- Sumar elementos (puntero++) ----------------\n";
    int arr[6] = {1, 2, 3, 4, 5, 6};
    cout << "Suma: " << SumarRecursivo(arr, 6) << endl;

    cout << "\n---------------- Inverso (puntero++) ----------------\n";
    int arr2[5] = {10, 20, 30, 40, 50};
    InversoRecursivo(arr2, 5);
    cout << endl;

    cout << "\n---------------- Contar ocurrencias (puntero++) ----------------\n";
    int arr3[6] = {1, 3, 5, 3, 3, 7};
    int numero = 3;
    cout << "El numero " << numero << " aparece " << ContarRecursivo(arr3, 6, numero) << " veces.\n";

    return 0;
}
