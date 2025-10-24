#ifndef VECTOR_H
#define VECTOR_H

#include "Punto.h"

class Vector
{
    public:
        Vector(Punto p1, Punto p2);
        void print()const;
        float modulo()const;
    private:
        Punto ini;
        Punto fin;
};

#endif // VECTOR_H
