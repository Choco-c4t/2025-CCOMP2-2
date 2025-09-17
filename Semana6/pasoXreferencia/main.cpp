#include <iostream>

using namespace std;

//Una funcion que reciba dos num enteros e intercambia sus valores

void Intercambio(int &a , int &b) //con & podemos realizar
{
    int c = a;
    a = b;
    b = c;
}

int main()
{
    int x = 10;
    int y = 20;
    Intercambio(x,y);
    cout<<x<<endl;
    cout<<y<<endl;
    return 0;
}
