#include <iostream>
#include <sstream>
#include <iomanip>
#include <math.h>
#include "point.h"
#include "triangle.h"

Triangle::Triangle(Point a, Point b, Point c): a(a), b(b), c(c){};
Triangle::Triangle(const Triangle &other): a(other.a), b(other.b), c(other.c){};

bool Triangle::equals(const Triangle &other){
    return a.equals(other.a) && b.equals(other.b) && c.equals(other.c);
}
void Triangle::flip(){
    a.flip();
    b.flip();
    c.flip();
}
void Triangle::move(double x, double y){
    a.move(x,y);
    b.move(x,y);
    c.move(x,y);
}


double Triangle::getSurface(){
    double AB = sqrt(pow(a.getX() - b.getX(),2) + pow(a.getY() - b.getY(),2)); //c
    double BC =sqrt(pow(b.getX() - c.getX(),2) + pow(b.getY() - c.getY(),2)); //a
    double AC =sqrt(pow(a.getX() - c.getX(),2) + pow(a.getY() - c.getY(),2)); //b

    return sqrt(((AB+BC+AC)/2)*(((AB+BC+AC)/2)-BC)*(((AB+BC+AC)/2)-AC)*(((AB+BC+AC)/2)-AB));
}

std::string Triangle::toString(){
    std::stringstream oss;
    oss << std::fixed << std::setprecision(1);
    oss << "Triangle("<< a.toString() << ", "<< b.toString() << ", " << c.toString() << ")";
    return oss.str();
}