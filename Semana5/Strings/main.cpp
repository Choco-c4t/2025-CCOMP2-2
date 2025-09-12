#include <iostream>

using namespace std;

int main()
{
    string cad = "Ciencia de la computacion";
    // " " -> para strings
    // ' ' -> para caracteres
    cout << cad << endl;
    char a = 'a';
    cout << a << endl;
    cout << cad.at(5) << endl; //5 (cuenta desde 0)

    // programa para contar el numero de letras de un string (caracter de fin de cadena ->  '\0 '
    int contador = 0;
    int i = 0;
    while (cad.at(i) != '\0'){
        i++;
    }
    cout << i << endl;

    //contar la cantidad de cierto caracter que hay en un string

    return 0;
}
