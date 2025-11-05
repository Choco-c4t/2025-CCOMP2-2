#ifndef STRING_H
#define STRING_H


class String
{
    public:
        String(char *data);
        int StringSize()const;
        char* getData()const;

        void toUpper(char *data);
        void toLower(char *data);
        virtual ~String();


    private:
        int size;
        char *data;
};

#endif // STRING_H
