#include <iostream>

using namespace std;

int main()
{
    int c = 10;
    int a = c++; //(asigno luego incremento)
    cout<< a << endl; //10
    cout<< c << endl; //11
    int b = ++c; //(incremento luego asigno)
    int d = ++c;
    cout<< b<< endl; //12
    cout<< d << endl; //13
    int e = --c;
    cout<< e << endl; //12

    int f = 10;
    int g = --c;
    cout<< ++a << endl; //11
    cout<< c-- << endl; //11


    return 0;
}
