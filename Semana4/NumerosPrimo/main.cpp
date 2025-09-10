#include <iostream>

using namespace std;

int main()
{
    /**
    *Implemento un programa que solicite un numero por teclado e indique si dicho numero es un "numero primo"
    */

    int n , i = 2 , d = 0;
    cout << "Ingrese un numero: ";
    cin >> i;
    while ( i * i <= n ){
        if (n % i == 0){  //basta con que llegue hasta la raiz
            d= d + 2;
            break;
        }
        if (d>0);
            break;
        i = i + 2;
    }
    cout <<((d==2)? "Es primo":"No es primo "); // (Condicion ? "Si se cumple : "si no se cumple

    /**
    * Que solicite un numero por teclado e imprima los numeros primos menores que dicho numero
    **/

    int num;
    cout << "Ingresa un numero: ";
    cin >> num;
    int i = 2;
    while (i <= num) {
        int j = 2;
        while (j < num && num % j == 0) {
            if (i % j == 0) {
            j = j + 1;
        }
        if (j == 2) {
            cout << i << " ";
        }

        i = i + 1;

        }
    }

    // Otra forma
    long long n , j=2, d=0, i = 2; cin>>n;
    while (j<=n){
        while (i*i <= j){
        if (j % i == 0){
            d = d+2;
            break;
            }
            i = i + 2
        }
        if (d==0)
            cout << i << endl;
        d = 0, i = 2
        j = j+2
    }
    return 0;

    }
    return 0;
}
