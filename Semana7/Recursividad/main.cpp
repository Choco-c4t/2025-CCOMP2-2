#include <iostream>

using namespace std;

//Suma de digitos recursivamente
int sumaDigitos(int n) {
    if (n == 0) return 0;              // caso base
    return (n % 10) + sumaDigitos(n / 10); // recursión
}

//Invertir una cadena
void invertirCadena(string &s, int i, int j) {
    if (i >= j) return; // caso base
    swap(s[i], s[j]);
    invertirCadena(s, i+1, j-1);
}

//Potencia (a^b)
long long potencia(int a, int b) {
    if (b == 0) return 1;
    if (b % 2 == 0) {
        long long mitad = potencia(a, b/2);
        return mitad * mitad;
    } else {
        return a * potencia(a, b-1);
    }
}

int main()
{
    int num = 5432;
    cout << "La suma de los digitos de " << num << " es: " << sumaDigitos(num) << endl;
    string palabra = "recursividad";
    invertirCadena(palabra, 0, palabra.size()-1);
    cout << "Cadena invertida: " << palabra << endl;
    cout << "2^10 = " << potencia(2,10) << endl;
    return 0;
}
