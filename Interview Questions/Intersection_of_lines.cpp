/*
Tusimple Interview
Given two line segments, determine if there are any intersections
*/

#include <iostream>
#include <algorithm>
#include <stdlib.h>

class Point{
public:
  float x_;
  float y_;

  Point(float x, float y):x_(x),y_(y){}
};

class Line{
public:
  float a_;
  float b_;

  Line(Point p1, Point p2){
    a_ = (p1.y_-p2.y_)/(p1.x_-p2.x_+0.00001); // for line that perpendicular to x axis
    b_ = p1.y_ - a_ * p1.x_;
  }
};

float IntersectionPoint(Line l1, Line l2){
  float x;
  x = (l2.b_-l1.b_)/(l1.a_-l2.a_);
  std::cout<<"intersection x:"<<x<<std::endl;
  return x;
}

int main(){
  Point p1(1,1),p2(3,3),p3(0,1),p4(1,2);
  Line l1(p1,p2),l2(p3,p4);

  if(abs(l1.a_-l2.a_) < 0.0001){
    // line parallel
    std::cout<<"abs b:"<<abs(l1.b_-l2.b_)<<std::endl;
    if( abs(l1.b_-l2.b_)<0.0001 &&
        ((std::min(p1.x_,p2.x_)>=std::min(p3.x_,p4.x_)) &&
        (std::min(p1.x_,p2.x_)<=std::max(p3.x_,p4.x_))) ||
        ((std::min(p3.x_,p4.x_)>=std::min(p1.x_,p2.x_)) &&
        (std::min(p3.x_,p4.x_)<=std::max(p1.x_,p2.x_))) ){
          std::cout<<"Parrallel Line Segments Intersected"<<std::endl;
    }
    else{
      std::cout<<"Parrallel Line Segments not Intersected"<<std::endl;
    }
  }
  else{
    // not parallel
    float x_interscetion = IntersectionPoint(l1,l2);
    if( std::min(p1.x_,p2.x_)<=x_interscetion &&
        std::max(p1.x_,p2.x_)>=x_interscetion ){
          std::cout<<"Line Segments Intersected"<<std::endl;
        }
        else{
          std::cout<<"Line Segments not Intersected"<<std::endl;
        }

  }

}
