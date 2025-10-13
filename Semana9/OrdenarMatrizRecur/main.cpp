#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void caratula() {
    cout << "=== MATRIZ DE LETRAS Y NUMEROS DINAMICA (RECURSIVA) ===\n";
}

// -------------------- Generar arrays recursivamente --------------------
void generarMayusculas(char tmp[], int idx, int n) {
    if (idx == n) return;
    tmp[idx] = 65 + rand() % 26;
    cout << "Letra mayuscula: " << tmp[idx] << endl;
    generarMayusculas(tmp, idx + 1, n);
}

void generarMinusculas(char tmp[], int idx, int n) {
    if (idx == n) return;
    tmp[idx] = 97 + rand() % 26;
    cout << "Letra minuscula: " << tmp[idx] << endl;
    generarMinusculas(tmp, idx + 1, n);
}

void generarNumeros(char tmp[], int idx, int n) {
    if (idx == n) return;
    tmp[idx] = 48 + rand() % 10;
    cout << "Numero: " << tmp[idx] << endl;
    generarNumeros(tmp, idx + 1, n);
}

// -------------------- Llenar matriz aleatoria recursivamente --------------------
void llenarMatrizAleatoria(char** M, int i, int j, int filas, int cols,
                           char tmpMayus[], char tmpMinus[], char tmpNum[],
                           int& idxMayus, int& idxMinus, int& idxNum) {
    if (i == filas) return;
    if (j == cols) {
        llenarMatrizAleatoria(M, i + 1, 0, filas, cols, tmpMayus, tmpMinus, tmpNum, idxMayus, idxMinus, idxNum);
        return;
    }

    bool asignado = false;
    while (!asignado) {
        int option = rand() % 3;
        switch(option) {
            case 0:
                if (idxMayus < 6) { M[i][j] = tmpMayus[idxMayus++]; asignado = true; } break;
            case 1:
                if (idxMinus < 6) { M[i][j] = tmpMinus[idxMinus++]; asignado = true; } break;
            case 2:
                if (idxNum < 4) { M[i][j] = tmpNum[idxNum++]; asignado = true; } break;
        }
    }

    llenarMatrizAleatoria(M, i, j + 1, filas, cols, tmpMayus, tmpMinus, tmpNum, idxMayus, idxMinus, idxNum);
}

// -------------------- Imprimir matriz recursivamente --------------------
void imprimirMatrizRec(char** M, int i, int j, int filas, int cols) {
    if (i == filas) return;
    if (j == cols) {
        cout << endl;
        imprimirMatrizRec(M, i + 1, 0, filas, cols);
        return;
    }
    cout << M[i][j] << " | ";
    imprimirMatrizRec(M, i, j + 1, filas, cols);
}

// -------------------- Reordenar matriz recursivamente --------------------
void reordenarMatriz(char** M, char** Ordenado, int i, int j,
                     int filas, int cols,
                     char tmpMayus[], char tmpMinus[], char tmpNum[],
                     int& idxMayus, int& idxMinus, int& idxNum) {
    if (i == filas) return;
    if (j == cols) {
        reordenarMatriz(M, Ordenado, i + 1, 0, filas, cols, tmpMayus, tmpMinus, tmpNum, idxMayus, idxMinus, idxNum);
        return;
    }

    Ordenado[i][j] = '-';

    // Primer paso: cuadrantes
    if (i < 2 && j < 2) Ordenado[i][j] = tmpMayus[idxMayus++];
    else if (i >= 2 && j >= 2) Ordenado[i][j] = tmpMinus[idxMinus++];

    // Segundo paso: completar cuadrantes faltantes
    if (i < 2 && j >= 2 && Ordenado[i][j] == '-' && idxMayus < 6) Ordenado[i][j] = tmpMayus[idxMayus++];
    else if (i >= 2 && j < 2 && Ordenado[i][j] == '-' && idxMinus < 6) Ordenado[i][j] = tmpMinus[idxMinus++];

    // Tercer paso: llenar números
    if (((i < 2 && j >= 2) || (i >= 2 && j < 2)) && Ordenado[i][j] == '-' && idxNum < 4)
        Ordenado[i][j] = tmpNum[idxNum++];

    reordenarMatriz(M, Ordenado, i, j + 1, filas, cols, tmpMayus, tmpMinus, tmpNum, idxMayus, idxMinus, idxNum);
}

// -------------------- MAIN --------------------
int main() {
    srand(time(nullptr));
    caratula();

    int filas = 4, cols = 4;

    // Crear matrices dinámicas
    char** LetrasNumeros = new char*[filas];
    char** LetrasNumerosOrdenado = new char*[filas];
    for (int i = 0; i < filas; i++) {
        LetrasNumeros[i] = new char[cols];
        LetrasNumerosOrdenado[i] = new char[cols];
    }

    char tmpMayus[6], tmpMinus[6], tmpNum[4];

    // Generar arrays recursivamente
    generarMayusculas(tmpMayus, 0, 6);
    generarMinusculas(tmpMinus, 0, 6);
    generarNumeros(tmpNum, 0, 4);

    // Llenar matriz aleatoria recursivamente
    int idxMayus = 0, idxMinus = 0, idxNum = 0;
    llenarMatrizAleatoria(LetrasNumeros, 0, 0, filas, cols, tmpMayus, tmpMinus, tmpNum, idxMayus, idxMinus, idxNum);

    cout << "\nMatriz aleatoria:\n";
    imprimirMatrizRec(LetrasNumeros, 0, 0, filas, cols);

    // Reordenar matriz recursivamente
    idxMayus = 0; idxMinus = 0; idxNum = 0;
    reordenarMatriz(LetrasNumeros, LetrasNumerosOrdenado, 0, 0, filas, cols, tmpMayus, tmpMinus, tmpNum, idxMayus, idxMinus, idxNum);

    cout << "\nMatriz reordenada:\n";
    imprimirMatrizRec(LetrasNumerosOrdenado, 0, 0, filas, cols);

    // Liberar memoria
    for (int i = 0; i < filas; i++) {
        delete[] LetrasNumeros[i];
        delete[] LetrasNumerosOrdenado[i];
    }
    delete[] LetrasNumeros;
    delete[] LetrasNumerosOrdenado;

    return 0;
}
