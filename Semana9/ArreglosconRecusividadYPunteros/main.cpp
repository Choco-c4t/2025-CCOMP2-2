#include <iostream>
using namespace std;

// 🧩 1. Sumar elementos de un arreglo usando puntero++
int SumarRecursivo(int* ptr, int n) {
    if (n == 0)
        return 0;

    int valor = *ptr;  // toma el valor actual
    ptr++;              // mueve el puntero al siguiente elemento
    return valor + SumarRecursivo(ptr, n - 1);
}

// 🧩 2. Mostrar los elementos en orden inverso usando puntero++
void InversoRecursivo(int* ptr, int n) {
    if (n == 0)
        return;

    InversoRecursivo(ptr + 1, n - 1); // avanza primero
    cout << *ptr << " ";              // imprime al volver
}

// 🧩 3. Contar cuántas veces aparece un número
int ContarRecursivo(int* ptr, int n, int numero) {
    if (n == 0)
        return 0;

    int conteo = (*ptr == numero) ? 1 : 0;
    ptr++;
    return conteo + ContarRecursivo(ptr, n - 1, numero);
}

// 🧩 4. Duplicar cada elemento del arreglo usando puntero++
void DuplicarRecursivo(int* ptr, int n) {
    if (n == 0)
        return;

    *ptr *= 2;   // duplica el valor actual
    DuplicarRecursivo(ptr + 1, n - 1);
}

// 🧩 5. Mostrar arreglo (normal, no recursivo, para ver resultados)
void Mostrar(int* ptr, int n) {
    for (int i = 0; i < n; i++)
        cout << *(ptr + i) << " ";
    cout << endl;
}

int main() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int* p = arr; // 🔹 puntero que apunta al arreglo

    cout << "---------------- Sumar elementos ----------------" << endl;
    cout << "Suma: " << SumarRecursivo(p, 6) << endl;

    cout << "\n---------------- Mostrar inverso ----------------" << endl;
    InversoRecursivo(p, 6);
    cout << endl;

    cout << "\n---------------- Contar ocurrencias ----------------" << endl;
    int numero = 3;
    cout << "El numero " << numero << " aparece "
         << ContarRecursivo(p, 6, numero) << " veces." << endl;

    cout << "\n---------------- Duplicar elementos ----------------" << endl;
    DuplicarRecursivo(p, 6);
    Mostrar(p, 6);

    return 0;
}
