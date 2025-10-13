#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

    char matriz[5][5];
    srand(time(nullptr));

    for(int i = 0; i<5 ; i++ ){
        for(int j = 0; j<5 ; j++){
            if((i+j)%2 == 0){
                int random_value = 48 + rand()%10;
                matriz[i][j]= (char)random_value;
            } else{
                int random_value = 97 + rand()%26;
                matriz[i][j]=(char)random_value;
            }
        }
    }
    for(int i = 0; i<5 ; i++ ){
        for(int j = 0; j<5 ; j++){
                cout<<matriz[i][j]<<"|";
        }
        cout<<endl;
    }

    char matriz[5][5];
    srand(time(nullptr));

    for(int i = 0; i<5 ; i++){
        for(int j = 0; j<5 ; j++){
            if(i==0| i==4 || j==0 | j==4){
                int random_value = 48 + rand()%10;
                matriz[i][j] = (char)random_value;
            }else{
                int random_value = 97 + rand()%26;
                matriz[i][j] = (char)random_value;
            }
        }
    }
    for(int i = 0; i<5 ; i++){
        for(int j = 0; j<5 ; j++){
                cout<<matriz[i][j]<<"|";
        }
        cout<<endl;
    }
    return 0;
}
