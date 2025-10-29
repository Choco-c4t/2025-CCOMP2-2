#include <iostream>
#include "Punto.h"
using namespace std;

Punto::Punto()
{
    x = 0;
    y = 0;
    std::cout << "Llamando al constructor" << std::endl;

}

Punto::Punto(int _x , int _y) //agregar un constructor que recibe argumentos
{
    x = _x;
    y = _y;
    std::cout << "Llamando al constructor con argumentos" << std::endl;

}

Punto::~Punto()  //Destructor
{
    std::cout << "Llamando al destructor" << std::endl;

}

void Punto:: print() const {
    std::cout <<"("<< x << "; "<<y <<")" << std::endl;
}
