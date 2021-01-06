/**
 * @file HSLAPixel.h
 *
 */

#pragma once

#include <iostream>
#include <sstream>

namespace uiuc {
  class HSLAPixel {
    public:
      double h; // storing the hue between 0 and 360
      double s; // storing saturation between 0.0 and 1.0
      double l; // storing luminence between 0.0 and 1.0
      double a; // storing alpha between 0.0 and 1.0
  };
}
