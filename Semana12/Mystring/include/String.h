#ifndef STRING_H
#define STRING_H


class String
{
    public:
        String(char *data, int size);
        void setData (std::string valor, int indice);
        int getData (int indice) const;
        int getSize()const;
        void print()const;
        virtual ~String();

    private:
        int size;
        char *data;
};

#endif // STRING_H
