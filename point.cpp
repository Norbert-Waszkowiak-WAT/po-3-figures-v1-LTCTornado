#include <iostream>
#include <sstream>
#include <iomanip>
#include "point.h"


Point::Point(double x, double y): x(x), y(y){};
Point::Point(const Point &other):x(other.x), y(other.y){};
bool Point::equals(const Point &other){
    return x == other.x && y == other.y;
}

double Point::getX(){
    return x;
}
double Point::getY(){
    return y;
}

void Point::flip(){
    x = -x;
    y = -y;
}

void Point::move(double x2, double y2){
    x += x2;
    y += y2;
}

std::string Point::toString(){
    std::stringstream oss;
    oss << std::fixed << std::setprecision(1);
    oss << "Point(" << x << ", " << y << ")";
    return oss.str();
}