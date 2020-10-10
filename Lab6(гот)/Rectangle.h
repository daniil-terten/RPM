//
// Created by Huawei on 02.10.2020.
//

#ifndef RPM_LABS_RECTANGLE_H
#define RPM_LABS_RECTANGLE_H

#include "Polygon.h"

class Rectangle : public Polygon{
public:
  /**
   * Constructs a rectangle using its diagonal points
   * @param id Rectangle name
   * @param tl Top-left point
   * @param br Bottom-right point
   */
  Rectangle(std::string id, Point tl, Point br);
};


#endif //RPM_LABS_RECTANGLE_H
