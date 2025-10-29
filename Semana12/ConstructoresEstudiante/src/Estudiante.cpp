#include <iostream>
#include "Estudiante.h"
using namespace std;

Estudiante::Estudiante(std::string nombre, int edad )
{
    dato1 = nombre;
    dato2 = edad;
}

void Estudiante:: print() const
{
    std::cout<<"Nombre del estudiante: "<< dato1 << "\nEdad del estudiante: "<< dato2<<  std::endl;
}

Estudiante::~Estudiante()
{
   std::cout << "Llamando al destructor" << std::endl;
}
