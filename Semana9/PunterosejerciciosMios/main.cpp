#include <iostream>
#include <cctype> // para tolower
using namespace std;

// Intercambio de dos números usando punteros
void IntercambioNum(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Mostrar arreglo usando solo punteros (++ sin índices)
void mostrar(int* arr, int n) {
    int* p = arr;
    for (int i = 0; i < n; i++) {
        cout << *p << " ";
        p++; // avanza al siguiente elemento
    }
    cout << endl;
}

// Invertir un arreglo usando punteros y ++
void invertir(int* arr, int n) {
    int* inicio = arr;
    int* fin = arr + n - 1;
    while (inicio < fin) {
        int temp = *inicio;
        *inicio = *fin;
        *fin = temp;
        inicio++; // avanza hacia adelante
        fin--;    // retrocede desde el final
    }
}

// Contar vocales usando punteros y ++
int contarVocales(char* texto) {
    int contador = 0;
    while (*texto != '\0') { // hasta el fin del texto
        char c = tolower(*texto);
        if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            contador++;
        texto++; // pasa al siguiente carácter
    }
    return contador;
}

// Sumar matrices usando punteros y ++
void SumaMatrices(int* A, int* B, int* C, int filas, int columnas) {
    int total = filas * columnas;
    for (int i = 0; i < total; i++) {
        *C = *A + *B;
        A++; B++; C++; // avanza todos los punteros
    }
}

// Mostrar matriz usando punteros y aritmética
void MostrarMatriz(int* M, int filas, int columnas) {
    int* p = M;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << *p << " ";
            p++; // avanza al siguiente elemento
        }
        cout << endl;
    }
}

// Comprobar si un número es par o impar
void NumParImpar(int* numero) {
    if (*numero % 2 == 0)
        cout << "Par" << endl;
    else
        cout << "Impar" << endl;
}

// Mostrar los pares de un arreglo y su posición usando punteros++
void numPares(int* arr, int n) {
    int* p = arr;
    for (int i = 0; i < n; i++) {
        if (*p % 2 == 0) {
            cout << *p << " es par. ";
            cout << "Direccion de memoria: " << p << endl;
        }
        p++; // avanza al siguiente número
    }
}

// Calcular promedio de un arreglo con punteros++
float promedio(int* arr, int n) {
    int suma = 0;
    int* p = arr;
    for (int i = 0; i < n; i++) {
        suma += *p;
        p++; // avanza al siguiente elemento
    }
    return float(suma) / n;
}

// Buscar un número en el arreglo usando punteros++
void buscarNum(int* arr, int n, int numero) {
    int* p = arr;
    bool encontrado = false;
    for (int i = 0; i < n; i++) {
        if (*p == numero) {
            cout << "Se encontro el numero: " << numero << endl;
            cout << "Su direccion de memoria es: " << p << endl;
            encontrado = true;
            break;
        }
        p++; // siguiente elemento
    }
    if (!encontrado)
        cout << "No se encontro el numero" << endl;
}

int main() {
    int x = 10;
    int* p = &x;

    cout << "Valor de x: " << *p << endl;
    cout << "Direccion de x (&x): " << &x << endl;
    cout << "Valor del puntero p: " << p << endl;

    cout << "\n--------------------------Intercambio--------------------------\n";
    int a = 10, b = 20;
    cout << "Antes: a = " << a << ", b = " << b << endl;
    IntercambioNum(&a, &b);
    cout << "Despues: a = " << a << ", b = " << b << endl;

    cout << "\n--------------------------Mostrar arreglo con punteros--------------------------\n";
    int numeros[] = {1, 2, 3, 4, 5};
    mostrar(numeros, 5);

    cout << "\n--------------------------Invertir arreglo--------------------------\n";
    int arr[] = {1, 2, 3, 4, 5};
    cout << "Original: ";
    mostrar(arr, 5);
    invertir(arr, 5);
    cout << "Invertido: ";
    mostrar(arr, 5);

    cout << "\n--------------------------Contar vocales--------------------------\n";
    char frase[] = "Ciencias de la Computacion";
    cout << "Cantidad de vocales: " << contarVocales(frase) << endl;

    cout << "\n--------------------------Suma de matrices--------------------------\n";
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int C[2][2];
    SumaMatrices(&A[0][0], &B[0][0], &C[0][0], 2, 2);
    MostrarMatriz(&C[0][0], 2, 2);

    cout << "\n--------------------------Numero par o impar--------------------------\n";
    int numero = 7;
    cout << "El numero " << numero << " es: ";
    NumParImpar(&numero);

    cout << "\n--------------------------Numeros pares en arreglo--------------------------\n";
    int arrnum[10] = {1,2,3,4,5,6,7,8,9,10};
    numPares(arrnum, 10);

    cout << "\n--------------------------Promedio de un arreglo--------------------------\n";
    int notas[5] = {12, 15, 12, 20, 18};
    cout << "Promedio: " << promedio(notas, 5) << endl;

    cout << "\n--------------------------Buscar un numero--------------------------\n";
    int arreglo[6] = {1, 2, 3, 4, 5, 6};
    buscarNum(arreglo, 6, 4);

    return 0;
}
