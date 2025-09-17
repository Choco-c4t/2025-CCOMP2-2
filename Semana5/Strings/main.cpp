#include <iostream>

using namespace std;


int main()
{
    string cad = "Ciencia de la computacion";
    // " " -> para strings
    // ' ' -> para caracteres
    cout << cad << endl;
    char a = 'a';
    cout << a << endl;
    cout << cad.at(5) << endl; //5 (cuenta desde 0)

    // programa para contar el numero de letras de un string (caracter de fin de cadena ->  '\0 '
    int contador = 0;
    int i = 0;
    for (int i = 0; i < cad.size();i++){
    }
    cout << i << endl;

    //contar la cantidad de cierto caracter que hay en un string
    string cadena = "Ciencia de la computacion";
    char caracter = 'i';
    int cantidad = 0;
    for (int j = 0; j < cadena.size();j++){
        if (cad.at(j) ==  caracter){
            cantidad++;
        }
    }
    cout << "La cantidad de "<<caracter<<" es: "<< cantidad<< endl;
    //dada una cadena verificar si dicha cadena es palindromo

    string cadenaa;
    //el cin se detiene cuando hay un espacio en blanco
    cout<<"Ingrese una cadena: "<<endl;
    getline(cin,cadenaa); //para recibir strings
    bool Espalindromo = true;
    int inicio =0;
    int fin =cadenaa.length() -1;
    while (inicio < fin){
        if (cadenaa.at(inicio)!= cadenaa.at(fin)){
            Espalindromo= false;
            break;
        }
        inicio++;
        fin--;
    }
    if (Espalindromo == true){
        cout<<"La cadena es palindromo"<<endl;
    }else{
        cout<<"La cadena no es palindromo"<<endl;
    }
    return 0;
}
