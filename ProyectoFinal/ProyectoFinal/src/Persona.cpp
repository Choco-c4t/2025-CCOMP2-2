#include "Persona.hpp"
#include <iostream>
using namespace std;

Persona::Persona() {}

Persona::Persona(string _nombre) : nombre(_nombre) {}

void Persona::registrarDatos() {
    cout << "Registrando persona..." << endl;
}
