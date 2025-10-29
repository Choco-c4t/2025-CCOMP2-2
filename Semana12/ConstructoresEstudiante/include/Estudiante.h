#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H


class Estudiante
{
    public:
        Estudiante(std::string  nombre, int edad);
        void print()const;
        ~Estudiante();

    private:
        std::string dato1;
        int dato2;
};

#endif // ESTUDIANTE_H
