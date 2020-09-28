#ifndef SORTANALYS_POINT_H
#define SORTANALYS_POINT_H
/*
template <typename T>
struct point {
    T x, y;
    explicit point (T x, T y) :
            x(x), y(y)
    {}

    void move (T delta_X, T delta_Y);
};*/

struct point {
    int x, y;
    explicit point (int x, int y) :
            x(x), y(y)
    {}

    void move (int delta_X, int delta_Y);
};

#endif //SORTANALYS_POINT_H
