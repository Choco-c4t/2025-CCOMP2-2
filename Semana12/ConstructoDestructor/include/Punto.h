#ifndef PUNTO_H
#define PUNTO_H


class Punto
{
    public:
        Punto();
        Punto(int _x , int _y);
        void print()const;
        ~Punto();


    private:
        int x;
        int y;
};

#endif // PUNTO_H
