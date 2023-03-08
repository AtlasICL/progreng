#include <iostream>
#include <cmath>

struct Point{
  double x;
  double y;

  Point(){
    x = 0;
    y = 0;
  }

  Point(double inix, double iniy){
    x = inix;
    y = iniy;
  }

  void to_str(){
    std::cout << "(" << x << ", " << y << ")\n";
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
  Point Pa(3, 4);
  Point Pb(1, 1);
  double dist = Pa.distance(Pb);
  std::cout << dist;
}