#include <iostream>
using namespace std;

// Función recursiva para imprimir matriz usando punteros
void imprimirMatrizRec(int* M, int filas, int cols, int fila = 0, int col = 0) {
    if (fila == filas) return; // Caso base: terminamos todas las filas

    cout << *(M + fila * cols + col) << " ";

    if (col == cols - 1) {
        cout << endl;
        imprimirMatrizRec(M, filas, cols, fila + 1, 0);
    } else {
        imprimirMatrizRec(M, filas, cols, fila, col + 1);
    }
}

// Función para imprimir matriz iterativamente usando punteros
void imprimirMatrizIter(int* M, int filas, int cols) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            cout << *(M + i * cols + j) << " ";
        }
        cout << endl;
    }
}

// Función para transponer matriz usando punteros
void transponerMatriz(int* M, int* T, int filas, int cols) {
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < cols; j++)
            *(T + j * filas + i) = *(M + i * cols + j);
}

int main() {
    const int filas = 3;
    const int cols = 4;

    int M[filas][cols] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12}
    };

    int T[cols][filas]; // matriz transpuesta

    cout << "Matriz original (iterativa con punteros):\n";
    imprimirMatrizIter(&M[0][0], filas, cols);

    cout << "\nMatriz original (recursiva con punteros):\n";
    imprimirMatrizRec(&M[0][0], filas, cols);

    // Transponer matriz
    transponerMatriz(&M[0][0], &T[0][0], filas, cols);

    cout << "\nMatriz transpuesta (iterativa con punteros):\n";
    imprimirMatrizIter(&T[0][0], cols, filas);

    cout << "\nMatriz transpuesta (recursiva con punteros):\n";
    imprimirMatrizRec(&T[0][0], cols, filas);

    return 0;
}




