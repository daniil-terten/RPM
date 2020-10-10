#ifndef RPM_LABS_POINT_H
#define RPM_LABS_POINT_H

#include <cmath>

/**
 * A point on the plane
 */
class Point {
private:
  double x;
  double y;
public:
  Point(double x, double y){
    this->x=x;
    this->y=y;
  };

  /**
 * Get distance between two points
 * @param other Point to get distance to
 * @return Distance between points
 */
  double Distance(Point other){
    return sqrt(pow(other.y-this->y,2)+pow(other.x-this->x,2));
  }

/**
 * Moves point relatively
 * @param x
 * @param y
 */
  void Move(double x, double y) {
    this->x+=x;
    this->y+=y;
  }

  double getX() const {
    return x;
  }

  double getY() const {
    return y;
  }
};

#endif //RPM_LABS_POINT_H
