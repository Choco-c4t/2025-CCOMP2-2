#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void llenarMatriz(char matriz[8][8], char minusculas[64], char mayusculas[64], char numeros[64], int &contMin, int &contMay, int &contNum) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int tipo = rand() % 3; //0=minusculas,1=mayusculas,2=numeros
            char c;

            if (tipo == 0) {
                c = 'a' + rand() % 26;
                minusculas[contMin] = c;
                contMin++;
            } else if (tipo == 1) {
                c = 'A' + rand() % 26;
                mayusculas[contMay] = c;
                contMay++;
            } else {
                c = '0' + rand() % 10;
                numeros[contNum] = c;
                contNum++;
            }

            matriz[i][j] = c;
        }
    }
}

void mostrarMatriz(char matriz[8][8]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void ordenarMinusculas(char minusculas[64], int contMin) {
    for (int i = 0; i < contMin; i++) {
        for (int j = i + 1; j < contMin; j++) {
            if (minusculas[i] > minusculas[j]) {
                char aux = minusculas[i];
                minusculas[i] = minusculas[j];
                minusculas[j] = aux;
            }
        }
    }
}

void ordenarMayusculas(char mayusculas[64], int contMay) {
    for (int i = 0; i < contMay; i++) {
        for (int j = i + 1; j < contMay; j++) {
            if (mayusculas[i] < mayusculas[j]) {
                char aux = mayusculas[i];
                mayusculas[i] = mayusculas[j];
                mayusculas[j] = aux;
            }
        }
    }
}

void ordenarNumeros(char numeros[64], int contNum) {
    for (int i = 0; i < contNum; i++) {
        for (int j = i + 1; j < contNum; j++) {
            if (numeros[i] > numeros[j]) {
                char aux = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = aux;
            }
        }
    }
}

void llenarMatrizOrdenada(char matriz[8][8], char minusculas[64], char mayusculas[64], char numeros[64], int contMin, int contMay, int contNum) {
    int idx = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (idx < contMin) {
                matriz[i][j] = minusculas[idx];
            } else if (idx < contMin + contMay) {
                matriz[i][j] = mayusculas[idx - contMin];
            } else {
                matriz[i][j] = numeros[idx - contMin - contMay];
            }
            idx++;
        }
    }
}

int main() {
    srand(time(0));

    char matriz[8][8];
    char minusculas[64];
    char mayusculas[64];
    char numeros[64];
    int contMin = 0, contMay = 0, contNum = 0;

    llenarMatriz(matriz, minusculas, mayusculas, numeros, contMin, contMay, contNum);

    cout << "Matriz original:\n";
    mostrarMatriz(matriz);

    ordenarMinusculas(minusculas, contMin);
    ordenarMayusculas(mayusculas, contMay);
    ordenarNumeros(numeros, contNum);

    llenarMatrizOrdenada(matriz, minusculas, mayusculas, numeros, contMin, contMay, contNum);

    cout << "Matriz ordenada\n";
    mostrarMatriz(matriz);

    return 0;
}
