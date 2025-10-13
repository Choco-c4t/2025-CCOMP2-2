#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Función para llenar la matriz con caracteres aleatorios
void llenarMatriz(char** matriz, char* minusculas, char* mayusculas, char* numeros,
                  int& contMin, int& contMay, int& contNum) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int tipo = rand() % 3; //0=minusculas,1=mayusculas,2=numeros
            char c;

            if (tipo == 0) {
                c = 'a' + rand() % 26;
                minusculas[contMin++] = c;
            } else if (tipo == 1) {
                c = 'A' + rand() % 26;
                mayusculas[contMay++] = c;
            } else {
                c = '0' + rand() % 10;
                numeros[contNum++] = c;
            }

            matriz[i][j] = c;
        }
    }
}

// Mostrar matriz
void mostrarMatriz(char** matriz) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }
}

// Ordenamiento de arrays
void ordenar(char* arr, int n, bool asc = true) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((asc && arr[i] > arr[j]) || (!asc && arr[i] < arr[j])) {
                char temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Llenar la matriz ordenada
void llenarMatrizOrdenada(char** matriz, char* minusculas, char* mayusculas, char* numeros,
                          int contMin, int contMay, int contNum) {
    int idx = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (idx < contMin)
                matriz[i][j] = minusculas[idx];
            else if (idx < contMin + contMay)
                matriz[i][j] = mayusculas[idx - contMin];
            else
                matriz[i][j] = numeros[idx - contMin - contMay];
            idx++;
        }
    }
}

int main() {
    srand(time(0));

    // Crear matriz dinámica
    char** matriz = new char*[8];
    for (int i = 0; i < 8; i++)
        matriz[i] = new char[8];

    // Crear arreglos dinámicos
    char* minusculas = new char[64];
    char* mayusculas = new char[64];
    char* numeros = new char[64];
    int contMin = 0, contMay = 0, contNum = 0;

    llenarMatriz(matriz, minusculas, mayusculas, numeros, contMin, contMay, contNum);

    cout << "Matriz original:\n";
    mostrarMatriz(matriz);

    // Ordenar
    ordenar(minusculas, contMin, true); // ascendente
    ordenar(mayusculas, contMay, false); // descendente
    ordenar(numeros, contNum, true); // ascendente

    // Llenar matriz ordenada
    llenarMatrizOrdenada(matriz, minusculas, mayusculas, numeros, contMin, contMay, contNum);

    cout << "Matriz ordenada:\n";
    mostrarMatriz(matriz);

    // Liberar memoria
    for (int i = 0; i < 8; i++)
        delete[] matriz[i];
    delete[] matriz;
    delete[] minusculas;
    delete[] mayusculas;
    delete[] numeros;

    return 0;
}

