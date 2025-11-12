#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point();
        Point(int _x , int _y);
        void print()const;
        void setPoint (int _x , int _y);
        void push_back(int valor);

        virtual ~Point();

    private:
        int x;
        int y;
};

#endif // POINT_H
