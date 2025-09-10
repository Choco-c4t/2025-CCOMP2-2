#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    /**
    *Escriba un programa que pida un numero (3 a 9 digitos)
    * y evaluar si ese numero es un palindromo
    * Ejm: 13331 -> palindromo
    */
    /**
    long long num;
    cout << "Ingrese un numero: " << endl;
    cin >> num;
    int a = 0 ;
    if ( num <= 100 && num <= 999){
        if ( )
        int b = num % 1000
    }
    /**
    *Palindromo pero con while
    */
    long long num, original, invertido = 0;
    cout << "Ingrese un numero (3 a 9 digitos): ";
    cin >> num;

    original = num;
    while (num > 0) {
        invertido = invertido * 10 + (num % 10);
        num = num / 10;
    }

    if (original == invertido)
        cout << "Es palindromo" << endl;
    else
        cout << "No es palindromo" << endl;

    // Ottra forma

    long numeroo;
    cout << "Ingrese un numero";
    cin >> numeroo;
    long numC = numeroo;
    long numdig = 0;
    while ( numC > 0){
            numC*= 10 ;
            numdig++;
    }
    while( numeroo!=0){
        int ini = numeroo / pow( 10 , numdig-1);
        int fin = numeroo%10;
        if (ini != fin){
            cout<< "No es palindromo"<<endl;
            break;
        }
        numeroo = (numeroo% static_cast<int>(pow( 10, numdig -1))) / 10;
        numdig-= 2;
        cout << fin << endl;
        cout << ini<< endl;
        cout<< numeroo<< endl;
    }



    /**
    *Numeros primos hasta N con for
    */
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;

    cout << "Primos hasta " << n << ": " << endl;
    for (int i = 2; i <= n; i=i+1) {
        int divisores = 0;
        for (int j = 1; j <= i; j=j+1) {
            if (i % j == 0)
                divisores++;
        }
        if (divisores == 2)  // solo divisible por 1 y él mismo
            cout << i << ""<<endl;
    }

    /**
    *Indicar si ese numero es primo con for
    */

    int numero;
    cout << "Ingrese un numero: "<< endl;
    cin >> numero;
    int divisor = 0;
    for (int j=1; j<= numero; j=j+1){
        if(numero % j == 0){
            divisor= divisor + 1;
        }
        if (divisor > 2){
            break;
        }
    }

    if (divisor == 2){
        cout << "Es primo"<< endl;
    } else {
        cout << "No es primo" << endl;
    }



    // usando while y for  y en los otros ejercicios (primos y primos menores al numero) -> que usen for
    return 0;
}
