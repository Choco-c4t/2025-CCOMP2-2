#ifndef DINAMICINTEGERARRAY_H
#define DINAMICINTEGERARRAY_H


class DinamicIntegerArray
{
    public:
        DinamicInteguerArray();
        DinamicInteguerArray(int arr[], int size);
        DinamicIntegerArray(DinamicIntegerArray &o);
        int getsize()const;
        void print()const;

        void push_back(int valor);
        void insert()
        ~DinamicInteguerArray();

    protected:

    private:
        int* data;
        int size;
};

#endif // DINAMICINTEGERARRAY_H
