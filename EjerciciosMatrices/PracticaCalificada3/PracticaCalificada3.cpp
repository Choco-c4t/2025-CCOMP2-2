#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 10;

void llenarMatriz(int matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = rand() % 101;
        }
    }
}

void mostrarMatriz(int matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

bool esPrimo(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void matrizToArray(int matriz[N][N], int arr[], int &tam) {
    tam = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[tam] = matriz[i][j];
            tam++;
        }
    }
}

void ordenarMayorMenor(int arr[], int tam) {
    for (int i = 0; i < tam; i++) {
        for (int j = i+1; j < tam; j++) {
            if (arr[j] > arr[i]) {
                int aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

void separarPrimos(int arr[], int tam, int primos[], int &tamP, int noPrimos[], int &tamNP) {
    tamP = 0;
    tamNP = 0;
    for (int i = 0; i < tam; i++) {
        if (esPrimo(arr[i])) {
            primos[tamP] = arr[i];
            tamP++;
        } else {
            noPrimos[tamNP] = arr[i];
            tamNP++;
        }
    }
}

void llenarNuevaMatriz(int primos[], int tamP, int noPrimos[], int tamNP, int nueva[N][N]) {
    int k = 0;
    for (int i = 0; i < N && k < tamP; i++) {
        for (int j = 0; j < N && k < tamP; j++) {
            nueva[i][j] = primos[k];
            k++;
        }
    }
    int m = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (nueva[i][j] == 0 && !(i < (tamP/N) + 1 && j < N)) {
                if (m < tamNP) {
                    nueva[i][j] = noPrimos[m];
                    m++;
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int matriz[N][N], nuevaMatriz[N][N];
    int arr[100], primos[100], noPrimos[100];
    int tam, tamP, tamNP;

    llenarMatriz(matriz);
    cout << "Matriz original:\n";
    mostrarMatriz(matriz);

    matrizToArray(matriz, arr, tam);
    separarPrimos(arr, tam, primos, tamP, noPrimos, tamNP);

    ordenarMayorMenor(primos, tamP);
    ordenarMayorMenor(noPrimos, tamNP);
    int k = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (k < tamP) {
                nuevaMatriz[i][j] = primos[k];
                k++;
            } else {
                nuevaMatriz[i][j] = noPrimos[k - tamP];
                k++;
            }
        }
    }

    cout << "Matriz nueva:\n";
    mostrarMatriz(nuevaMatriz);

    return 0;
}

