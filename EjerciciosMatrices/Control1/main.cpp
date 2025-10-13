#include <iostream>
using namespace std;

// Función para dividir dos enteros y devolver el resultado en decimal manual
void dividir(int numerador, int denominador) {
    if (denominador == 0) {
        cout << "Error: division por cero." << endl;
        return;
    }

    int* entero = new int;  // parte entera
    *entero = numerador / denominador;

    int* resto = new int;   // residuo inicial
    *resto = numerador % denominador;

    cout << "Resultado: " << *entero << ".";

    // Calcular decimal hasta 10 dígitos
    int i = 0;
    while (*resto != 0 && i < 10) {
        *resto *= 10;
        int digito = *resto / denominador;
        cout << digito;
        *resto = *resto % denominador;
        i++;
    }

    cout << endl;

    delete entero;
    delete resto;
}

// Función para verificar palíndromo usando punteros
bool esPalindromo(char* str) {
    int len = 0;
    while (*(str + len) != '\0') len++;  // calcular longitud manualmente

    char* inicio = str;
    char* fin = str + len - 1;

    while (inicio < fin) {
        if (*inicio != *fin)
            return false;
        inicio++;
        fin--;
    }
    return true;
}

int main() {
    // --- Parte 1: División ---
    int num1, num2;
    cout << "Ingrese el numerador: ";
    cin >> num1;
    cout << "Ingrese el denominador: ";
    cin >> num2;

    dividir(num1, num2);

    // --- Parte 2: Palíndromo ---
    char* texto = new char[100];
    cout << "Ingrese una palabra o numero: ";
    cin >> texto;

    if (esPalindromo(texto))
        cout << texto << " es palindromo." << endl;
    else
        cout << texto << " NO es palindromo." << endl;

    delete[] texto;
    return 0;
}

/*Con recursion:
*#include <iostream>
#include <cstring>
using namespace std;

// Funciones definidas antes
void imprimirDecimales(int resto, int denominador, int precision) {
    if (resto == 0 || precision == 0)
        return;

    resto *= 10;
    int digito = resto / denominador;
    cout << digito;
    resto = resto % denominador;

    imprimirDecimales(resto, denominador, precision - 1);
}

void dividirRecursivo(int numerador, int denominador, int precision) {
    if (denominador == 0) {
        cout << "Error: division por cero." << endl;
        return;
    }

    int* entero = new int;
    *entero = numerador / denominador;

    int* resto = new int;
    *resto = numerador % denominador;

    cout << "Resultado: " << *entero << ".";
    imprimirDecimales(*resto, denominador, precision);

    cout << endl;

    delete entero;
    delete resto;
}

bool esPalindromoRec(char* inicio, char* fin) {
    if (inicio >= fin) return true;
    if (*inicio != *fin) return false;
    return esPalindromoRec(inicio + 1, fin - 1);
}

int main() {
    // --- Parte 1: División ---
    int num1, num2;
    cout << "Ingrese el numerador: ";
    cin >> num1;
    cout << "Ingrese el denominador: ";
    cin >> num2;

    dividirRecursivo(num1, num2, 10);  // hasta 10 dígitos decimales

    // --- Parte 2: Palíndromo ---
    char* texto = new char[100];
    cout << "Ingrese una palabra o numero: ";
    cin >> texto;

    int len = 0;
    while (*(texto + len) != '\0') len++; // longitud manual

    if (esPalindromoRec(texto, texto + len - 1))
        cout << texto << " es palindromo." << endl;
    else
        cout << texto << " NO es palindromo." << endl;

    delete[] texto;
    return 0;
}
*/
