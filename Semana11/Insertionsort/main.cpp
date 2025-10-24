#include <iostream>
#include <cmath>
using namespace std;

class Punto {  //representar como clase el punto, es mucho mejor que declararlas en el main
    public:
        int x;
        int y;
        void print(){
            cout <<"("<< x << ";" << y << ")" << endl;
        }
        void modificar(int _x , int _y){
            x = _x;
            y = _y;
        }
};

float distancia(Punto p1, Punto p2){
    return sqrt( pow((p2.x - p1.x),2) + pow((p2.y - p1.y),2) );
}

int main()
{
    Punto p1;
    p1.x = 0;
    p1.y = 0;
    p1.print();

    Punto p2;
    p2.x = 3;
    p2.y = 4;
    p2.print();

    cout<<"---------Distancia entre dos puntos---------"<<endl;
    cout << distancia(p1,p2)<<endl;

    cout<<"---------Distancia entre dos puntos---------"<<endl;

    p1.modificar(1,1);
    p2.modificar(3,4);
    p1.print();
    p2.print();
    return 0;
}
