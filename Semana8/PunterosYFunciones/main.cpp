#include <iostream>

using namespace std;

//Imprimir array usando punteros
void printArray(int *arr,int size){
    cout << "[";
    for (int i = 0 ; i<size ; i++, arr++){
        cout << *arr<<" ";
    }
    cout << "]"<<endl;
}

//intercambio de valores usando punteros
void intercambio(int *a, int *b){
    int tmp = *a;
    *a=*b;
    *b=tmp;
}

//funcion para invertir los elementos de un arreglo, usando punteros

void invertirArr (int *ini,int *fin){
    while (ini<fin){
        intercambio(ini,fin);
        ini++; fin--;
    }
}
//invertir los elementos de un array, usando recursividad y punteros (fija para parcial o control)

void recursivoInvertir (int *ini,int *fin){
    if (ini >=fin){
        return;
    }
    else{
        intercambio(ini,fin);
        recursivoInvertir(++ini,--fin);
    }
}
int main()
{
    int arr[] ={1,2,3,4,5};
    int tam = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,tam); //arr aca estamos enviando una direccion de memoria
    cout << "=============================="<<endl;
    int x=10; //|10| x666
    int y=20; //|20| x111
    intercambio(&x,&y);
    cout<<"---Intercambio---"<<endl;
    cout<<"a= "<< x << endl;
    cout<<"b= "<< y << endl;
    cout << "=============================="<<endl;
    invertirArr(arr,arr+tam-1);
    printArray(arr,tam);
    cout << "=============================="<<endl;
    recursivoInvertir(arr,arr+tam-1);
    printArray(arr,tam);


    return 0;
}
