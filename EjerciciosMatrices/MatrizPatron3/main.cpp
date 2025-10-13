#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Función para ordenar de menor a mayor usando punteros
void ordenarAsc(char* arr, int n){
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(*(arr+j) > *(arr+j+1)){
                char tmp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = tmp;
            }
}

// Función para ordenar de mayor a menor usando punteros
void ordenarDesc(char* arr, int n){
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(*(arr+j) < *(arr+j+1)){
                char tmp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = tmp;
            }
}

int main(){
    srand(time(nullptr)); // Inicializar aleatorio

    const int N = 5; // Tamaño de la matriz

    // Crear matriz dinámicamente
    char** matriz = new char*[N];
    for(int i=0; i<N; i++)
        matriz[i] = new char[N];

    // Crear matrices auxiliares para patrón
    bool** esAsterisco = new bool*[N];
    bool** esArroba = new bool*[N];
    for(int i=0;i<N;i++){
        esAsterisco[i] = new bool[N]{0};
        esArroba[i] = new bool[N]{0};
    }

    // ---------------------------------------------
    // 1. Marcar patrón
    // ---------------------------------------------
    int asteriscoPos[][2] = {
        {0,1},{0,3},
        {1,0},{1,4},
        {2,1},{2,3},
        {3,0},{3,1},{3,3},{3,4},
        {4,2}
    };

    for(int k=0;k<11;k++)
        *(*(esAsterisco + asteriscoPos[k][0]) + asteriscoPos[k][1]) = true;

    int arrobaPos[][2] = {
        {1,1},{1,2},{1,3},
        {2,2}
    };

    for(int k=0;k<4;k++)
        *(*(esArroba + arrobaPos[k][0]) + arrobaPos[k][1]) = true;

    // ---------------------------------------------
    // 2. Rellenar la matriz
    // ---------------------------------------------
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){

            if(*(*(esAsterisco+i)+j))
                *(*(matriz+i)+j) = '*';

            else if(*(*(esArroba+i)+j))
                *(*(matriz+i)+j) = '@';

            else {
                // Cuadrantes para caracteres aleatorios
                if(i<2 && j<2) *(*(matriz+i)+j) = 'A'+rand()%26;          // Sup-izq A-Z
                else if(i<2 && j>2) *(*(matriz+i)+j) = 'a'+rand()%26;     // Sup-der a-z
                else if(i>2 && j<2) *(*(matriz+i)+j) = rand()%2 ? 'Z'-rand()%26 : '1'+rand()%9; // Inf-izq
                else if(i>2 && j>2) *(*(matriz+i)+j) = '9'-rand()%9;       // Inf-der
                else *(*(matriz+i)+j) = ' ';                               // Centro
            }

        }
    }

    // ---------------------------------------------
    // 3. Ordenar cada cuadrante
    // ---------------------------------------------
    char aux[10];
    int idx;

    // Sup-izq
    idx=0;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            if(!*(*(esAsterisco+i)+j) && !*(*(esArroba+i)+j))
                *(aux+idx++) = *(*(matriz+i)+j);
    ordenarAsc(aux, idx);
    idx=0;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            if(!*(*(esAsterisco+i)+j) && !*(*(esArroba+i)+j))
                *(*(matriz+i)+j) = *(aux+idx++);

    // Sup-der
    idx=0;
    for(int i=0;i<2;i++)
        for(int j=3;j<5;j++)
            if(!*(*(esAsterisco+i)+j) && !*(*(esArroba+i)+j))
                *(aux+idx++) = *(*(matriz+i)+j);
    ordenarAsc(aux, idx);
    idx=0;
    for(int i=0;i<2;i++)
        for(int j=3;j<5;j++)
            if(!*(*(esAsterisco+i)+j) && !*(*(esArroba+i)+j))
                *(*(matriz+i)+j) = *(aux+idx++);

    // Inf-izq
    idx=0;
    for(int i=3;i<5;i++)
        for(int j=0;j<2;j++)
            if(!*(*(esAsterisco+i)+j) && !*(*(esArroba+i)+j))
                *(aux+idx++) = *(*(matriz+i)+j);
    ordenarDesc(aux, idx);
    idx=0;
    for(int i=3;i<5;i++)
        for(int j=0;j<2;j++)
            if(!*(*(esAsterisco+i)+j) && !*(*(esArroba+i)+j))
                *(*(matriz+i)+j) = *(aux+idx++);

    // Inf-der
    idx=0;
    for(int i=3;i<5;i++)
        for(int j=3;j<5;j++)
            if(!*(*(esAsterisco+i)+j) && !*(*(esArroba+i)+j))
                *(aux+idx++) = *(*(matriz+i)+j);
    ordenarDesc(aux, idx);
    idx=0;
    for(int i=3;i<5;i++)
        for(int j=3;j<5;j++)
            if(!*(*(esAsterisco+i)+j) && !*(*(esArroba+i)+j))
                *(*(matriz+i)+j) = *(aux+idx++);

    // ---------------------------------------------
    // 4. Mostrar la matriz final
    // ---------------------------------------------
    cout << "\nMATRIZ CON PATRÓN _*_*_ 5x5 (punteros):\n\n";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << *(*(matriz+i)+j) << " ";
        }
        cout << endl;
    }

    // ---------------------------------------------
    // 5. Liberar memoria dinámica
    // ---------------------------------------------
    for(int i=0;i<N;i++){
        delete[] matriz[i];
        delete[] esAsterisco[i];
        delete[] esArroba[i];
    }
    delete[] matriz;
    delete[] esAsterisco;
    delete[] esArroba;

    return 0;
}

