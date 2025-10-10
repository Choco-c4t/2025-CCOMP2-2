#include <iostream>

using namespace std;

/*
*Punteros: variable que almacena la direccion de memoria de otra variable
*   & → obtiene la dirección de memoria
*    * → accede al valor guardado en esa dirección
*
*/

//Programa que intercambie numeros con punteros

void IntercambioNum (int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


//Programa que invierta un arreglo usando punteros

void invertir(int*arr, int n){
    int* inicio = arr;
    int* fin = arr + n -1;
    while (inicio < fin){
        int temp = *inicio;
        *inicio = *fin;
        *fin = temp;

        inicio ++;
        fin --;
    }
}

void mostrar (int*arr,int n){
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//Programa que cuente vocales de una cadena

int contarVocales(char*texto){
    int contador = 0;
    while (*texto !='\0'){
        char c = tolower(*texto);
        if (c=='a'||c=='e'|c=='i'|c=='o'|c=='u'){
            contador++;
        }
        texto++;
    }
    return contador;
}

//programa para sumar matrices

void SumaMatrices(int*A,int*B,int*C,int filas,int columnas){
    for(int i=0;i<filas*columnas;i++){
        *(C+i)= *(A+i)+*(B+i);
    }
}

void MostrarMatriz(int*M,int filas, int columnas){
    for(int i=0; i<filas;i++){
        for(int j= 0;j<columnas;j++){
            cout<<*(M+i*columnas+j)<< " ";
        }
        cout<<endl;
    }
}

//Comprobar si un numero es par o impar con punteros

void NumParImpar (int*numero){
    if(*numero%2==0){
        cout<<"Par"<<endl;
    } else{
        cout<<"Impar"<<endl;
    }
}

//Indicar que numeros son pares y su posicion en memoria en un arreglo

void numPares(int*arr,int n){
    for(int i = 0;i<n;i++){
        if(*(arr+i) %2==0){
            cout<<*(arr+i)<<" es par"<<endl;
            cout<<"posicion: "<<arr+i<<endl;
        }
    }
}

//Programa que retorne el promedio de un arreglo:

float promedio(int *arr,int n){
    int suma=0;
    for(int i =0;i<n;i++){
        suma += *(arr+i);
    }
    return float(suma)/n;
}

//Programa que encuentre un numero en un arreglo y su posicion de memoria:

void buscarNum (int*arr,int n, int numero){
    bool encontrado = false;
    for(int i=0;i<n;i++){
        if(*(arr+i)==numero){
            cout<<"Se encontro el numero: "<<numero<<endl;
            cout<<"Su direccion es: "<<(arr+i)<<endl;
            encontrado=true;
            break;
        }
    }
    if (encontrado==false){
        cout<<"No se encontro el numero"<<endl;
    }
}
int main(){
    int x = 10;
    int* puntero = &x;
    cout<<"Valor de x: "<< x <<endl;
    cout<<"Direccion de x (&x): " << &x <<endl;
    cout << "Valor del puntero p: " << puntero << endl;
    cout << "Valor al que apunta (*p): " << *puntero << endl;

    cout <<"--------------------------Intercambio--------------------------"<<endl;
    int a = 10;
    int b = 20;
    cout<<"Antes del intercambio: a = "<<a<<" b = "<<b<<endl;
    IntercambioNum(&a,&b);
    cout <<"Despues del intercambio: a = "<<a<<" b = "<<b<<endl;

    cout <<"--------------------------Arreglos--------------------------"<<endl;
    int numeros[]={1,2,3,4,5};
    int *puntnum=numeros;
    for(int i=0;i<5;i++){
        cout<<"Elementos del arreglo ["<<i<<"]: "<<*puntnum++<<endl;
    }
    for(int i=0;i<5;i++){
        cout<<"Posicion de memoria " <<numeros[i]<<" es: "<<puntnum++<<endl;
    }

    cout <<"--------------------------Invertir arreglo--------------------------"<<endl;
    int arr[5]= {1,2,3,4,5};
    cout << "Arreglo Original: "<<endl;
    mostrar(arr,5);

    cout<<"Arreglo Invertido: "<<endl;
    invertir (arr, 5);
    mostrar(arr,5);

    cout <<"--------------------------Contar Vocales--------------------------"<<endl;

    char frase[]="Ciencias de la Computación";
    int vocales = contarVocales(frase);
    cout<<"Cantidad de vocales: "<< vocales<<endl;

    cout <<"--------------------------Suma de Matrices--------------------------"<<endl;
    int MatrizA[2][2]={{1,2},{3,4}};
    int MatrizB[2][2]={{5,6},{7,8}};
    int MatrizC[2][2];

    SumaMatrices(&MatrizA[0][0],&MatrizB[0][0],&MatrizC[0][0],2,2);
    cout<<"Resultado de la Suma:\n";
    MostrarMatriz(&MatrizC[0][0],2,2);

    cout <<"--------------------------Numero par o impar--------------------------"<<endl;
    int numero;
    cout<<"Ingrese un numero: ";
    cin>>numero;

    cout<<"El numero es: "<<endl;
    NumParImpar(&numero);

    cout <<"--------------------------Numero par o impar de un arreglo--------------------------"<<endl;
    int arrnum[10]={1,2,3,4,5,6,7,8,9,10};
    numPares(arrnum,10);

    cout <<"--------------------------Promedio de un arreglo--------------------------"<<endl;
    int notas[5]={12,15,12,20,18};
    cout<<"El promedio es: "<<promedio(notas,5)<<endl;

    cout <<"--------------------------Buscar un numero en un arreglo--------------------------"<<endl;
    int arreglo[6]={1,2,3,4,5,6};
    int numeroo=3;
    buscarNum(arreglo,6,numeroo);

    return 0;
}
