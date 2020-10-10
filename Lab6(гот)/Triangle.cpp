//
// Created by Huawei on 02.10.2020.
//

#include "Triangle.h"

Triangle::Triangle(std::string id, Point* p1, Point* p2, Point* p3) {
  this->id = id;
  this->type = "Triangle";

  this->pointCount = 3;
  this->points = new Point*[3];
  this->points[0] = p1;
  this->points[1] = p2;
  this->points[2] = p3;


  // Heron's formula for area
  double a = p1->Distance(*p2);
  double b = p1->Distance(*p3);
  double c = p2->Distance(*p3);
  double p = (a+b+c)/2;

  this->area = sqrt(p*(p-a)*(p-b)*(p-c));
}
