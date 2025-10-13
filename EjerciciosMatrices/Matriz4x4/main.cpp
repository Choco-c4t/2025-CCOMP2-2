#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // Crear una matriz 4x4 con letras mayusculas, minusculas y numeros
    char LetrasNumeros[4][4];
    char tmpMayusculas[4];
    char tmpMinusculas[4];
    char tmpNumeros[8];

    // semilla aleatoria
    std::srand(std::time(nullptr));

    // Generar mayúsculas
    for(int i = 0; i < 4; i++)
    {
        int random_value = std::rand() % 26;
        tmpMayusculas[i] = 65 + random_value; // A-Z
    }

    // Generar minúsculas
    for(int i = 0; i < 4; i++)
    {
        int random_value = std::rand() % 26;
        tmpMinusculas[i] = 97 + random_value; // a-z
    }

    // Generar números
    for(int i = 0; i < 8; i++)
    {
        int random_value = std::rand() % 10;
        tmpNumeros[i] = 48 + random_value; // 0-9
    }

    // Índices para recorrer los arrays temporales
    int idxMayus = 0, idxMinus = 0, idxNum = 0;

    // Primer cuadrante (arriba izquierda): MAYÚSCULAS
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            LetrasNumeros[i][j] = tmpMayusculas[idxMayus++];
        }
    }

    // Segundo cuadrante (arriba derecha): NÚMEROS
    for(int i = 0; i < 2; i++)
    {
        for(int j = 2; j < 4; j++)
        {
            LetrasNumeros[i][j] = tmpNumeros[idxNum++];
        }
    }

    // Tercer cuadrante (abajo izquierda): NÚMEROS
    for(int i = 2; i < 4; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            LetrasNumeros[i][j] = tmpNumeros[idxNum++];
        }
    }

    // Cuarto cuadrante (abajo derecha): MINÚSCULAS
    for(int i = 2; i < 4; i++)
    {
        for(int j = 2; j < 4; j++)
        {
            LetrasNumeros[i][j] = tmpMinusculas[idxMinus++];
        }
    }

    // Mostrar matriz final
    std::cout << "Matriz final (4x4):" << std::endl;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            std::cout << LetrasNumeros[i][j] << " | ";
        }
        std::cout << std::endl;
    }

    return 0;
}

