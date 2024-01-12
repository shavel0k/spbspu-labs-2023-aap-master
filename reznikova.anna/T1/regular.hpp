#ifndef REGULAR_HPP
#define REGULAR_HPP
#include <stdio.h>
#include <iostream>
#include <cmath>
#include "shape.hpp"
#include "base-types.hpp"

namespace reznikova
{
  class Regular : public Shape
  {
  public:
    Regular(point_t center, point_t point1, point_t point2);
    ~Regular() override = default;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const double dx, const double dy) override;
    void move(const point_t new_center) override;
    void scale(const double n) override;
    void newscale(const point_t center, const double n) override;
  private:
    point_t center_;
    point_t point1_;
    point_t point2_;
    double r;
    double R;
    double num_sides;
  };
}

#endif
