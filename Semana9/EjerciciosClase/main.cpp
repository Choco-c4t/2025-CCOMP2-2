#include <iostream>

using namespace std;


/*
*Memoria dinamica:
*   Reservar 1 valor ->	int* p = new int;
*   Liberar 1 valor	-> delete p;
*   Reservar arreglo ->	int* a = new int[n];
*   Liberar arreglo	-> delete[] a;
*/
int main()
{

    //Puntero para una variable
cout<<"\n--------------- Para Variables ---------------\n"<<endl;

    int num = 3;
    int* puntero = nullptr;

    puntero = new int;   // Reserva espacio para un entero
    *puntero = num;      // Guarda el valor de num en ese espacio

    cout << "Valor: " << *puntero << endl;

    delete puntero;      // Libera la memoria
    puntero = nullptr;   // Buen hábito


    //Puntero para un arreglo
cout<<"\n--------------- Para Arreglos ---------------\n"<<endl;

    int arr[3] = {1, 2, 3};
    int* puntero2 = nullptr;

    puntero2 = new int[3];  // Reserva espacio para 3 enteros
    // Copiar valores del arreglo estático al dinámico
    for (int i = 0; i < 3; i++) {
        puntero2[i] = arr[i];
    }
    // Mostrar valores
    for (int i = 0; i < 3; i++) {
        cout << puntero2[i] << " ";
    }
    delete[] puntero2;  // Libera todo el arreglo
    puntero2 = nullptr; // Buen hábito


    //Puntero para una matriz
cout<<"\n--------------- Para Matrices ---------------\n"<<endl;
    int filas = 3, columnas = 4;
    int** matriz = new int*[filas]; // Reserva punteros a filas
    for (int i = 0; i < filas; i++)
        matriz[i] = new int[columnas]; // Reserva cada fila
    // Asignar valores
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < columnas; j++)
            matriz[i][j] = i + j;
    // Mostrar
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }
    // Liberar memoria
    for (int i = 0; i < filas; i++)
        delete[] matriz[i];
    delete[] matriz;


    //Ejercicio1: Sumar elementos de un arreglo dinamico
cout<<"\n--------------- Ejercicio 1 ---------------\n"<<endl;
    int arreglo[6] = {3,5,7,12,54,2};
    int* puntero3 = nullptr;
    puntero3 = new int[6];
    for(int i=0;i<6;i++){
        puntero3[i]= arreglo[i];
    }
    int suma = 0;
    for(int i = 0; i<6;i++){
        suma +=puntero3[i];
    }
    cout<<"Suma total: "<<suma<<endl;
    delete[]puntero3;
    puntero3=nullptr;


    //Ejercicio2: Encontrar el mayor valor en un arreglo:
cout<<"\n--------------- Ejercicio 2 ---------------\n"<<endl;
    int arreglo2[4] = {43,65,11,434};
    int* puntero4 = nullptr;
    puntero4 = new int[4];
    for(int i= 0; i<4;i++){
        puntero4[i]=arreglo2[i];
    }
    int maximo = puntero4[0];
    for(int i=1;i<4;i++){
        if(puntero4[i]> maximo){
            maximo = puntero4[i];
        }
    }
    cout<<"El maximo es: "<< maximo<<endl;
    delete[]puntero4;
    puntero4 = nullptr;


    //Ejercicio3: Transponer una matriz dinamica:
cout<<"\n--------------- Ejercicio 3 ---------------\n"<<endl;
    int matrizA[3][2]={{1,2},{3,4},{5,6}};
    int filas2 = 3;
    int columnas2 = 2;
    int** A = nullptr;
    A = new int*[filas2];
    for (int i=0; i<filas2;i++){
        A[i] = new int[columnas2];
        for (int j=0; j< columnas2; j++){
            A[i][j]=matrizA[i][j];
        }
    }

    int** transpuesta = nullptr;
    transpuesta = new int*[columnas2];
    for(int i=0; i<columnas2; i++){
        transpuesta[i]=new int[filas2];
    }

    for (int i = 0; i < filas2; i++) {
        for (int j = 0; j < columnas2; j++) {
            transpuesta[j][i] = A[i][j];
        }
    }
    cout << "Matriz transpuesta:\n";
    for (int i = 0; i < columnas2; i++) {
        for (int j = 0; j < filas2; j++) {
            cout << transpuesta[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < filas2; i++) delete[] A[i];
    delete[] A;

    for (int i = 0; i < columnas2; i++) delete[] transpuesta[i];
    delete[] transpuesta;

    //Ejercicio4:




    return 0;
}
