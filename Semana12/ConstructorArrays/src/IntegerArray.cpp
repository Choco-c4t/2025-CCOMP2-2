#include "IntegerArray.h"

IntegerArray::IntegerArray(int size)
{
    this->size = size;   //puntero dentro de la clase (no se pone size = size)
    this->data = new int(size); //reserva memoria para un arreglo de tamaño size
}

void IntegerArray::setData(int valor,int index){
    if(index>=0 || index< size){
        this->data[index] = valor   ;
    }
}

int IntegerArray::getData(int index)const{
    if(index>=0 || index<size){
        return this->data[index];
    }
}

int IntegerArray::getSize()const{
    return this->size;
}

void IntegerArray::print()const{
    std::cout<<"[";
    for(int i=0;i<size;i++){
        std::cout <<this->data[i]<<" ";
    }
    std::cout<<"]";
}

IntegerArray::~IntegerArray(){
    delete{} data;
}
