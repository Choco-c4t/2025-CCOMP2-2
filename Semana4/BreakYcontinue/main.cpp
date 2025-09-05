#include <iostream>

using namespace std;

int main()
{
    /**
    * break : Rompe el bucle
    */
    int i = 1;
    cout << "Probando break: "<< endl;
    while (i<10){
        if (i == 5)
            break;
        cout << i << endl;
        i = i + 1;
    //Imprime 1 , 2, 3, 4
    }
    /**
    * continue : Salta a la siguente iteraccion
    */
    i = 0;
    cout << "Probando continue: "<< endl;
    while (i<10){
        i = i + 1;
        if( i == 5)
            continue;
        cout << i << endl;
    //Imprime 1 , 2 , 3 , 4, 6 ,7 ,8 ,9 ,10
    }
    return 0;
}
