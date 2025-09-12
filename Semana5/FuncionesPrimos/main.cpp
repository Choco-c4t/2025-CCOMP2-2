#include <iostream>

using namespace std;

/**
*Implemente una funcion que determine si un numero es primo o no lo es
*/

bool EsPrimo ( int numero){
    for (int i= 2 ; i*i <=numero; i++){
        if( numero % i == 0){
            return false;
        }
    }
    return true;
}

void PrimosHasta (int numero){
    int i = 2;
    while (i < numero){
        if (EsPrimo(i))
            cout << i << " ";
        i++;
    }
    cout << endl;
}

/**
*Implemente una funcion que reciba un entero y retorne el numero de digitos que tiene dicho entero
**/

int NumDigitos (long long n){
    int contador = 0;
    while ( n > 0){
        n /= 10 ;
        contador++;
    }
    return contador;
}

int main() {
    int n;
    cout << "Ingrese un numero: " << endl;
    cin >> n;
    cout << n << " es primo? " << EsPrimo(n) << endl;
    PrimosHasta (n); // void no imprime nada, invocarlo asi
    cout << NumDigitos(n)<< endl;
    return 0;
}
