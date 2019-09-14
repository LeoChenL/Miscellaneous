/*
Solution 2
vector straddle
*/

#include <iostream>

class Point{
public:
  float x_,y_;

  Point(float x, float y):x_(x), y_(y){}
};

class Vector{
public:
  float x_,y_;

  Vector(Point p1, Point p2):x_(p2.x_-p1.x_), y_(p2.y_-p1.y_){}

  float CrossProduct(Vector v2){
    return x_*v2.y_ - y_*v2.x_;
  }
};

class Segment{
public:
  Point p1_,p2_;

  Segment(Point p1, Point p2):p1_(p1), p2_(p2){}

  bool Is_Straddle(Segment seg2){
    Vector v1(p1_, seg2.p1_),
           v2(p1_, seg2.p2_),
           v_seg(p1_, p2_);
    if(v_seg.CrossProduct(v1) * v_seg.CrossProduct(v2) <= 0 ){
      // = vector direction is same
      // both segments straddle check will make sure the segment interction
      return true;
    }
    else{
      return false;
    }
  }
};

int main(){
  Point p1(0,0),p2(1,1),p3(0,1),p4(5,5);
  Segment seg1(p1,p2),seg2(p3,p4);

  if(seg1.Is_Straddle(seg2) && seg2.Is_Straddle(seg1)){
    std::cout<<"Intersected"<<std::endl;
  }
  else{
    std::cout<<"Not Intersected"<<std::endl;
  }

  return 0;
}
