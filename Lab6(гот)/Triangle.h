//
// Created by Huawei on 02.10.2020.
//

#ifndef RPM_LABS_TRIANGLE_H
#define RPM_LABS_TRIANGLE_H

#include "Polygon.h"

class Triangle : public Polygon{
public:
  /**
   * Constructs a triangle using it's three vertices
   * @param id Triangle name
   * @param p1 Vertex 1
   * @param p2 Vertex 2
   * @param p3 Vertex 3
   */
  Triangle(std::string id, Point* p1, Point* p2, Point* p3);
};


#endif //RPM_LABS_TRIANGLE_H
