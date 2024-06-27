#include "class.h"

Point::Point(double nx, double ny) {
    x = nx;
    y = ny;
}

Point::Point(Point &np) {
    x = np.x;
    y = np.y;
}
Point::~Point(){
    
}

void Point::SetX(double nx) {
    x = nx;
}

void Point::SetY(double ny) {
    y = ny;
}

void Point::SetPoint(double nx, double ny) {
    SetX(nx);
    SetY(ny);
}

void Point::SetPoint(Point &np) {
    SetX(np.x);
    SetY(np.y);
}