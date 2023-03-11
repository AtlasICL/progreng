#include <iostream>
#include <string>
#include <utility>

struct Point{

    double x;
    double y;

    Point() : x(0), y(0) {}

    Point(double ix, double iy) : x(ix), y(iy) {}

};

struct Triangle{

    Triangle(){}

    Triangle(Point iPa, Point iPb, Point iPc) : Pa(iPa), Pb(iPb), Pc(iPc) {}

    Point Pa, Pb, Pc;

};

int main(){

    std::pair<int, int> mp1;
    mp1.first = 1;
    mp1.second = 2;

    std::pair<std::string, double> mp2;
    mp2.first = "hello";
    mp2.second = 7.56;

    std::pair<Point, Triangle> mp3;
    mp3.first.x = 3;
    mp3.first.y = 2;
    Point Pa(2, 3);
    Point Pb;
    Point Pc(7, 8);
    Triangle T1(Pa, Pb, Pc);
    mp3.second = T1;

}