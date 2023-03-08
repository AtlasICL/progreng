#include <iostream>
#include <cmath>
#include <string>

struct Point{
  double x;
  double y;

  Point() : x(0), y(0) { 
  }

  Point(double inix) : x(inix), y(0) {
  }

  Point(double inix, double iniy) : x(inix), y(iniy) {
  }

  std::string to_s() const {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
  }

  double distance(){
    return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
  }

  double distance(Point Pb){
    double dX = Pb.x - x;
    double dY = Pb.y - y;
    return std::sqrt(std::pow(dX, 2) + std::pow(dY, 2));
  }

};

int main(){
  Point p1(2, -0.5);
  Point p2;
  Point p3(4);
  std::cout << p1.to_s() << std::endl;
  std::cout << p2.to_s() << std::endl;
  std::cout << p3.to_s() << std::endl;
}