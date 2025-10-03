#include <iostream>

using namespace std;

int contarcaracteres (char *ptr, int car){
    int contador = 0;
    while(*ptr != '\0'){
        if(*ptr== car){
            contador+=1;
        }
        ptr++;
    }
}
int main()
{
    char cad[] = "Ciencia de la computacion";
    cout << contarcaracteres(cad, 'e')<<end; //--> 2
    return 0;
}
