#include <iostream>

using namespace std;

//Sumar elementos de un arreglo usando recursividad y punteros

int SumarRecursivo(int*arr,int n){
    if (n==0){
        return 0;
    } else{
        return *arr + SumarRecursivo(arr+1,n-1);
    }
}

//Mostrar los elementos de un arreglo en orden inverso
void InversoRecursivo(int*arr,int n){
    if(n==0){
        return;
    } else{
        InversoRecursivo(arr+1,n-1);
    }
    cout<<*arr<<" ";
}

//Contar cuantas veces aparece un numero


int main()
{
    cout <<"--------------------------Sumar elementos de un arreglo con recursividad y punteros--------------------------"<<endl;
    int arr[6]={1,2,3,4,5,6};
    cout<<SumarRecursivo(arr,6)<<endl;

    cout <<"--------------------------Mostrar los elementos de un arreglo en orden inverso--------------------------"<<endl;
    int arr2[5]={1,2,3,4,5};
    InversoRecursivo(arr2,5);

    return 0;
}
