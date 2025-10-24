#ifndef PUNTO_H
#define PUNTO_H

//Especificacion de la clase
class Punto
{
    public:
        Punto();
        Punto(int _x , int _y);
        int getX() const; //const
        int getY() const;
        void print() const;
        void modificar(int _x, int _y);

    private:
        int x;
        int y;

};

#endif // PUNTO_H
