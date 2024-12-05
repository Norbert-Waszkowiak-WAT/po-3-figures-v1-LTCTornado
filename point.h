#ifndef POINT_H
#define POINT_H
#include <iostream>


class Point{
private:
    double x;
    double y;
public:
    Point(double x, double y);
    Point(const Point &other);
    bool equals(const Point &other);

    double getX();
    double getY();

    void flip();

    void move(double x, double y);

    std::string toString();

};
#endif