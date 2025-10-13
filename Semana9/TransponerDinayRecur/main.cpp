#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Funci�n recursiva para transponer
void transponerRecursivo(int** A, int** T, int fila, int col, int filas, int cols) {
    if (fila == filas) return;        // Caso base: terminamos todas las filas
    if (col == cols) {                // Fin de una fila
        transponerRecursivo(A, T, fila + 1, 0, filas, cols);
        return;
    }

    T[col][fila] = A[fila][col];      // Copiar elemento a la transpuesta
    transponerRecursivo(A, T, fila, col + 1, filas, cols);
}

// Funci�n recursiva para imprimir la matriz
void imprimirMatrizRec(int** M, int fila, int col, int filas, int cols) {
    if (fila == filas) return;
    if (col == cols) {
        cout << endl;
        imprimirMatrizRec(M, fila + 1, 0, filas, cols);
        return;
    }

    cout << M[fila][col] << " ";
    imprimirMatrizRec(M, fila, col + 1, filas, cols);
}

int main() {

    //Crear matrice y realizar su transpuesta con memoria dinamica
    srand(time(nullptr));

    int filas, columnas;
    cout << "Ingrese el n�mero de filas: ";
    cin >> filas;
    cout << "Ingrese el n�mero de columnas: ";
    cin >> columnas;

    // Crear matriz din�mica original
    int** matriz = new int*[filas];
    for (int i = 0; i < filas; ++i)
        matriz[i] = new int[columnas];

    // Llenar con n�meros aleatorios del 1 al 9
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = 1 + rand() % 9;
        }
    }

    // Mostrar matriz original
    cout << "\nMATRIZ ORIGINAL:\n";
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j)
            cout << matriz[i][j] << " ";
        cout << endl;
    }

    // Crear matriz transpuesta
    int** transpuesta = new int*[columnas];
    for (int i = 0; i < columnas; ++i)
        transpuesta[i] = new int[filas];

    // Calcular transpuesta
    for (int i = 0; i < filas; ++i)
        for (int j = 0; j < columnas; ++j)
            transpuesta[j][i] = matriz[i][j];

    // Mostrar matriz transpuesta
    cout << "\nMATRIZ TRANSPUESTA:\n";
    for (int i = 0; i < columnas; ++i) {
        for (int j = 0; j < filas; ++j)
            cout << transpuesta[i][j] << " ";
        cout << endl;
    }

    // Liberar memoria
    for (int i = 0; i < filas; ++i)
        delete[] matriz[i];
    delete[] matriz;

    for (int i = 0; i < columnas; ++i)
        delete[] transpuesta[i];
    delete[] transpuesta;


// Transponer Recursivamente:

    int filass = 3, cols = 4;

    // Crear matriz din�mica
    int** A = new int*[filass];
    for (int i = 0; i < filass; i++)
        A[i] = new int[cols];

    // Asignar valores fijos a la matriz din�mica
    int valores[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12}
    };

    for (int i = 0; i < filass; i++)
        for (int j = 0; j < cols; j++)
            A[i][j] = valores[i][j];

    cout << "Matriz original:\n";
    imprimirMatrizRec(A, 0, 0, filass, cols);

    // Crear matriz transpuesta din�mica
    int** T = new int*[cols];
    for (int i = 0; i < cols; i++)
        T[i] = new int[filass];

    // Transponer
    transponerRecursivo(A, T, 0, 0, filass, cols);

    cout << "\nMatriz transpuesta:\n";
    imprimirMatrizRec(T, 0, 0, cols, filass);

    // Liberar memoria
    for (int i = 0; i < filass; i++) delete[] A[i];
    delete[] A;
    for (int i = 0; i < cols; i++) delete[] T[i];
    delete[] T;

    return 0;
}
