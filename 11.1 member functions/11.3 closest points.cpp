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

  double minimum_distance = INT8_MAX;
  Pair closestPoints;

  for (int i = 0; i<vin.size(); i++){
    
    for (int j = 0; j<vin.size(); j++){

      if (j == i){
        j++;
      }
      
      if (vin[i].distance(vin[j]) < minimum_distance){
        minimum_distance = vin[i].distance(vin[j]);
        closestPoints.Pa = vin[i];
        closestPoints.Pb = vin[j];
      }
      
    }
  
  }

  closestPoints.print();
    
}