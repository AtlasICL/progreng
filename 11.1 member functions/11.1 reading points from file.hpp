#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
 
struct Point{
  double x;
  double y;

  std::string to_s(){
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    // here x and y are the x and y of the Point variable on which the function is called
  }

  void print(){
    std::cout << "(" << x << ", " << y << ")" << std::endl;
  }
 
  double distance(Point p){
    return std::sqrt(std::pow((x - p.x), 2) + std::pow((y - p.y), 2));
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
  
  
}