#ifndef DINAMICINTEGUERARRAY_H
#define DINAMICINTEGUERARRAY_H


class DinamicInteguerArray
{
    public:
        DinamicInteguerArray();
        DinamicInteguerArray(int arr[], int size);
        int getsize()const;
        void print()const;

        void push_back(int valor); // para armar el metodo
        // 1.reservar memoria para un arreglo tmp de tamaño de size +1
        // 2.Copiar los elementos de data a tmp, saltando la posicion pos.
        // 3.Copiar val al final de tmp (a la posicion pos)
        // 4.Actualizar tamaño
        // 5.LIBERAR LA MEMORIA APUNTADA POR DATA
        // 6.Data apunte a tmp

        ~DinamicInteguerArray();

    protected:

    private:
        int* data;
        int size;
};

#endif // DINAMICINTEGUERARRAY_H
