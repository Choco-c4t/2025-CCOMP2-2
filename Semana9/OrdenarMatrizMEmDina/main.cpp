#include <iostream>
#include <cstdlib>
#include <ctime>

void caratula() {
    std::cout << "=== MATRIZ DE LETRAS Y NUMEROS DINAMICA ===\n";
}


int main() {
    caratula();

    int filas = 4, cols = 4;

    // Crear matriz dinámica
    char** LetrasNumeros = new char*[filas];
    char** LetrasNumerosOrdenado = new char*[filas];
    for (int i = 0; i < filas; i++) {
        LetrasNumeros[i] = new char[cols];
        LetrasNumerosOrdenado[i] = new char[cols];
    }

    char tmpMayusculas[6], tmpMinusculas[6], tmpNumeros[4];

    std::srand(std::time(nullptr)); // semilla aleatoria

    // Llenar array de letras mayúsculas y minúsculas
    for (int i = 0; i < 6; i++) {
        tmpMayusculas[i] = 65 + std::rand() % 26; // A-Z
        tmpMinusculas[i] = 97 + std::rand() % 26; // a-z
        std::cout << "Letra mayuscula: " << tmpMayusculas[i]
                  << " | Letra minuscula: " << tmpMinusculas[i] << std::endl;
    }

    // Llenar array de números
    for (int i = 0; i < 4; i++) {
        tmpNumeros[i] = 48 + std::rand() % 10; // 0-9
        std::cout << "Numero: " << tmpNumeros[i] << std::endl;
    }

    // Llenar LetrasNumeros aleatoriamente con los valores de tmp
    int idxMayus = 0, idxMinus = 0, idxNum = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            bool asignado = false;
            do {
                int option = std::rand() % 3;
                switch (option) {
                    case 0:
                        if (idxMayus < 6) {
                            LetrasNumeros[i][j] = tmpMayusculas[idxMayus++];
                            asignado = true;
                        }
                        break;
                    case 1:
                        if (idxMinus < 6) {
                            LetrasNumeros[i][j] = tmpMinusculas[idxMinus++];
                            asignado = true;
                        }
                        break;
                    case 2:
                        if (idxNum < 4) {
                            LetrasNumeros[i][j] = tmpNumeros[idxNum++];
                            asignado = true;
                        }
                        break;
                }
            } while (!asignado);
        }
    }

    // Mostrar matriz aleatoria
    std::cout << "\nMatriz LetrasNumeros:\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++)
            std::cout << LetrasNumeros[i][j] << " | ";
        std::cout << std::endl;
    }

    // REORDENAR matriz como en tu lógica original
    idxMayus = 0; idxMinus = 0; idxNum = 0;

    // Primer paso: colocar mayúsculas y minúsculas según cuadrantes
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            LetrasNumerosOrdenado[i][j] = '-';
            if (i < 2 && j < 2) LetrasNumerosOrdenado[i][j] = tmpMayusculas[idxMayus++];
            else if (i >= 2 && j >= 2) LetrasNumerosOrdenado[i][j] = tmpMinusculas[idxMinus++];
        }
    }

    // Segundo paso: completar los cuadrantes faltantes con mayúsculas/minúsculas
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            if (i < 2 && j >= 2 && idxMayus < 6) LetrasNumerosOrdenado[i][j] = tmpMayusculas[idxMayus++];
            else if (i >= 2 && j < 2 && idxMinus < 6) LetrasNumerosOrdenado[i][j] = tmpMinusculas[idxMinus++];
        }
    }

    // Tercer paso: llenar números
    idxNum = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++) {
            if ((i < 2 && j >= 2) || (i >= 2 && j < 2)) {
                if (LetrasNumerosOrdenado[i][j] == '-' && idxNum < 4)
                    LetrasNumerosOrdenado[i][j] = tmpNumeros[idxNum++];
            }
        }
    }

    // Mostrar matriz reordenada
    std::cout << "\nMatriz LetrasNumerosOrdenado:\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < cols; j++)
            std::cout << LetrasNumerosOrdenado[i][j] << " | ";
        std::cout << std::endl;
    }

    // Liberar memoria dinámica
    for (int i = 0; i < filas; i++) {
        delete[] LetrasNumeros[i];
        delete[] LetrasNumerosOrdenado[i];
    }
    delete[] LetrasNumeros;
    delete[] LetrasNumerosOrdenado;

    return 0;
}

