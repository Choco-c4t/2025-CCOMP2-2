#ifndef INTEGERARRAY_H
#define INTEGERARRAY_H
#include <iostream>

class IntegerArray
{
    public:
        IntegerArray(int size);
        void setData(int valor,int index);
        int getData(int index) const;
        int getSize()const;
        void print()const;
        virtual ~IntegerArray();

    private:
        int size;
        int *data;
};

#endif // INTEGERARRAY_H
