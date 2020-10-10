#ifndef RPM_LABS_POLYGON_H
#define RPM_LABS_POLYGON_H

#include <iostream>
#include "Point.h"

/**
 * An abstract polygon shape
 */
class Polygon {
protected:
  std::string id;
public:
  const std::string &getId() const;

protected:
  int pointCount;
  double area;
  Point** points;
  std::string type;
public:
  double getArea() const;
  std::string getType() const;
  /**
   * A polygon's position is the position of it's point
   * @return Reference to a point at (x,y) position of polygon
   */
  Point* getPos();
public:
  /**
   * Moves a polygon relatively
   * @param x
   * @param y
   */
  void Move(double x, double y);
  /**
   * Check if area of this polygon is more than the other's
   * @param other Polygon to compare
   * @return 1 if this polygon is bigger, -1 if the other's is bigger, 0 if equal
   */
  int Compare(Polygon other);
};


#endif //RPM_LABS_POLYGON_H
