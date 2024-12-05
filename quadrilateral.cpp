#include <iostream>
#include "quadrilateral.h"
#include "point.h"
#include <sstream>
#include <iomanip>

Quadrilateral::Quadrilateral(Point a, Point b, Point c, Point d): a(a), b(b), c(c), d(d){};
Quadrilateral::Quadrilateral(const Quadrilateral &other): a(other.a), b(other.b), c(other.c), d(other.d){};

bool Quadrilateral::equals(const Quadrilateral &other){
    return a.equals(other.a) && b.equals(other.b) && c.equals(other.c) && d.equals(d);
}

void Quadrilateral::flip(){
    a.flip();
    b.flip();
    c.flip();
    d.flip();
}
void Quadrilateral::move(double x, double y){
    a.move(x,y);
    b.move(x,y);
    c.move(x,y);
    d.move(x,y);
}
double Quadrilateral::getSurface(){
    return (abs(a.getX()*(b.getY() - d.getY()) + b.getX()*(c.getY() - a.getY()) + c.getX()*(d.getY() - b.getY()) + d.getX()*(a.getY() - c.getY())))/2;                                           // 4* 3 + 4*
}

std::string Quadrilateral::toString(){
    std::stringstream oss;
    oss << std::fixed << std::setprecision(1);
    oss << "Quadrilateral("<< a.toString() << ", "<< b.toString() << ", " << c.toString() << ", " << d.toString() << ")";
    return oss.str();
}
