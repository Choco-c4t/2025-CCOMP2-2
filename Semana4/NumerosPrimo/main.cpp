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
    int n;
    int i = 1;
    int d = 0;
    int f = 0;
    cout << "Ingrese un numero: ";
    cin >> n;
    while (f != n ){
        while ( i <= n ){
        if (n % i == 0){
            d= d + 2;
        }
        i = i + 2;
    } cout << i;
    f = f + 1;
    }

    return 0;
}
