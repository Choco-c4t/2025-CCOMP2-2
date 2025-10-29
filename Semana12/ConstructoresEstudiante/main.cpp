#include <iostream>
#include "Estudiante.h"
using namespace std;


//crear clase estudiante tiene nombre y edad, en el main crear 2 objetos y que imprima los datos
int main()
{
    Estudiante estudiante1("Fernando",18);
    cout << endl;
    estudiante1.print();
    cout << endl;

    Estudiante estudiante2("Rocio",18);
    cout << endl;
    estudiante2.print();
    cout << endl;

    return 0;
}
