#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Función para ordenar de menor a mayor
void ordenarAsc(char* arr, int n) {
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(arr[j] > arr[j+1]) {
                char tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
}

// Función para ordenar de mayor a menor
void ordenarDesc(char* arr, int n) {
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(arr[j] < arr[j+1]) {
                char tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
}

int main() {

    srand(time(nullptr));   // Inicializar generador de números aleatorios

    const int N = 5;        // Tamaño de la matriz 5x5
    char matriz[N][N];      // Matriz principal

    int centro = N/2;       // Centro de la matriz (fila y columna 2)

    bool esAsterisco[N][N] = {0}; // Matriz auxiliar para bordes (*)
    bool esArroba[N][N]   = {0};  // Matriz auxiliar para interior (@)

    // ---------------------------------------------
    // 1. Crear patrón del diamante dinámicamente
    // ---------------------------------------------
    for(int i=0; i<N; i++) {

        for(int j=0; j<N; j++) {

            int distancia = abs(i - centro) + abs(j - centro);

            if(distancia == 2)
                esAsterisco[i][j] = true;   // Bordes del diamante
            else if(distancia < 2)
                esArroba[i][j] = true;      // Interior del diamante
            // Los demás espacios quedan libres
        }

    }

    // ---------------------------------------------
    // 2. Llenar la matriz
    // ---------------------------------------------
    for(int i=0; i<N; i++) {

        for(int j=0; j<N; j++) {

            if(esAsterisco[i][j])
                matriz[i][j] = '*';

            else if(esArroba[i][j])
                matriz[i][j] = '@';

            else {
                // Relleno de los espacios libres según cuadrante
                if(i < centro && j < centro)
                    matriz[i][j] = 'A' + rand()%26;          // Sup-izq A-Z

                else if(i < centro && j > centro)
                    matriz[i][j] = 'a' + rand()%26;          // Sup-der a-z

                else if(i > centro && j < centro) {
                    if(rand()%2 == 0)
                        matriz[i][j] = 'Z' - rand()%26;      // Inf-izq Z-A
                    else
                        matriz[i][j] = '1' + rand()%9;       // Inf-izq números 1-9
                }

                else if(i > centro && j > centro)
                    matriz[i][j] = '9' - rand()%9;           // Inf-der números 9-1

                else
                    matriz[i][j] = ' ';                      // Centro fila impar
            }

        }

    }

    // ---------------------------------------------
    // 3. Ordenar los cuadrantes
    // ---------------------------------------------

    // 3.1 Superior izquierda (A-Z)
    char supIzq[10];
    int idx = 0;
    for(int i=0; i<centro; i++)
        for(int j=0; j<centro; j++)
            if(!esAsterisco[i][j] && !esArroba[i][j])
                supIzq[idx++] = matriz[i][j];

    ordenarAsc(supIzq, idx);
    idx = 0;
    for(int i=0; i<centro; i++)
        for(int j=0; j<centro; j++)
            if(!esAsterisco[i][j] && !esArroba[i][j])
                matriz[i][j] = supIzq[idx++];

    // 3.2 Superior derecha (a-z)
    char supDer[10];
    idx = 0;
    for(int i=0; i<centro; i++)
        for(int j=centro+1; j<N; j++)
            if(!esAsterisco[i][j] && !esArroba[i][j])
                supDer[idx++] = matriz[i][j];

    ordenarAsc(supDer, idx);
    idx = 0;
    for(int i=0; i<centro; i++)
        for(int j=centro+1; j<N; j++)
            if(!esAsterisco[i][j] && !esArroba[i][j])
                matriz[i][j] = supDer[idx++];

    // 3.3 Inferior izquierda (Z-A / números)
    char infIzq[10];
    idx = 0;
    for(int i=centro+1; i<N; i++)
        for(int j=0; j<centro; j++)
            if(!esAsterisco[i][j] && !esArroba[i][j])
                infIzq[idx++] = matriz[i][j];

    ordenarDesc(infIzq, idx);
    idx = 0;
    for(int i=centro+1; i<N; i++)
        for(int j=0; j<centro; j++)
            if(!esAsterisco[i][j] && !esArroba[i][j])
                matriz[i][j] = infIzq[idx++];

    // 3.4 Inferior derecha (números descendentes)
    char infDer[10];
    idx = 0;
    for(int i=centro+1; i<N; i++)
        for(int j=centro+1; j<N; j++)
            if(!esAsterisco[i][j] && !esArroba[i][j])
                infDer[idx++] = matriz[i][j];

    ordenarDesc(infDer, idx);
    idx = 0;
    for(int i=centro+1; i<N; i++)
        for(int j=centro+1; j<N; j++)
            if(!esAsterisco[i][j] && !esArroba[i][j])
                matriz[i][j] = infDer[idx++];

    // ---------------------------------------------
    // 4. Mostrar la matriz final
    // ---------------------------------------------
    cout << "\nMATRIZ CON DIAMANTE CENTRADO 5x5:\n\n";

    for(int i=0; i<N; i++) {

        for(int j=0; j<N; j++) {
            cout << matriz[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}


//Patron  con memoria dinamica:
/*
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Función para ordenar de menor a mayor usando punteros
void ordenarAsc(char* arr, int n) {
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(*(arr+j) > *(arr+j+1)) {
                char tmp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = tmp;
            }
}

// Función para ordenar de mayor a menor usando punteros
void ordenarDesc(char* arr, int n) {
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(*(arr+j) < *(arr+j+1)) {
                char tmp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = tmp;
            }
}

int main() {

    srand(time(nullptr)); // Inicializar generador aleatorio

    const int N = 5; // Tamaño 5x5

    // Crear matriz usando punteros
    char** matriz = new char*[N];
    for(int i=0; i<N; i++)
        matriz[i] = new char[N];

    int centro = N/2; // Centro de la matriz

    bool** esAsterisco = new bool*[N];
    bool** esArroba = new bool*[N];
    for(int i=0; i<N; i++) {
        esAsterisco[i] = new bool[N]{0};
        esArroba[i]   = new bool[N]{0};
    }

    // ---------------------------------------------
    // 1. Crear patrón de diamante
    // ---------------------------------------------
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            int distancia = abs(i - centro) + abs(j - centro);

            if(distancia == 2)
                *(*(esAsterisco + i) + j) = true;
            else if(distancia < 2)
                *(*(esArroba + i) + j) = true;
        }
    }

    // ---------------------------------------------
    // 2. Llenar la matriz con caracteres
    // ---------------------------------------------
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {

            if(*(*(esAsterisco + i) + j))
                *(*(matriz + i) + j) = '*';
            else if(*(*(esArroba + i) + j))
                *(*(matriz + i) + j) = '@';
            else {
                if(i < centro && j < centro)
                    *(*(matriz + i) + j) = 'A' + rand()%26;
                else if(i < centro && j > centro)
                    *(*(matriz + i) + j) = 'a' + rand()%26;
                else if(i > centro && j < centro) {
                    if(rand()%2 == 0) *(*(matriz + i) + j) = 'Z' - rand()%26;
                    else *(*(matriz + i) + j) = '1' + rand()%9;
                }
                else if(i > centro && j > centro)
                    *(*(matriz + i) + j) = '9' - rand()%9;
                else
                    *(*(matriz + i) + j) = ' ';
            }

        }
    }

    // ---------------------------------------------
    // 3. Ordenar los cuadrantes con punteros
    // ---------------------------------------------

    // 3.1 Superior izquierda
    char supIzq[10]; int idx=0;
    for(int i=0;i<centro;i++)
        for(int j=0;j<centro;j++)
            if(!*(*(esAsterisco + i) + j) && !*(*(esArroba + i) + j))
                *(supIzq + idx++) = *(*(matriz + i) + j);

    ordenarAsc(supIzq, idx);
    idx = 0;
    for(int i=0;i<centro;i++)
        for(int j=0;j<centro;j++)
            if(!*(*(esAsterisco + i) + j) && !*(*(esArroba + i) + j))
                *(*(matriz + i) + j) = *(supIzq + idx++);

    // 3.2 Superior derecha
    char supDer[10]; idx=0;
    for(int i=0;i<centro;i++)
        for(int j=centro+1;j<N;j++)
            if(!*(*(esAsterisco + i) + j) && !*(*(esArroba + i) + j))
                *(supDer + idx++) = *(*(matriz + i) + j);

    ordenarAsc(supDer, idx);
    idx=0;
    for(int i=0;i<centro;i++)
        for(int j=centro+1;j<N;j++)
            if(!*(*(esAsterisco + i) + j) && !*(*(esArroba + i) + j))
                *(*(matriz + i) + j) = *(supDer + idx++);

    // 3.3 Inferior izquierda
    char infIzq[10]; idx=0;
    for(int i=centro+1;i<N;i++)
        for(int j=0;j<centro;j++)
            if(!*(*(esAsterisco + i) + j) && !*(*(esArroba + i) + j))
                *(infIzq + idx++) = *(*(matriz + i) + j);

    ordenarDesc(infIzq, idx);
    idx=0;
    for(int i=centro+1;i<N;i++)
        for(int j=0;j<centro;j++)
            if(!*(*(esAsterisco + i) + j) && !*(*(esArroba + i) + j))
                *(*(matriz + i) + j) = *(infIzq + idx++);

    // 3.4 Inferior derecha
    char infDer[10]; idx=0;
    for(int i=centro+1;i<N;i++)
        for(int j=centro+1;j<N;j++)
            if(!*(*(esAsterisco + i) + j) && !*(*(esArroba + i) + j))
                *(infDer + idx++) = *(*(matriz + i) + j);

    ordenarDesc(infDer, idx);
    idx=0;
    for(int i=centro+1;i<N;i++)
        for(int j=centro+1;j<N;j++)
            if(!*(*(esAsterisco + i) + j) && !*(*(esArroba + i) + j))
                *(*(matriz + i) + j) = *(infDer + idx++);

    // ---------------------------------------------
    // 4. Mostrar la matriz final
    // ---------------------------------------------
    cout << "\nMATRIZ CON DIAMANTE CENTRADO 5x5 (punteros):\n\n";

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << *(*(matriz + i) + j) << " ";
        }
        cout << endl;
    }

    // ---------------------------------------------
    // 5. Liberar memoria dinámica
    // ---------------------------------------------
    for(int i=0;i<N;i++) {
        delete[] matriz[i];
        delete[] esAsterisco[i];
        delete[] esArroba[i];
    }
    delete[] matriz;
    delete[] esAsterisco;
    delete[] esArroba;

    return 0;
}

//matriz con bordes de * 

#include <iostream>
#include <cstdlib>  // rand, srand
#include <ctime>    // time

using namespace std;

int main() {
    const int n = 5;
    char matriz[n][n];
    const int interiorSize = 9; // 3x3 interior
    char interior[interiorSize];

    srand(time(NULL));  // semilla aleatoria

    // --- LLENAR MATRIZ ---
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                matriz[i][j] = '*';
            } else {
                char letra = 'a' + rand() % 26;
                matriz[i][j] = letra;
                interior[k++] = letra; // guardar letra interior
            }
        }
    }

    // --- ORDENAR INTERIOR DE Z -> A (BURBUJA) ---
    for (int i = 0; i < interiorSize - 1; i++) {
        for (int j = 0; j < interiorSize - i - 1; j++) {
            if (interior[j] < interior[j + 1]) { // descendente
                char temp = interior[j];
                interior[j] = interior[j + 1];
                interior[j + 1] = temp;
            }
        }
    }

    // --- RELLENAR MATRIZ CON INTERIOR ORDENADO FILA POR FILA ---
    k = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            matriz[i][j] = interior[k++];
        }
    }

    // --- IMPRIMIR MATRIZ ORDENADA ---
    cout << "Matriz ordenada (de z a a):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << ' ';
        }
        cout << '\n';
    }

    // --- IMPRIMIR LETRAS INTERIORES ORDENADAS ---
    cout << "\nLetras interiores ordenadas (z->a): ";
    for (int i = 0; i < interiorSize; i++) {
        cout << interior[i] << ' ';
    }
    cout << '\n';

    return 0;
}

*/


