struct Triangle{
  Point a;
  Point b;
  Point c;

  double perimeter(){
    return a.distance(b) + b.distance(c) + c.distance(a);
  }

};