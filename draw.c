#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

/*======== void add_point() ==========
Inputs:   struct matrix * points
         int x
         int y
         int z
Returns:
adds point (x, y, z) to points and increment points.lastcol
if points is full, should call grow on points
====================*/
void add_point( struct matrix * points, double x, double y, double z) {
}

/*======== void add_edge() ==========
Inputs:   struct matrix * points
          int x0, int y0, int z0, int x1, int y1, int z1
Returns:
add the line connecting (x0, y0, z0) to (x1, y1, z1) to points
should use add_point
====================*/
void add_edge( struct matrix * points,
	       double x0, double y0, double z0,
	       double x1, double y1, double z1) {
}

/*======== void draw_lines() ==========
Inputs:   struct matrix * points
         screen s
         color c
Returns:
Go through points 2 at a time and call draw_line to add that line
to the screen
====================*/
void draw_lines(struct matrix * points, screen s, color c) {
}

void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  if (x0 > x1) {
    x0 = x0 ^ x1;
    x1 = x0 ^ x1;
    x0 = x0 ^ x1;

    y0 = y0 ^ y1;
    y1 = y0 ^ y1;
    y0 = y0 ^ y1;
  }

  int a = y1 - y0;
  int b = x0 - x1;

  if (!b) { //vertical
    int y;
    for (y = y0; y <= y1; y++) plot(s, c, x0, y);
    return;
  }

  if (a > 0) {
    if (a < -b) { //octant 1
      int err = 2 * a + b;
      while (x0 < x1) {
        plot(s, c, x0, y0);
        if (err > 0) {
          y0++;
          err += b;
        }
        x0++;
        err += a;
      }
    } else { //octant 2
      int err = 2 * b + a;
      while (y0 < y1) {
        plot(s, c, x0, y0);
        if (err < 0) {
          x0++;
          err += a;
        }
        y0++;
        err += b;
      }
    }
  } else {
    if (a > b) { // octant 8
      int err = 2 * a - b;
      while (x0 < x1) {
        plot(s, c, x0, y0);
        if (err < 0) {
          y0--;
          err -= b;
        }
        x0++;
        err += a;
      }
    } else { // octant 7
      int err = -2 * b + a;
      while (y0 > y1) {
        plot(s, c, x0, y0);
        if (err > 0) {
          x0++;
          err += a;
        }
        y0--;
        err -= b;
      }
    }
  }
}
