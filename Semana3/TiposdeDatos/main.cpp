#include <iostream>

using namespace std;

int main()
{
    /**
        los tipos de datos para manejar ENTEROS son:
            -short (en memoria RAM ocupa 2 bytes)
            - int - long (En memoria RAM ocupa 4 bytes)
            - long Long (en memoria RAM ocupa 8 bytes)
    */
    unsigned short val1 = 32766;
    cout << "el valor es :" << (val1)<< endl;
    val1 = val1 + 1;
    cout << "el valor es :" << (val1)<< endl;
    val1 = val1 + 1;
    cout << "el valor es :" << (val1)<< endl;
    return 0;
    /**
    Para short = 2bytes
    1 byte tiene 8 bits
    2 bytes tiene 16 bits

    255 en binario es 11111111
    256 en binario es 00000001 00000000
    ----
    2 elevado a la 16 - 1 = 65535 en binario es 11111111 11111111
    el valor maximo para short es la mitad de 65535 = 32766 (solo positivos)
    sin signo es
    */

}
