#include "DinamicIntegerArray.h"



//------CONSTRUCCTOR SIN PARAMETROS------


DinamicInteguerArray::DinamicInteguerArray()
{
    this->size=0;
    this->data = new int(size);

}

//------CONSTRUCCTOR QUE RECIBE PARAMETROS------

DinamicInteguerArray::DinamicInteguerArray(int arr[],int size)
{
    this->size=size;
    this->data = new int(size);
    for(int i=0;i<size;i++){
        this->data[i] = arr[i];
    }

}


//------CONSTRUCCTOR POR COPIA------

DinamicIntegerArray::DinamicInteguerArray(DinamicIntegerArray &o){
    this->size = o.size;
    //this->data = o.data; ------> si lo ponemos asi, cuando b sale de su ambito, b pasara al destrucctor y libera la memoria del arreglo "da" lo que lo deja sin nada

    //solucion: crear un nuevo puntero, para que tenga su propio espacio de memoria:

    this->data = new int(size);
    for(int i=0;i<size;i++){
        this->data =o.data[i];
    }
}

int DinamicInteguerArray::getsize()const
{
    return size;
}

void DinamicInteguerArray::print() const
{
    std::cout <<"[";
    for(int i=0; i<size; i++){
        std::cout<< this->data[i]<<" ";
    }
    std::cout <<"]";
}

void DinamicInteguerArray::push_back(int valor) //crear un nuevo arreglo para usar push back
{
    //primer paso
    int *tmp= new int(size+1);
    //segundo paso
    for (int i=0;i<size; i++){
        tmp= this->data[i];
    }
    //segundo psao
    tmp[size]=val;
    //tercer paso
    size++;
    //quinto paso
    delete[]data;
    //sexto paso
    this->data = tmp;
}

void insert(int pos){
    int tmp = new int[size-1];
    for(int i=0; i< pos; i++){
        tmp[i]= this->data[i+1];
    }
    for(int i= pos; i<size; i++){
        tmp[i] =this->data[i+1];
    }
    size--;
    delete[]data;
    this->data =tmp;

}

void DinamicInteguerArray::insert(int val, int pos){
    int *tmp= new int [size+1];
    for (int i=0; i<pos; i++){
        tmp=this->data[i];
    }
    for (int i=pos; i<size; i++){
        tmp[i+1]=this->data[i];
    }
}


DinamicInteguerArray::~DinamicInteguerArray()
{
    delete[] data;
}

