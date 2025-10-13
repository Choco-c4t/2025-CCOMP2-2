#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int filas = 8, cols = 8;
    // Crear matriz dinámica
    char** matriz = new char*[filas];
    for (int i = 0; i < filas; i++)
        matriz[i] = new char[cols];

    // Crear arreglos dinámicos para minusculas, mayusculas y numeros
    char* minusculas = new char[filas * cols];
    char* mayusculas = new char[filas * cols];
    char* numeros = new char[filas * cols];

    int idxMin = 0, idxMay = 0, idxNum = 0;

    // Llenar matriz y arreglos
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            int tipo = rand() % 3;
            if (tipo == 0) {
                matriz[i][j] = 'a' + rand() % 26;
                minusculas[idxMin++] = matriz[i][j];
            } else if (tipo == 1) {
                matriz[i][j] = 'A' + rand() % 26;
                mayusculas[idxMay++] = matriz[i][j];
            } else {
                matriz[i][j] = '0' + rand() % 10;
                numeros[idxNum++] = matriz[i][j];
            }
        }
    }

    // Imprimir matriz original
    cout << "Matriz original:\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }

    // Ordenar minusculas ascendente
    for (int i = 0; i < idxMin; i++)
        for (int j = i + 1; j < idxMin; j++)
            if (minusculas[i] > minusculas[j])
                swap(minusculas[i], minusculas[j]);

    // Ordenar mayusculas descendente
    for (int i = 0; i < idxMay; i++)
        for (int j = i + 1; j < idxMay; j++)
            if (mayusculas[i] < mayusculas[j])
                swap(mayusculas[i], mayusculas[j]);

    // Ordenar numeros ascendente
    for (int i = 0; i < idxNum; i++)
        for (int j = i + 1; j < idxNum; j++)
            if (numeros[i] > numeros[j])
                swap(numeros[i], numeros[j]);

    // Volver a llenar la matriz con el orden deseado
    int k = 0;
    for (int i = 0; i < idxMin; i++)
        matriz[k / cols][k % cols] = minusculas[i], k++;
    for (int i = 0; i < idxMay; i++)
        matriz[k / cols][k % cols] = mayusculas[i], k++;
    for (int i = 0; i < idxNum; i++)
        matriz[k / cols][k % cols] = numeros[i], k++;

    // Imprimir matriz ordenada
    cout << "\nMatriz ordenada:\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }

    // Liberar memoria dinámica
    for (int i = 0; i < filas; i++)
        delete[] matriz[i];
    delete[] matriz;
    delete[] minusculas;
    delete[] mayusculas;
    delete[] numeros;

    return 0;
}

