#include <iostream>

using namespace std;

int main()
{
    int val1 = 20;
    int val2 = 8;
    float val3 = 8;
    int suma = val1 + val2; //28
    int resta = val1 - val2; //12
    int mul = val1 * val2; //160
    int div = val1 / val2; //2 entero
    float divd = val1 / val3;  //2.5 float
    cout << "La suma es : " << suma << endl;
    cout << "La resta e es: " << resta << endl;
    cout << "La multiplicacion es: " << mul << endl;
    cout << "La div entera es: " << div << endl;
    cout << "La div es: " << divd << endl;
    return 0;

}
