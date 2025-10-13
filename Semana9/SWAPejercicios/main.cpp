#include <iostream>
using namespace std;

// ====================== Funciones ======================

// Imprimir matriz (punteros)
void imprimirMatriz(int* M, int filas, int cols) {
    for(int i=0;i<filas;i++){
        for(int j=0;j<cols;j++)
            cout << *(M + i*cols + j) << " ";
        cout << endl;
    }
}

// Imprimir arreglo (punteros)
void imprimirArreglo(int* A, int n) {
    for(int i=0;i<n;i++) cout << *(A+i) << " ";
    cout << endl;
}

// Swap matrices est�ticas
void swapMatrices(int* A, int* B, int filas, int cols) {
    for(int i=0;i<filas;i++)
        for(int j=0;j<cols;j++){
            int temp = *(A + i*cols + j);
            *(A + i*cols + j) = *(B + i*cols + j);
            *(B + i*cols + j) = temp;
        }
}

// Swap arreglos est�ticos
void swapArreglos(int* X, int* Y, int n){
    for(int i=0;i<n;i++){
        int temp = *(X+i);
        *(X+i) = *(Y+i);
        *(Y+i) = temp;
    }
}

// Swap matrices din�micas
void swapMatricesDinamicas(int** A, int** B, int filas, int cols){
    for(int i=0;i<filas;i++)
        for(int j=0;j<cols;j++){
            int temp = *(*(A+i)+j);
            *(*(A+i)+j) = *(*(B+i)+j);
            *(*(B+i)+j) = temp;
        }
}

// Swap arreglos din�micos
void swapArreglosDinamicos(int* X, int* Y, int n){
    for(int i=0;i<n;i++){
        int temp = *(X+i);
        *(X+i) = *(Y+i);
        *(Y+i) = temp;
    }
}

// ====================== Main ======================
int main(){
    // -------------------- MATRICES EST�TICAS --------------------
    const int filas = 2, cols = 3;
    int A[filas][cols] = {{1,2,3},{4,5,6}};
    int B[filas][cols] = {{7,8,9},{10,11,12}};

    cout << "Matrices est�ticas originales:\n";
    imprimirMatriz(&A[0][0], filas, cols);
    cout << endl;
    imprimirMatriz(&B[0][0], filas, cols);

    swapMatrices(&A[0][0], &B[0][0], filas, cols);

    cout << "\nMatrices est�ticas despu�s del swap:\n";
    imprimirMatriz(&A[0][0], filas, cols);
    cout << endl;
    imprimirMatriz(&B[0][0], filas, cols);

    // -------------------- ARREGLOS EST�TICOS --------------------
    const int n = 5;
    int arr1[n] = {1,2,3,4,5};
    int arr2[n] = {6,7,8,9,10};

    cout << "\nArreglos est�ticos originales:\n";
    imprimirArreglo(arr1, n);
    imprimirArreglo(arr2, n);

    swapArreglos(arr1, arr2, n);

    cout << "\nArreglos est�ticos despu�s del swap:\n";
    imprimirArreglo(arr1, n);
    imprimirArreglo(arr2, n);

    // -------------------- MATRICES DIN�MICAS --------------------
    int** C = new int*[filas];
    int** D = new int*[filas];
    for(int i=0;i<filas;i++){
        C[i] = new int[cols]{i*cols+1, i*cols+2, i*cols+3};
        D[i] = new int[cols]{i*cols+7, i*cols+8, i*cols+9};
    }

    cout << "\nMatrices din�micas originales:\n";
    for(int i=0;i<filas;i++){
        for(int j=0;j<cols;j++) cout << C[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    for(int i=0;i<filas;i++){
        for(int j=0;j<cols;j++) cout << D[i][j] << " ";
        cout << endl;
    }

    swapMatricesDinamicas(C,D,filas,cols);

    cout << "\nMatrices din�micas despu�s del swap:\n";
    for(int i=0;i<filas;i++){
        for(int j=0;j<cols;j++) cout << C[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    for(int i=0;i<filas;i++){
        for(int j=0;j<cols;j++) cout << D[i][j] << " ";
        cout << endl;
    }

    // Liberar memoria din�mica
    for(int i=0;i<filas;i++){ delete[] C[i]; delete[] D[i]; }
    delete[] C; delete[] D;

    // -------------------- ARREGLOS DIN�MICOS --------------------
    int* arrDyn1 = new int[n]{1,2,3,4,5};
    int* arrDyn2 = new int[n]{6,7,8,9,10};

    swapArreglosDinamicos(arrDyn1, arrDyn2, n);

    cout << "\nArreglos din�micos despu�s del swap:\n";
    imprimirArreglo(arrDyn1, n);
    imprimirArreglo(arrDyn2, n);

    delete[] arrDyn1;
    delete[] arrDyn2;

    return 0;
}
