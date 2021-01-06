#include <iostream>
#include <cmath>
#include <cstdlib>
#include "uiuc/PNG.h"
#include "uiuc/HSLAPixel.h"
#include "ImageTransform.h"

/* ******************

Name: Daniel Furman

******************** */

using uiuc::PNG;
using uiuc::HSLAPixel;

/**
 * Returns an image that has been transformed to grayscale.
 *
 */
PNG grayscale(PNG image) {
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);
      pixel.s = 0;
    }
  }
  return image;
}


/**
 * Returns an image with a spotlight centered at (`centerX`, `centerY`).
 *
 */
PNG createSpotlight(PNG image, int centerX, int centerY) {
    for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);
      
      if (sqrt((x-centerX)*(x-centerX) + (y-centerY)*(y-centerY))>160) {
        pixel.l = .2*pixel.l;
      } else {
        pixel.l = (1 - sqrt((x-centerX)*(x-centerX) + (y-centerY)*(y-centerY))*.005) *pixel.l;
      }
    }
  }
  return image;
}
 
/**
 * Returns a image transformed to Illini colors.
**/
PNG illinify(PNG image) {
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);
      if (pixel.h < 113.5 || pixel.h > 293.5) {
        pixel.h = 11;
      } else {
        pixel.h = 216;
      }
    }
  }

  return image;
}
 

/**
* Returns an immge that has been watermarked by another image.
*
*/
PNG watermark(PNG firstImage, PNG secondImage) {
    unsigned within_both_width = min(firstImage.width(), secondImage.width());
    unsigned within_both_height = min(firstImage.height(), secondImage.height());
    
    for (unsigned x = 0; x < within_both_width; x++) {
    for (unsigned y = 0; y < within_both_height; y++) {
      HSLAPixel & firstImage_pixel = firstImage.getPixel(x, y);
      HSLAPixel & secondImage_pixel = secondImage.getPixel(x, y);
      if (secondImage_pixel.l == 1.0){
        firstImage_pixel.l = firstImage_pixel.l + 0.2;
      }
    }
  }
  return firstImage;
}
