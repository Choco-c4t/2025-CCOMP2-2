#include <iostream>

using namespace std;

int main()
{
    char car = '6';   //el caracter utiliza comillas simples, mientras que una cadena utiliza comillas
    int val = static_cast<int>(car); //pasar de caracter a entero
    cout << sizeof (car) << endl;  //el tamaño de ese valor
    cout << "El valor entero es :" << val << endl;

    int num = 54; //para numeros no es necesario ponerle comillas
    char val2 = static_cast < int>(num); //pasar de entero a caracter
    cout << "El valor es: " << val2 << endl;

    int result = val - '0';
    cout << "El valor entero es: "<<val<<endl;
    cout << result << endl;


    return 0;
}
