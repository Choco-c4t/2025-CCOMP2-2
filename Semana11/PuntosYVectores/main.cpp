#include <iostream>
#include <cmath>
using namespace std;


//Clases es para inicializar un nuevo tipo de dato
class Punto {
    private: // Son accesibles solamente dentro de la clase
        int x;
        int y;
    public: //Son accesibles en cualquier lugar

        //Definir dos constructores uno que no recibe nada y otro que recibe dos enteros
        Punto(){
            x = 0;
            y = 0;
        }
        Punto(int _x , int _y){
            x = _x;
            y = _y;
        }
        //------------Metodo get-------------(Para acceder a los elementos privados)

        int getX() const {
            return x;
        }
        int getY() const {
            return y;
        }

        void print(){
            cout <<"("<< x << ";" << y << ")";
        }

        void modificar(int _x , int _y){ //el guion bajo es solo un nombre , para no confundirse con x
            x = _x;
            y = _y;
        }
};

class VectorGeometrico{ //Un vector tiene dos puntos el inicio y el fin
        Punto inicio; //Inicializamos como Punto para utilizar sus funciones
        Punto fin;
    public:
        //Construimos un constructor que recibe dos datos de tipo Punto
        VectorGeometrico(Punto p1, Punto p2){
            inicio = p1;
            fin = p2;
        }

        void print(){
            inicio.print(); //llamamos la funcion de la clase Punto
            cout <<" -> ";
            fin.print();
        }

        float modulo(){
            return sqrt(pow((fin.getX()-inicio.getX()),2)+ pow((fin.getY()-inicio.getY()),2));   //Como fin.x etc son elementos privados utilizamos el metodo get para acceder a ellos
        }
};



int main()
{
    Punto p1; //sera 0,0
    Punto p2(3,4); //sera 3,4
    VectorGeometrico vg(p1,p2); //Inicio= 0,0 y Fin= 3,4
    vg.print(); //Imprimimos el vector

    cout<<"\nEl modulo entre el punto p1 y p2 es: " << vg.modulo()<<endl;
    return 0;
}
