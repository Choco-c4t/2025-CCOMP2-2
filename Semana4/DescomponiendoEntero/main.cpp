#include <iostream>

using namespace std;

int main()
{
    int num; // declarando numero
    cout << "Ingrese un numero de 4 digitos : ";
    cin >> num;

    cout << "n El numero ingresador es: "<<num<<endl;

    //3245
    cout << num / 100<< endl; //3
    cout << (num % 1000) / 100<< endl; //2
    cout <<(num % 100) / 10<< endl; //4
    cout <<num % 10<< endl; //5
    return 0;
}
