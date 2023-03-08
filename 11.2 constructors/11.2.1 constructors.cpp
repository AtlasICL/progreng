#include <iostream>
#include <cmath>
#include <string>
 
struct Point{
  double x;
  double y;

  Point(){
    x = 0;
    y = 0;
  } 
 
  Point(double ix, double iy){
    x = ix;
    y = iy;
  }
 
  std::string to_str() const {
      return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
  }
 
  double distance(Point p) const {
      return std::sqrt(std::pow((x - p.x), 2) + std::pow((y - p.y), 2));
  }
}; 
 
int main(){
  Point pa(4, 2);
  Point pb;
  
  std::cout << pa.to_str() << std::endl;
  std::cout << pb.to_str() << std::endl;
}