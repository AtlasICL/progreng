#include <iostream>

struct Vector{
  int x;
  int y;
  int z;
};

int sumVector(Vector V1, Vector V2){
  int sumX = V1.x + V2.x;
  int sumY = V1.y + V2.y;
  int sumZ = V1.z + V2.z;
  return sumZ;
}

int main(){

  Vector V1, V2;
  V1.x = 5;
  V1.y = 8;
  V1.z = 19;

  V2.x = 2;
  V2.y = 10;
  V2.z = -7;

  int r = sumVector(V1, V2);
  std::cout << r;
  
}