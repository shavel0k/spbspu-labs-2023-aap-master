#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <stdio.h>
#include "base-types.hpp"

namespace reznikova
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() = 0;
    virtual rectangle_t getFrameRect() = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void move(point_t new_center) = 0;
    virtual void scale(double n) = 0;
    virtual void scale(point_t scale_center, double n) = 0;
  };
}

#endif
