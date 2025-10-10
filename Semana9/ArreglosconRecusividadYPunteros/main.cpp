#include <iostream>
#include <cctype>
using namespace std;

// 🧩 1. Sumar elementos de un arreglo usando puntero++
int SumarRecursivo(int* ptr, int n) {
    if (n == 0)
        return 0;

    int valor = *ptr;  // toma el valor actual
    ptr++;              // mueve el puntero al siguiente elemento
    return valor + SumarRecursivo(ptr, n - 1);
}

// 🧩 2. Mostrar los elementos en orden inverso usando puntero++
void InversoRecursivo(int* ptr, int n) {
    if (n == 0)
        return;

    InversoRecursivo(ptr + 1, n - 1); // avanza primero
    cout << *ptr << " ";              // imprime al volver
}

// 🧩 3. Contar cuántas veces aparece un número usando puntero++
int ContarRecursivo(int* ptr, int n, int numero) {
    if (n == 0)
        return 0;

    int conteo = (*ptr == numero) ? 1 : 0;
    ptr++;
    return conteo + ContarRecursivo(ptr, n - 1, numero);
}

// 🧩 4. Duplicar cada elemento del arreglo usando puntero++
void DuplicarRecursivo(int* ptr, int n) {
    if (n == 0)
        return;

    *ptr *= 2;   // duplica el valor actual
    DuplicarRecursivo(ptr + 1, n - 1);
}

// 🧩 5. Contar vocales en una cadena recursivamente (puntero++)
int ContarVocalesRec(char* texto) {
    if (*texto == '\0')
        return 0;

    char c = tolower(*texto);
    int esVocal = (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') ? 1 : 0;
    return esVocal + ContarVocalesRec(texto + 1);
}

// 🧩 6. Invertir un arreglo recursivamente usando punteros
void InvertirRecursivo(int* inicio, int* fin) {
    if (inicio >= fin)
        return;

    int temp = *inicio;
    *inicio = *fin;
    *fin = temp;
    InvertirRecursivo(inicio + 1, fin - 1);
}

// 🧩 7. Buscar un número recursivamente en un arreglo
bool BuscarNumRec(int* ptr, int n, int num) {
    if (n == 0)
        return false;

    if (*ptr == num) {
        cout << "Se encontro el numero " << num << " en la direccion: " << ptr << endl;
        return true;
    }
    return BuscarNumRec(ptr + 1, n - 1, num);
}

// 🧩 8. Calcular promedio recursivo (usando punteros)
float PromedioRec(int* ptr, int n, int suma = 0, int i = 0) {
    if (i == n)
        return (float)suma / n;
    return PromedioRec(ptr, n, suma + *(ptr + i), i + 1);
}

// 🧩 9. Mostrar arreglo (normal, no recursivo, para ver resultados)
void Mostrar(int* ptr, int n) {
    for (int i = 0; i < n; i++)
        cout << *(ptr + i) << " ";
    cout << endl;
}

// ===============================================================
// 🧠 FUNCIONES PRINCIPALES DEMOSTRATIVAS
// ===============================================================
int main() {
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int* p = arr; // 🔹 puntero al arreglo

    cout << "---------------- Sumar elementos ----------------" << endl;
    cout << "Suma: " << SumarRecursivo(p, 6) << endl;

    cout << "\n---------------- Mostrar inverso ----------------" << endl;
    InversoRecursivo(p, 6);
    cout << endl;

    cout << "\n---------------- Contar ocurrencias ----------------" << endl;
    int numero = 3;
    cout << "El numero " << numero << " aparece "
         << ContarRecursivo(p, 6, numero) << " veces." << endl;

    cout << "\n---------------- Duplicar elementos ----------------" << endl;
    DuplicarRecursivo(p, 6);
    Mostrar(p, 6);

    cout << "\n---------------- Contar vocales ----------------" << endl;
    char frase[] = "Recursion con punteros";
    cout << "Cantidad de vocales: " << ContarVocalesRec(frase) << endl;

    cout << "\n---------------- Invertir arreglo ----------------" << endl;
    int datos[] = {9, 8, 7, 6, 5};
    cout << "Antes: ";
    Mostrar(datos, 5);
    InvertirRecursivo(datos, datos + 4);
    cout << "Despues: ";
    Mostrar(datos, 5);

    cout << "\n---------------- Buscar numero ----------------" << endl;
    int lista[] = {3, 6, 9, 12, 15};
    if (!BuscarNumRec(lista, 5, 9))
        cout << "No se encontro el numero." << endl;

    cout << "\n---------------- Promedio recursivo ----------------" << endl;
    int notas[] = {14, 16, 18, 12, 20};
    cout << "Promedio: " << PromedioRec(notas, 5) << endl;

    return 0;
}
