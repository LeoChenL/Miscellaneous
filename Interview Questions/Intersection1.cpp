/*
Tusimple Interview
Given two line segments, determine if there are any intersections

Solution 1:
	斜截式表示直线
	判断平行，非平行求交点
	判断交点位置是否在线段上
Issue:
	垂直与x轴的直线，斜截式难以表示
	平行线段相交
*/

#include <iostream>
#include <algorithm>
#include <stdlib.h>

const float eps = 1e-8;
const float tolerance = 1e-4;

class Point{
public:
  float x_;
  float y_;

  Point(float x, float y):x_(x),y_(y){}
};


class Segment{
public:
  Point p1_, p2_;
  float a_, b_;

  Segment(Point p1, Point p2):p1_(p1), p2_(p2){
    a_ = (p1.y_-p2.y_)/(p1.x_-p2.x_+eps); // for line that perpendicular to x axis
    b_ = p1.y_ - a_ * p1.x_;
  }

  float IntersectionPoint(Segment seg2){
    float x;
    x = (seg2.b_-b_)/(a_-seg2.a_);
    return x;
  }

  bool Is_Intersect(Segment seg2){
    if(abs(a_-seg2.a_) < tolerance){
      // line parallel
      if( abs(b_-seg2.b_)<tolerance &&
          ((std::min(p1_.x_,p2_.x_)>=std::min(seg2.p1_.x_,seg2.p2_.x_)) &&
           (std::min(p1_.x_,p2_.x_)<=std::max(seg2.p1_.x_,seg2.p2_.x_))) ||
          ((std::min(seg2.p1_.x_,seg2.p2_.x_)>=std::min(p1_.x_,p2_.x_)) &&
           (std::min(seg2.p1_.x_,seg2.p2_.x_)<=std::max(p1_.x_,p2_.x_))) ){
        return true;
      }
      else{
        return false;
      }
    }
    else{
      // not parallel
      float x_interscetion = IntersectionPoint(seg2);
      if( std::min(p1_.x_,p2_.x_)<=x_interscetion &&
          std::max(p1_.x_,p2_.x_)>=x_interscetion ){
        return true;
      }
      else{
        return false;
      }
    }
  }
};

int main(){
  Point p1(0,0),p2(3,3),p3(0,1),p4(1,0);
  Segment seg1(p1,p2),seg2(p3,p4);

  if( seg1.Is_Intersect(seg2) ){
    std::cout<<"Intersected"<<std::endl;
  }
  else{
    std::cout<<"Not Intersected"<<std::endl;
  }
}
