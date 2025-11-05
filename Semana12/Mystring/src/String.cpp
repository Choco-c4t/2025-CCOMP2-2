#include "String.h"

String::String(char *arr)
{
    int contador=0;
    for (int i=0; arr[i] != '\0'; i++){
        contador++;
    }
    this->size = contador;
    this->data = new char[contador+1]; //+1 para el fin de cadena
    for (int i=0; arr[i] != '\0'; i++){
        this->data[i]=arr[i]; //el fin de cadena ya no lo considera
    }
    this->data[size] = '\0';
}

int String::StringSize()const{
    return size;
}

char* String::getData()const{
    return this->data;
}

void String::toLower(){
    for(int i=0; i < size;i++){
        if(arr[i]>=65 && arr[i]<=90){
            arr[i]+= 32;
        }
    }
}


void String::toUpper(char *arr){
    for(int i=0; i < size;i++){
        if(arr[i]>= 97 && arr[i]<= 122){
            arr[i]-=32;
        }
    }
}



String::~String()
{
    delete[] data;
}
