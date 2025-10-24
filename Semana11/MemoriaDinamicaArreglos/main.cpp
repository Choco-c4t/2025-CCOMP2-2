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

void mostrarArreglo(int arr[], int tam) {
    for (int i = 0; i < tam; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/*Implementar un algoritmo de ordenamiento Bubble sort (complejidad: n^2)
*/
// ======================
//  Bubble SORT
// ======================

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
// ======================
//  INSERTION SORT
// ======================
void insertionSort(int arr[], int tam) {
    for (int i = 1; i < tam; i++) {
        int actual = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > actual) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = actual;
    }
}

// ======================
// MERGE SORT
// ======================

void merge(int arr[], int izq, int medio, int der) {
    int n1 = medio - izq + 1;
    int n2 = der - medio;

    int izquierda[n1], derecha[n2];

    for (int i = 0; i < n1; i++)
        izquierda[i] = arr[izq + i];
    for (int j = 0; j < n2; j++)
        derecha[j] = arr[medio + 1 + j];

    int i = 0, j = 0, k = izq;
    while (i < n1 && j < n2) {
        if (izquierda[i] <= derecha[j]) {
            arr[k] = izquierda[i];
            i++;
        } else {
            arr[k] = derecha[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = izquierda[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = derecha[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int izq, int der) {
    if (izq < der) {
        int medio = izq + (der - izq) / 2;
        mergeSort(arr, izq, medio);
        mergeSort(arr, medio + 1, der);
        merge(arr, izq, medio, der);
    }
}


// ======================
// QUICK SORT
// ======================
int particion(int arr[], int bajo, int alto) {
    int ultEleme = arr[alto];
    int i = bajo - 1;

    for (int j = bajo; j < alto; j++) {
        if (arr[j] < ultEleme) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[alto];
    arr[alto] = temp;
    return i + 1;
}

void quickSort(int arr[], int bajo, int alto) {
    if (bajo < alto) {
        int pi = particion(arr, bajo, alto);
        quickSort(arr, bajo, pi - 1);
        quickSort(arr, pi + 1, alto);
    }
}



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
    cout<<endl;
    cout<<"\nLa suma Iterativa es: "<<sumaarreglo(ptr,tam)<<endl;
    cout<<"\nLa suma Recursiva es: "<<sumarecursiva(ptr,tam)<<endl;

    cout << "\nBubble Sort: ";
    OrdenamientoBubble(ptr,tam);
    mostrarArreglo(ptr, tam);

    cout << "\nInsertion Sort: ";
    insertionSort(ptr, tam);
    mostrarArreglo(ptr, tam);

    cout << "\nMerge Sort: ";
    mergeSort(ptr, 0, tam - 1);
    mostrarArreglo(ptr, tam);

    cout << "\nQuick Sort: ";
    quickSort(ptr, 0, tam - 1);
    mostrarArreglo(ptr, tam);


    delete[] ptr;
    return 0;
}
