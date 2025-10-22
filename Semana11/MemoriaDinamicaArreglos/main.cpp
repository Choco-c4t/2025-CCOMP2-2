#include <iostream>

using namespace std;

int sumaarreglo( int *arr,int tam){
    int suma=0;
    for(int i=0; i<tam; i++){
        suma+=arr[i];
    }
    return suma;
}


int sumarecursiva(int *arr, int tam){
    if (tam == 0){
        return 0;
    } else{
        return *arr + sumarecursiva(arr + 1 ,tam - 1);
    }
}

/*Implementar un algoritmo de ordenamiento Bubble sort (complejidad: n^2)
*/

void OrdenamientoBubble(int *ptr,int tam){
    for(int i=0;i<tam;i++){
        for(int j= i+1; j< tam ;j++){
            if(ptr[i] > ptr[j]){
                int temp = ptr[i];
                ptr[i]=ptr[j];
                ptr[j]=temp;
            }
        }

    }
}

/*Implementar un algoritmo de ordenamiento (siguente clase) : Insertion sort, Merge sort y quick sort.
*/



int main()
{
    //Sintaxis para reservar memoria de un arreglo;
    int tam=5;
    int *ptr = new int[tam];
    for (int i=0; i < tam;i++){
        ptr[i]=i;
    }
    for (int i=0; i < tam;i++){
        cout <<ptr[i]<<" ";
    }
    cout<<"\nLa suma Iterativa es:"<<sumaarreglo(ptr,tam);
    cout<<"\nLa suma Recursiva es:"<<sumarecursiva(ptr,tam);
    cout<<"\nEl ordenamiento con bubble sort es:"<<endl;

    OrdenamientoBubble(ptr,tam);
    for (int i=0; i < tam;i++){
        cout <<ptr[i]<<" ";
    }

    delete[] ptr;
    return 0;
}
