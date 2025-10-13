#include <iostream>
using namespace std;

// Funcion para crear un tablero dinamico
char** crearTablero(int tamano) {
    char** tablero = new char*[tamano];
    for (int i = 0; i < tamano; i++) {
        tablero[i] = new char[tamano];
        for (int j = 0; j < tamano; j++)
            tablero[i][j] = ' '; // Inicializa con espacios
    }
    return tablero;
}

// Funcion para mostrar el tablero
void mostrarTablero(char** tablero, int tamano) {
    cout << "\n";
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            cout << " " << tablero[i][j] << " ";
            if (j < tamano - 1) cout << "|";
        }
        cout << "\n";
        if (i < tamano - 1) {
            for (int k = 0; k < tamano; k++) {
                cout << "---";
                if (k < tamano - 1) cout << "+";
            }
            cout << "\n";
        }
    }
    cout << "\n";
}

// Funcion para comprobar si alguien gano
char comprobarGanador(char** tablero, int tamano) {
    // Filas y columnas
    for (int i = 0; i < tamano; i++) {
        if (tablero[i][0] != ' ' && tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2])
            return tablero[i][0];
        if (tablero[0][i] != ' ' && tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i])
            return tablero[0][i];
    }
    // Diagonales
    if (tablero[0][0] != ' ' && tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2])
        return tablero[0][0];
    if (tablero[0][2] != ' ' && tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0])
        return tablero[0][2];

    return ' '; // No hay ganador aun
}

// Funcion para liberar memoria
void liberarTablero(char** tablero, int tamano) {
    for (int i = 0; i < tamano; i++)
        delete[] tablero[i];
    delete[] tablero;
}

int main() {
    int tamano = 3;
    char** tablero = crearTablero(tamano);
    char jugador = 'X';
    int fila, columna;
    int turnos = 0;
    char ganador = ' ';

    cout << "Juego de Tres en Raya\n";

    while (ganador == ' ' && turnos < tamano * tamano) {
        mostrarTablero(tablero, tamano);
        cout << "Turno del jugador " << jugador << ". Ingresa fila y columna (0-2): ";
        cin >> fila >> columna;

        if (fila >= 0 && fila < tamano && columna >= 0 && columna < tamano && tablero[fila][columna] == ' ') {
            tablero[fila][columna] = jugador;
            turnos++;
            ganador = comprobarGanador(tablero, tamano);
            jugador = (jugador == 'X') ? 'O' : 'X';
        } else {
            cout << "Movimiento invalido, intenta de nuevo.\n";
        }
    }

    mostrarTablero(tablero, tamano);

    if (ganador != ' ')
        cout << "Felicidades! El jugador " << ganador << " gana.\n";
    else
        cout << "Empate!\n";

    liberarTablero(tablero, tamano);
    return 0;
}

