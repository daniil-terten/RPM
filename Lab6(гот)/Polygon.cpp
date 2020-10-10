//
// Created by Huawei on 02.10.2020.
//

#include "Polygon.h"
#include <limits>

void Polygon::Move(double x, double y) {
  for(int i=0; i < this->pointCount; i ++){
    (this->points[i])->Move(x,y);
  }
}

int Polygon::Compare(Polygon other) {
  if(this->area==other.area){
    return 0;
  }
  if(this->area>other.area){
    return 1;
  }
  return -1;
}

double Polygon::getArea() const {
  return area;
}

Point* Polygon::getPos() {
  /*
  Point* minPoint = new Point(std::numeric_limits<float>::max(),std::numeric_limits<float>::max());
  for(int i=0; i < this->pointCount; i ++){
    //std::cout << "Checking " << this->points[i]->getX() << " "  << this->points[i]->getY() << " vs " << minPoint->getX() << " " << minPoint->getY() << "\n";
    if(this->points[i]->getX()<=minPoint->getX() and this->points[i]->getY()>=minPoint->getY()){
      minPoint = this->points[i];
    }
  }
  return minPoint;*/
  // this doesn't work. Too bad!
  return this->points[0];
}

std::string Polygon::getType() const {
  return type;
}

const std::string &Polygon::getId() const {
  return id;
}
