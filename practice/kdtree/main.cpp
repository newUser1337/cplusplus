#include <iostream>
#include <cstdlib>
#include "Kdtree.h"
#include "Kdtree.cpp"
#define N 12
class Point
{
public:
    int x[2];
    Point(const int &, const int &);
    Point();
};

void point_init(Point *);

int main()
{
    Point r[N];
    point_init(r);

    KDTree<int> tree(2);
    for (int i = 0; i < N; i++)
        tree.Add(r[i].x);
    std::cout << tree;

    return 0;
}

Point::Point(const int &in_x, const int &in_y)
{
    x[0] = in_x;
    x[1] = in_y;
}

Point::Point()
{
    x[0] = 0;
    x[1] = 0;
}

void point_init(Point *set)
{
    set[0].x[0] = 3;
    set[0].x[1] = 4;

    set[1].x[0] = 5;
    set[1].x[1] = 8;

    set[2].x[0] = 7;
    set[2].x[1] = 6;

    set[3].x[0] = 5;
    set[3].x[1] = 2;

    set[4].x[0] = 2;
    set[4].x[1] = 7;

    set[5].x[0] = 6;
    set[5].x[1] = 9;

    set[6].x[0] = 4;
    set[6].x[1] = 6;

    set[7].x[0] = 6;
    set[7].x[1] = 3;

    set[8].x[0] = 3;
    set[8].x[1] = 3;

    set[9].x[0] = 1;
    set[9].x[1] = 1;

    set[10].x[0] = 1;
    set[10].x[1] = 9;

    set[11].x[0] = 9;
    set[11].x[1] = 7;
}