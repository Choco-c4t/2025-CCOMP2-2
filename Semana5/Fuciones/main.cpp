#include <iostream>

using namespace std;


//Una funcion que defina la potencia de un numero
int potencia ( int base, int exponente){
    int resultado = 1;
    for(int i = 0; i < exponente ; i++){ //parte del for -> for(inicializacion ; condicion ; incremento)
        resultado = resultado * base;
    }
    return resultado;
}

int main()
{
    cout << potencia(2,3)<< endl; //implementacion
    return 0;
}
