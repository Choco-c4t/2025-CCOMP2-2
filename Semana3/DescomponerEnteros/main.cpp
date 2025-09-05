#include <iostream>

using namespace std;

int main()
{
    //int a = 102;
    /**
        suma => +
        resta => -
        mult => *
        div => /
        modulo => %
    */

    //int result1 = val % 10;  //2
    //int result2 = val / 10;  //10

    /**
    * Implemente un programa que reciba por teclado un numero de 4 digitos e imprima el numero en forma vertical
     EJM,  3256
            3
            2
            5
            6
    */

    int a;
    cout << "Ingrese un numero de 4 digitos: ";
    cin >> a;
    cout << "El numero ingresado es: "<< a << endl;
    int resul1 = a / 1000 ;
    int resul2 = a % 1000;
    int resul3 = a / 100;
    int resul4 = a % 10;

    cout << resul1 << endl;
    cout << resul2 << endl;
    cout << resul3 << endl;
    cout << resul4 << endl;
    return 0;
}
