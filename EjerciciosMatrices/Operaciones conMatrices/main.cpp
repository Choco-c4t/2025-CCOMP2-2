#include <iostream>
using namespace std;

// ===================== Funciones =====================

// Imprimir matriz est�tica (punteros)
void imprimirMatriz(int* M, int filas, int cols) {
    for(int i=0;i<filas;i++){
        for(int j=0;j<cols;j++)
            cout << *(M + i*cols + j) << " ";
        cout << endl;
    }
}

// Imprimir matriz din�mica
void imprimirMatriz(int** M, int filas, int cols){
    for(int i=0;i<filas;i++){
        for(int j=0;j<cols;j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
}

// ===================== MATRICES EST�TICAS =====================

// Suma matrices est�ticas
void sumarMatrices(int* A, int* B, int* C, int filas, int cols){
    for(int i=0;i<filas;i++)
        for(int j=0;j<cols;j++)
            *(C + i*cols + j) = *(A + i*cols + j) + *(B + i*cols + j);
}

// Resta matrices est�ticas
void restarMatrices(int* A, int* B, int* C, int filas, int cols){
    for(int i=0;i<filas;i++)
        for(int j=0;j<cols;j++)
            *(C + i*cols + j) = *(A + i*cols + j) - *(B + i*cols + j);
}

// Multiplicar matrices est�ticas
void multiplicarMatrices(int* A, int* B, int* C, int filasA, int colsA, int colsB){
    for(int i=0;i<filasA;i++){
        for(int j=0;j<colsB;j++){
            *(C + i*colsB + j) = 0;
            for(int k=0;k<colsA;k++)
                *(C + i*colsB + j) += *(A + i*colsA + k) * *(B + k*colsB + j);
        }
    }
}

// Transpuesta matriz est�tica
void transponerMatriz(int* A, int* T, int filas, int cols){
    for(int i=0;i<filas;i++)
        for(int j=0;j<cols;j++)
            *(T + j*filas + i) = *(A + i*cols + j);
}

// ===================== MATRICES DIN�MICAS =====================

// Crear matriz din�mica
int** crearMatriz(int filas, int cols){
    int** M = new int*[filas];
    for(int i=0;i<filas;i++)
        M[i] = new int[cols];
    return M;
}

// Liberar matriz din�mica
void liberarMatriz(int** M, int filas){
    for(int i=0;i<filas;i++)
        delete[] M[i];
    delete[] M;
}

// Suma matrices din�micas
void sumarMatrices(int** A, int** B, int** C, int filas, int cols){
    for(int i=0;i<filas;i++)
        for(int j=0;j<cols;j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Resta matrices din�micas
void restarMatrices(int** A, int** B, int** C, int filas, int cols){
    for(int i=0;i<filas;i++)
        for(int j=0;j<cols;j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Multiplicar matrices din�micas
int** multiplicarMatrices(int** A, int** B, int filasA, int colsA, int colsB){
    int** C = crearMatriz(filasA, colsB);
    for(int i=0;i<filasA;i++){
        for(int j=0;j<colsB;j++){
            C[i][j] = 0;
            for(int k=0;k<colsA;k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }
    return C;
}

// Transpuesta matriz din�mica
int** transponerMatriz(int** A, int filas, int cols){
    int** T = crearMatriz(cols, filas);
    for(int i=0;i<filas;i++)
        for(int j=0;j<cols;j++)
            T[j][i] = A[i][j];
    return T;
}

// ===================== MAIN =====================
int main(){
    // ----------- MATRICES EST�TICAS -----------
    const int filas=2, cols=3;
    int A[filas][cols] = {{1,2,3},{4,5,6}};
    int B[filas][cols] = {{6,5,4},{3,2,1}};
    int C[filas][cols];

    cout << "Matrices est�ticas A y B:\n";
    imprimirMatriz(&A[0][0], filas, cols);
    cout << endl;
    imprimirMatriz(&B[0][0], filas, cols);

    sumarMatrices(&A[0][0], &B[0][0], &C[0][0], filas, cols);
    cout << "\nSuma A + B:\n";
    imprimirMatriz(&C[0][0], filas, cols);

    restarMatrices(&A[0][0], &B[0][0], &C[0][0], filas, cols);
    cout << "\nResta A - B:\n";
    imprimirMatriz(&C[0][0], filas, cols);

    int D[cols][filas]; // transpuesta
    transponerMatriz(&A[0][0], &D[0][0], filas, cols);
    cout << "\nTranspuesta de A:\n";
    imprimirMatriz(&D[0][0], cols, filas);

    // ----------- MATRICES DIN�MICAS -----------
    int fD=2, cD=3;
    int** DA = crearMatriz(fD,cD);
    int** DB = crearMatriz(fD,cD);
    int** DC = crearMatriz(fD,cD);

    // Llenar matrices din�micas
    int contador=1;
    for(int i=0;i<fD;i++)
        for(int j=0;j<cD;j++){
            DA[i][j] = contador++;
            DB[i][j] = contador++;
        }

    cout << "\nMatrices din�micas DA y DB:\n";
    imprimirMatriz(DA,fD,cD);
    cout << endl;
    imprimirMatriz(DB,fD,cD);

    sumarMatrices(DA,DB,DC,fD,cD);
    cout << "\nSuma DA + DB:\n";
    imprimirMatriz(DC,fD,cD);

    restarMatrices(DA,DB,DC,fD,cD);
    cout << "\nResta DA - DB:\n";
    imprimirMatriz(DC,fD,cD);

    int** DT = transponerMatriz(DA,fD,cD);
    cout << "\nTranspuesta de DA:\n";
    imprimirMatriz(DT,cD,fD);

    int** DM = multiplicarMatrices(DA,DB,fD,cD,cD);
    cout << "\nMultiplicaci�n DA * DB^T (dimensiones compatibles):\n";
    imprimirMatriz(DM,fD,fD);

    // Liberar memoria din�mica
    liberarMatriz(DA,fD);
    liberarMatriz(DB,fD);
    liberarMatriz(DC,fD);
    liberarMatriz(DT,cD);
    liberarMatriz(DM,fD);

    return 0;
}
