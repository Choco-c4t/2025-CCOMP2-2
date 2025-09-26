#include <iostream>
using namespace std;

int main() {
    int n = 2, m = 3;
    int A[n][m] = {{1, 2, 3}, {4, 5, 6}};
    int B[n][m] = {{6, 5, 4}, {3, 2, 1}};
    int C[n][m];
    int T[m][n];

    // suma de matrices
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            C[i][j] = A[i][j] + B[i][j];

    cout << "Matriz suma:\n";
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++)
        cout << C[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    //Transpuesta de una matriz

    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            T[j][i] = A[i][j];

    cout << "Matriz transpuesta:\n";
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++)
            cout << T[i][j] << " ";
        cout << endl;
    }
    //Si es simetrica
    bool simetrica = true;
    for (int i=0; i<n && simetrica; i++) {
        for (int j=0; j<n; j++) {
            if (A[i][j] != A[j][i]) {
                simetrica = false;
                break;
            }
        }
    }

    if (simetrica)
        cout << "La matriz es simétrica\n";
    else
        cout << "La matriz NO es simétrica\n";

    //Diagonal Principal y secundaria
    cout << "Diagonal principal: ";
    for (int i=0; i<n; i++)
        cout << A[i][i] << " ";
    cout << endl;

    cout << "Diagonal secundaria: ";
    for (int i=0; i<n; i++)
        cout << A[i][n-1-i] << " ";
    cout << endl;
    return 0;
}

