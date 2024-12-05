#ifndef GROUP_H
#define GROUP_H
#include "line.h"
#include "triangle.h"
#include "quadrilateral.h"
#include <vector>
#include <iostream>

using namespace std;

class Group{
private:
    vector<Line> lines;
    vector<Triangle> triangles;
    vector<Quadrilateral> quadrilaterals;
public:
    Group(vector<Line> lines, vector<Triangle> triangles, vector<Quadrilateral> quadrilaterals);
    Group(const Group &other);
    Group();

    bool equals(const Group &other);
    
    void remove(Line t);
    void remove(Triangle t);
    void remove(Quadrilateral t);

    void add(Line t);
    void add(Triangle t);
    void add(Quadrilateral t);

    double getSurface();
    
    void flip();
    void move(double x, double y);

    std::string toString();


};
#endif