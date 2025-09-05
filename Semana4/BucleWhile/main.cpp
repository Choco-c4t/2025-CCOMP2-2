#include <iostream>

using namespace std;
int main()
{
    /**
    *Bucle while
    * Sintaxis:
    *   while(Condicion){
            Instruccion 1
            Instruccion 2
            ...
            Instruccion n
    * }
    */
    /**
    //imprime del 1 al 9
    int i = 0;
    while (i < 10) {
            cout << i << endl;
        i = i + 1;
    }
    // imprime del 9 al 1
    int j = 9;
    while (j>= 1) {
            cout<< j << endl;
        i = i - 1;
    }
    //multiplos de 3 menores que 100
    int z = 1;
    while (z< 100){
        if (z % 3 == 0){
            cout << z << endl;
        z = z + 1;
        }
    }
    return 0;
}
