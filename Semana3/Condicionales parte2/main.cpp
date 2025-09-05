#include <iostream>

using namespace std;

int main()
{

    char val;
    cout << "ingrese un caracter por favor: ";
    cin >> val; //para ingresar datos y se guarda en val

    cout << "El valor en la variable es: "<< val << endl;
    int num = static_cast<int>(val);
    cout << "El valor numerico es: "<< num << endl;

    /**
    * Escribir un programa que indique si el valor ingresa es una letra mayuscula
    */

    if (num >= 65 && num <=90){
        cout << "Es una letra mayuscula" << endl;
    } else{
        cout << "no es una letra mayuscula";
    }
    /**
    * Escribir un programa que indique si el valor ingresa es una letra mayuscula o una letra minuscula
    */
    if (num >= 65 && num <=90 || num>=97 && num <=122){
        cout << "Es una letra"<< endl;
    } else {
        cout <<" No es una letra" << endl;
    }
    /**
    * Escribe un programa que indique si el valor ingresador es un NUMERO
    */
    if (num >= 49 && num <=57 ){
        cout<< "ES UN NUMERO"<< endl;
    } else {
        cout << "No es un numero"<< endl;
    }

    return 0;
}
