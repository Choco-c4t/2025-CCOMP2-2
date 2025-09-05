#include <iostream>

using namespace std;

int main()
{
    /**
    *Implemento un programa que solicite un numero por teclado e indique si dicho numero es un "numero primo"
    */
    /**
    int n , i = 1 , d = 0;
    cout << "Ingrese un numero: ";
    cin >> i;
    while ( i <= n ){
        if (n % i == 0){
            d= d + 2;
        }
        i = i + 2;
    }
    cout <<((d==2)? "Es primo":"No es primo "); // (Condicion ? "Si se cumple : "si no se cumple

    /**
    * Que solicite un numero por teclado e imprima los numeros primos menores que dicho numero
    **/
    int limite;

    cout << "Ingresa un numero: ";
    cin >> limite;

    int i = 2;

    while (i <= limite) {
        int j = 1;
        int divisores = 0;

        while (j <= i) {
            if (i % j == 0) {
                divisores = divisores + 1;
            }
            j = j + 1;
        }

        if (divisores == 2) {
            cout << i << " ";
        }

        i = i + 1;
    }

    cout << endl;
    return 0;
}
