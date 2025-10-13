#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    //crear matriz
    char matriz[5][5];
    srand(time(nullptr));
    int centro = 2;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5 ; j++){
            if(i == centro || j == centro){
                //num 0-9
                int random_value = 48 + rand()%10;
                matriz[i][j]= (char)random_value;
            } else {
                int random_value = 97 + rand()%26;
                matriz[i][j]= (char)random_value;
            }
        }
    }

    cout << "Matriz 5x5 con cruz:" << endl;
    for(int i = 0; i < 5; i++){
        for(int j = 0 ; j < 5; j++ ){
            cout<< matriz[i][j]<<" | ";
        }
        cout << endl;
    }

    return 0;

}
