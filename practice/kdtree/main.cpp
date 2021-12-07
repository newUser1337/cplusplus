#include <iostream>
#include <cstdlib>
#include "Kdtree.h"
#include "Kdtree.cpp"
#define N 12
class Point
{
public:
    int x;
    int y;
    Point(const int &, const int &);
    Point();
    friend std::ostream &operator<<(std::ostream &, Point &);
    int GetDistance(const Point &);
    int Compare(Point &, int);
};

void point_init(Point *);

int main()
{
    Point r[N];
    point_init(r);
    
    KDTree<Point> tree(&r[0]);

    std::cout << r[0] << std::endl;
    return 0;
}

int Point::GetDistance(const Point &p)
{
    return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
}
int Point::Compare(Point &p, int dim)
{
    if (dim)
        return y - p.y;
    else
        return x - p.x;
}

Point::Point(const int &in_x, const int &in_y)
{
    x = in_x;
    y = in_y;
}

Point::Point() : x(0), y(0)
{
}

std::ostream &operator<<(std::ostream &s, Point &p)
{
    s << "(" << p.x << ", " << p.y << ")";
    return s;
}

void point_init(Point *set)
{
    set[0].x = 3;
    set[0].y = 4;

    set[1].x = 5;
    set[1].y = 8;

    set[2].x = 7;
    set[2].y = 6;

    set[3].x = 5;
    set[3].y = 2;

    set[4].x = 2;
    set[4].y = 7;

    set[5].x = 6;
    set[5].y = 9;

    set[6].x = 4;
    set[6].y = 6;

    set[7].x = 6;
    set[7].y = 3;

    set[8].x = 3;
    set[8].y = 3;

    set[9].x = 1;
    set[9].y = 1;

    set[10].x = 1;
    set[10].y = 9;

    set[11].x = 9;
    set[11].y = 7;
}