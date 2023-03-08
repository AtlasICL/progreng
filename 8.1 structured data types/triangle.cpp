#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
 
struct Point{
    double x;
    double y;
};
 
double distance_points(Point p1, Point p2){
    return std::sqrt(std::pow((p1.x - p2.x), 2) + std::pow((p1.y - p2.y), 2));
}
 
std::string point_to_s(Point p){
    return "(" + std::to_string(p.x) + ", " + std::to_string(p.y) + ")";
}

void print_vector_Point(const std::vector<Point> vin){
  for (int i=0; i < vin.size(); i++){

    std::cout << "(" << point_to_s(vin[i]) << ")" << std::endl;
  }
}

struct Triangle{
  Point A;
  Point B;
  Point C;
};

double perimeter(const Triangle t1){
  double sum = 0;
  sum += distance_points(t1.A, t1.B);
  sum += distance_points(t1.B, t1.C);
  sum += distance_points(t1.C, t1.A);

  return sum;
}

int main(){

  Point A, B, C;

  A.x = 1;
  A.y = 3;
  B.x = 5;
  B.y = 4;
  C.x = 4;
  C.y = 1;

  Triangle t1;
  t1.A = A;
  t1.B = B;
  t1.C = C;

  double peri = perimeter(t1);
  std::cout << peri;
 
}