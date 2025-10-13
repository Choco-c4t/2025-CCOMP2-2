#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    char matriz[8][8];
    char minusculas[64];
    char mayusculas[64];
    char numeros[64];
    srand(time(0));
    int idxMin = 0, idxMay = 0, idxNum = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            int tipo = rand() % 3;
            if (tipo == 0) {
                matriz[i][j] = 'a' + rand() % 26;
                minusculas[idxMin] = matriz[i][j];
                idxMin++;
            }
            else if (tipo == 1) {
                matriz[i][j] = 'A' + rand() % 26;
                mayusculas[idxMay] = matriz[i][j];
                idxMay++;
            }
            else {
                matriz[i][j] = '0' + rand() % 10;
                numeros[idxNum] = matriz[i][j];
                idxNum++;
            }
        }
    }

    cout << "Matriz original:\n";
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < idxMin; i++) {
        for (int j = i + 1; j < idxMin; j++) {
            if (minusculas[i] > minusculas[j]) {
                char temporal = minusculas[i];
                minusculas[i] = minusculas[j];
                minusculas[j] = temporal;
            }
        }
    }

    for (int i = 0; i < idxMay; i++) {
        for (int j = i + 1; j < idxMay; j++) {
            if (mayusculas[i] < mayusculas[j]) {
                char temporal = mayusculas[i];
                mayusculas[i] = mayusculas[j];
                mayusculas[j] = temporal;
            }
        }
    }

    for (int i = 0; i < idxNum; i++) {
        for (int j = i + 1; j < idxNum; j++) {
            if (numeros[i] > numeros[j]) {
                char temporal = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = temporal;
            }
        }
    }

    int k = 0;
    for (int i = 0; i < idxMin; i++) {
        matriz[k / 8][k % 8] = minusculas[i];
        k++;
    }
    for (int i = 0; i < idxMay; i++) {
        matriz[k / 8][k % 8] = mayusculas[i];
        k++;
    }
    for (int i = 0; i < idxNum; i++) {
        matriz[k / 8][k % 8] = numeros[i];
        k++;
    }

    cout << "Matriz ordenada:\n";
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}






