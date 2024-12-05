#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "group.h"

using namespace std;

Group::Group(vector<Line> lines,vector<Triangle> triangles,vector<Quadrilateral> quadrilaterals): lines(lines), triangles(triangles), quadrilaterals(quadrilaterals){};
Group::Group(const Group &other): lines(other.lines), triangles(other.triangles), quadrilaterals(other.quadrilaterals){};
Group::Group(){};

bool Group::equals(const Group &other){
    if(lines.size() == other.lines.size() && triangles.size() == other.triangles.size() && quadrilaterals.size() == other.quadrilaterals.size()){
        for(int i = 0; i < lines.size();i++){
            if(lines[i].equals(other.lines[i]) == false){
                return false;
            }
        }
        for(int i = 0; i < triangles.size();i++){
            if(triangles[i].equals(other.triangles[i]) == false){
                return false;
            }
        }
        for(int i = 0; i < quadrilaterals.size();i++){
            if(quadrilaterals[i].equals(other.quadrilaterals[i]) == false){
                return false;
            }
        }

    }
    else{
        return false;
    }
    return true;
}


void Group::remove(Line t){
    for(int i = 0; i < lines.size(); i++){
        if(lines[i].equals(t)){
            lines.erase(lines.begin() + i);
        }
    }
}
void Group::remove(Triangle t){
    for(int i = 0; i < triangles.size(); i++){
        if(triangles[i].equals(t)){
            triangles.erase(triangles.begin() + i);
        }
    }
}
void Group::remove(Quadrilateral t){
    for(int i = 0; i < quadrilaterals.size(); i++){
        if(quadrilaterals[i].equals(t)){
            quadrilaterals.erase(quadrilaterals.begin() + i);
        }
    }
}


void Group::add(Line t){
    lines.push_back(t);
}
void Group::add(Triangle t){
    triangles.push_back(t);
}
void Group::add(Quadrilateral t){
    quadrilaterals.push_back(t);
}

double Group::getSurface() {
    double result = 0;
    for (auto &triangle : triangles) {
        result += triangle.getSurface();
    }
    for (auto &quadrilateral : quadrilaterals) {
        result += quadrilateral.getSurface();
    }
    return result;
}

void Group::flip(){
    for(int i = 0; i < lines.size();i++){
        lines[i].flip();
    }
    for(int i = 0; i < triangles.size();i++){
        triangles[i].flip();
    }
    for(int i = 0; i < quadrilaterals.size();i++){
        quadrilaterals[i].flip();
    }
}

void Group::move(double x, double y){
    for(int i = 0; i < lines.size();i++){
        lines[i].move(x,y);
    }
    for(int i = 0; i < triangles.size();i++){
        triangles[i].move(x,y);
    }
    for(int i = 0; i < quadrilaterals.size();i++){
        quadrilaterals[i].move(x,y);
    }
}

std::string Group::toString(){
std::stringstream oss;
    oss << std::fixed << std::setprecision(1);
    oss << "Group(";
    for(int i = 0; i < lines.size();i++){
        oss << lines[i].toString() << ", ";
    }
    for(int i = 0; i < triangles.size();i++){
        oss << triangles[i].toString() << ", ";
    }
    for(int i = 0; i < quadrilaterals.size();i++){
        oss << quadrilaterals[i].toString() << ", ";
    }
    oss << ")";
    return oss.str();

    //"Group(Line(Point(4.0, 5.0), Point(6.0, 7.0)), Line(Point(7.0, 8.0), Point(9.0, 10.0)), )");
}



