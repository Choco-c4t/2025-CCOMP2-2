#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Funciones de ordenamiento manual
void ordenarAsc(char* arr, int n) {
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (arr[j] > arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

void ordenarDesc(char* arr, int n) {
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (arr[j] < arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int main() {
    srand(time(0));

    const int filas = 4;
    const int columnas = 7;
    const int centro = columnas / 2;

    // Crear matriz dinámica
    char** matriz = new char*[filas];
    for (int i = 0; i < filas; ++i)
        matriz[i] = new char[columnas];

    // Llenado del triángulo centrado
    for (int i = 0; i < filas; ++i) {
        int inicio = centro - i;
        int fin = centro + i;
        if (inicio < 0) inicio = 0;
        if (fin >= columnas) fin = columnas - 1;

        int izq_count = inicio;
        int der_count = columnas - fin - 1;

        char* izq = new char[izq_count];
        char* der = new char[der_count];

        // Generar letras aleatorias
        for (int j = 0; j < izq_count; ++j)
            izq[j] = 'A' + rand() % 26;
        for (int j = 0; j < der_count; ++j)
            der[j] = 'A' + rand() % 26;

        // Ordenar manualmente
        ordenarAsc(izq, izq_count);
        ordenarDesc(der, der_count);

        // Colocar en la matriz
        for (int j = 0; j < izq_count; ++j) matriz[i][j] = izq[j];
        for (int j = inicio; j <= fin; ++j) matriz[i][j] = '*'; // triángulo
        for (int j = 0; j < der_count; ++j) matriz[i][fin + 1 + j] = der[j];

        delete[] izq;
        delete[] der;
    }

    // Mostrar la matriz
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j)
            cout << matriz[i][j] << ' ';
        cout << '\n';
    }

    // Liberar memoria
    for (int i = 0; i < filas; ++i) delete[] matriz[i];
    delete[] matriz;

    return 0;
}






