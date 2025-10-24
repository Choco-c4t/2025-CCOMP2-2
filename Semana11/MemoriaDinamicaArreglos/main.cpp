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
void intercambiar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// "partir" el arreglo 
int particionar(int arr[], int inicio, int fin) {
    int pivote = arr[fin];  // elegimos el último elemento como pivote
    int i = inicio - 1;     // índice de los elementos más pequeños

    for (int j = inicio; j < fin; j++) {
        if (arr[j] < pivote) {   // si el elemento actual es menor al pivote
            i++;                 // movemos el índice
            intercambiar(arr[i], arr[j]); // y lo colocamos a la izquierda
        }
    }

    // colocamos el pivote en su lugar correcto
    intercambiar(arr[i + 1], arr[fin]);
    return i + 1;  // devolvemos la posición del pivote
}

// Función recursiva de Quick Sort 
void quickSort(int arr[], int inicio, int fin) {
    if (inicio < fin) {
        int indicePivote = particionar(arr, inicio, fin); // colocamos el pivote en su lugar

        // Ordenamos las dos partes
        quickSort(arr, inicio, indicePivote - 1); // izquierda
        quickSort(arr, indicePivote + 1, fin);    // derecha
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
