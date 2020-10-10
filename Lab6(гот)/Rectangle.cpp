//
// Created by Huawei on 02.10.2020.
//

#include "Rectangle.h"

Rectangle::Rectangle(std::string id, Point tl, Point br) {
  this->id = id;
  this->type = "Rectangle";

  this->pointCount = 4;
  this->points = new Point*[4];
  this->points[0] = new Point(tl.getX(),tl.getY());
  this->points[1] = new Point(br.getX(),tl.getY());
  this->points[2] = new Point(br.getX(),br.getY());
  this->points[3] = new Point(tl.getX(),br.getY());

  std::cout << "!!" << this->points[0]->getX();
  double a = tl.Distance(*this->points[1]);
  double b = tl.Distance(*this->points[3]);
  this->area = a*b;
}
