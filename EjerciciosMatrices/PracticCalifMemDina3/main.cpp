#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 10;

// Función para llenar matriz dinámica
void llenarMatriz(int** matriz) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            matriz[i][j] = rand() % 101;
}

// Mostrar matriz dinámica
void mostrarMatriz(int** matriz) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << matriz[i][j] << "\t";
        cout << endl;
    }
}

// Comprobar si es primo
bool esPrimo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0) return false;
    return true;
}

// Convertir matriz a arreglo
void matrizToArray(int** matriz, int* arr, int &tam) {
    tam = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            arr[tam++] = matriz[i][j];
}

// Ordenar arreglo de mayor a menor
void ordenarMayorMenor(int* arr, int tam) {
    for (int i = 0; i < tam; i++)
        for (int j = i + 1; j < tam; j++)
            if (arr[j] > arr[i]) {
                int aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
}

// Separar primos y no primos
void separarPrimos(int* arr, int tam, int* primos, int &tamP, int* noPrimos, int &tamNP) {
    tamP = tamNP = 0;
    for (int i = 0; i < tam; i++) {
        if (esPrimo(arr[i]))
            primos[tamP++] = arr[i];
        else
            noPrimos[tamNP++] = arr[i];
    }
}

// Llenar nueva matriz con primos primero
void llenarNuevaMatriz(int* primos, int tamP, int* noPrimos, int tamNP, int** nueva) {
    int k = 0;
    // Primero primos
    for (int i = 0; i < N && k < tamP; i++)
        for (int j = 0; j < N && k < tamP; j++)
            nueva[i][j] = primos[k++];
    // Luego no primos
    int m = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (k < N * N) { // posiciones restantes
                if (i*N + j >= tamP) {
                    nueva[i][j] = noPrimos[m++];
                    k++;
                }
            }
}

int main() {
    srand(time(NULL));

    // Crear matriz dinámica
    int** matriz = new int*[N];
    int** nuevaMatriz = new int*[N];
    for (int i = 0; i < N; i++) {
        matriz[i] = new int[N];
        nuevaMatriz[i] = new int[N];
    }

    // Crear arreglos dinámicos
    int* arr = new int[N*N];
    int* primos = new int[N*N];
    int* noPrimos = new int[N*N];
    int tam, tamP, tamNP;

    // Llenar matriz original
    llenarMatriz(matriz);
    cout << "Matriz original:\n";
    mostrarMatriz(matriz);

    // Convertir a array y separar
    matrizToArray(matriz, arr, tam);
    separarPrimos(arr, tam, primos, tamP, noPrimos, tamNP);

    // Ordenar
    ordenarMayorMenor(primos, tamP);
    ordenarMayorMenor(noPrimos, tamNP);

    // Llenar nueva matriz
    llenarNuevaMatriz(primos, tamP, noPrimos, tamNP, nuevaMatriz);

    cout << "\nMatriz nueva:\n";
    mostrarMatriz(nuevaMatriz);

    // Liberar memoria
    for (int i = 0; i < N; i++) {
        delete[] matriz[i];
        delete[] nuevaMatriz[i];
    }
    delete[] matriz;
    delete[] nuevaMatriz;
    delete[] arr;
    delete[] primos;
    delete[] noPrimos;

    return 0;
}

