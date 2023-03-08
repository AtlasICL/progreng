#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

struct Point{
  
  double x;
  double y;

  void print() const {
    std::cout << "(" << x << ", " << y << ")\n";
  }

  double distance(Point Pb) const {
    return std::sqrt( std::pow((x - Pb.x), 2) + std::pow((y - Pb.y), 2) );
  }

  std::string to_s() const {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }

};

struct Pair{
  Point Pa;
  Point Pb;

  void print(){
    std::cout << "[" << Pa.to_s() << Pb.to_s() << "]";
  }
};

struct Triangle{
  Point a;
  Point b;
  Point c;

  double perimeter(){
    return a.distance(b) + b.distance(c) + c.distance(a);
  }
};

int main(){
  
  std::ifstream infile;
  infile.open("Week 5 - trees and member functions//11.1//points_input.txt");

  if (!infile.is_open()){
    std::cout << "error opening input file";
    EXIT_FAILURE;
  }

  Point tmp;
  std::vector<Point> vin;
  while (infile >> tmp.x >> tmp.y){
    vin.push_back(tmp);
  }
  infile.close();

  for (int i=0; i<vin.size(); i++){
    vin[i].print();
  }

  double minimum_distance;
  if (vin.size() < 2){
    EXIT_FAILURE;
  }

  minimum_distance = vin[0].distance(vin[1]);
  
  Pair closestPoints;
  int j;
  int i = 1;
  
  while (i<vin.size()){

    j = i-1;
    
    while (j<vin.size()) {  
      if (j==i){
        j++;
      }
      
      if (vin[i].distance(vin[j]) < minimum_distance){
        minimum_distance = vin[i].distance(vin[j]);
        closestPoints.Pa = vin[i];
        closestPoints.Pb = vin[j];
      }
      j++;
    }
    
    i++;
    
  }

  closestPoints.print();
    
}