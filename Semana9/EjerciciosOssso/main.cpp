#include <iostream>
using namespace std;

// Función para crear el tablero dinámicamente
char** crearTablero(int filas, int columnas) {
    char** tablero = new char*[filas];
    for (int i = 0; i < filas; i++) {
        tablero[i] = new char[columnas];
        for (int j = 0; j < columnas; j++) {
            tablero[i][j] = '.';
        }
    }
    return tablero;
}

// Mostrar el tablero
void mostrarTablero(char** tablero, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Contar los "OSO" generados al colocar una letra
int contarOSO(char** tablero, int f, int c, int filas, int columnas) {
    int puntos = 0;

    // Direcciones: derecha, abajo, diagonal ↘ y diagonal ↙
    int dir[4][2] = {
        {0, 1},  // derecha
        {1, 0},  // abajo
        {1, 1},  // diagonal ↘
        {1, -1}  // diagonal ↙
    };

    for (int d = 0; d < 4; d++) {
        int df = dir[d][0];
        int dc = dir[d][1];

        // Comprobar patrón OSO en ambas direcciones
        for (int s = -1; s <= 1; s += 2) {
            int f1 = f + s * df;
            int c1 = c + s * dc;
            int f2 = f + 2 * s * df;
            int c2 = c + 2 * s * dc;

            if (f2 >= 0 && f2 < filas && c2 >= 0 && c2 < columnas) {
                if (tablero[f][c] == 'O' && tablero[f1][c1] == 'S' && tablero[f2][c2] == 'O')
                    puntos++;
            }
        }
    }

    return puntos;
}

// Liberar memoria del tablero
void liberarTablero(char** tablero, int filas) {
    for (int i = 0; i < filas; i++) {
        delete[] tablero[i];
    }
    delete[] tablero;
}

int main() {
    int filas, columnas;
    cout << "Filas: ";
    cin >> filas;
    cout << "Columnas: ";
    cin >> columnas;

    char** tablero = crearTablero(filas, columnas);
    int puntaje[2] = {0, 0};
    int turno = 0;  // 0 = jugador 1, 1 = jugador 2
    int jugadas = 0;
    int total = filas * columnas;

    while (jugadas < total) {
        cout << "\nTurno del jugador " << (turno + 1) << endl;
        mostrarTablero(tablero, filas, columnas);

        int f, c;
        char letra;
        cout << "Fila: ";
        cin >> f;
        cout << "Columna: ";
        cin >> c;
        cout << "Letra (O/S): ";
        cin >> letra;
        letra = toupper(letra);

        f--; c--; // Para usar índices desde 0

        if (f < 0 || f >= filas || c < 0 || c >= columnas) {
            cout << "Posición inválida.\n";
            continue;
        }
        if (tablero[f][c] != '.') {
            cout << "Casilla ocupada.\n";
            continue;
        }
        if (letra != 'O' && letra != 'S') {
            cout << "Solo se permite O o S.\n";
            continue;
        }

        tablero[f][c] = letra;
        int puntos = contarOSO(tablero, f, c, filas, columnas);

        if (puntos > 0) {
            puntaje[turno] += puntos;
            cout << "¡Hiciste " << puntos << " OSO(s)!\n";
        }

        // Pase de turno SIEMPRE
        turno = 1 - turno;
        jugadas++;
    }

    cout << "\n--- JUEGO TERMINADO ---\n";
    mostrarTablero(tablero, filas, columnas);

    cout << "Puntaje final:\n";
    cout << "Jugador 1: " << puntaje[0] << endl;
    cout << "Jugador 2: " << puntaje[1] << endl;

    if (puntaje[0] > puntaje[1])
        cout << " ¡Gana el Jugador 1!\n";
    else if (puntaje[1] > puntaje[0])
        cout << "¡Gana el Jugador 2!\n";
    else
        cout << "¡Empate!\n";

    liberarTablero(tablero, filas);
    return 0;
}




