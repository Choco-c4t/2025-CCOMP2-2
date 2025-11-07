#include "DinamicInteguerArray.h"

DinamicInteguerArray::DinamicInteguerArray()
{
    this->size=0;
    this->data = new int(size);

}

DinamicInteguerArray::DinamicInteguerArray(int arr[],int size)
{
    this->size=size;
    this->data = new int(size);
    for(int i=0;i<size;i++){
        this->data[i] = arr[i];
    }

}

int DinamicInteguerArray::getsize()
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

void DinamicInteguerArray::insert(int val, int pos){
    int *tmp= new int [size+1];
    for (int i=0; i<pos; i++){
        tmp=this->data[i];
    }
    for (int i=pos; i<size; i++){
        tmp[i+1]=this->data[i];
    }
}

void remove

DinamicInteguerArray::~DinamicInteguerArray()
{
    delete[] data;
}
