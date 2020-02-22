#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {
  srand(time(NULL));
  int i;

  printf("Creating matrices...\n");

  struct matrix* edges = new_matrix(4, 0);
  struct matrix* transform = new_matrix(4, 4);
  ident(transform);

  printf("\nAdding edge...\n");
  add_edge(edges, 4, 2, 7, 1, 9, 5);
  print_matrix(edges);

  printf("\nMultiplying identity matrix by edge matrix...\n");
  matrix_mult(transform, edges);
  printf("Edge matrix:\n");
  print_matrix(edges);

  printf("\nGenerating transform matrix...\n");
  for (i = 0; i < 4; i++) {
    int j;
    for (j = 0; j < 4; j++) {
      transform->m[i][j] = rand() % 10;
    }
  }
  transform->lastcol = 4;
  print_matrix(transform);

  printf("\nMultiplying transformation matrix by edge matrix...\n");
  matrix_mult(transform, edges);
  print_matrix(edges);

  // IMAGE GENERATION CODE BEGINS HERE

  ident(transform);
  edges->lastcol = 0;
  transform->lastcol = 0;

  screen s;
  clear_screen(s);
  color c = {MAX_COLOR, 0, 0};

  add_edge(edges, XRES/2-50, YRES/2-sqrt(7500), 0, XRES/2-50, YRES/2+sqrt(7500), 0);
  add_edge(edges, XRES/2-sqrt(12500), YRES/2+100, 0, XRES/2+sqrt(12500), YRES/2+100, 0);
  add_edge(edges, XRES/2+150, YRES/2-sqrt(17500), 0, XRES/2+150, YRES/2+sqrt(17500), 0);
  add_edge(edges, XRES/2-sqrt(22500), YRES/2-200, 0, XRES/2+sqrt(22500), YRES/2-200, 0);
  add_edge(edges, XRES/2-250, YRES/2-sqrt(27500), 0, XRES/2-250, YRES/2+sqrt(27500), 0);
  add_edge(edges, XRES/2-sqrt(32500), YRES/2+300, 0, XRES/2+sqrt(32500), YRES/2+300, 0);
  add_edge(edges, XRES/2+350, YRES/2-sqrt(37500), 0, XRES/2+350, YRES/2+sqrt(37500), 0);

  // print_matrix(edges);

  ident(transform);
  transform->m[0][0] = cos(M_PI/51);
  transform->m[0][1] = -sin(M_PI/51);
  transform->m[1][0] = sin(M_PI/51);
  transform->m[1][1] = cos(M_PI/51);
  transform->m[0][3] = -XRES/2*cos(M_PI/51)+YRES/2*sin(M_PI/51)+XRES/2;
  transform->m[1][3] = -XRES/2*sin(M_PI/51)+XRES/2*-cos(M_PI/51)+YRES/2;

  int phase = 0;

  while (phase < 6) {
    draw_lines(edges, s, c);
    switch (phase) {
      case 0:
        c.green += 15;
        if (c.green == MAX_COLOR) phase++;
        break;
      case 1:
        c.red -= 15;
        if (!c.red) phase++;
        break;
      case 2:
        c.blue += 15;
        if (c.blue == MAX_COLOR) phase++;
        break;
      case 3:
        c.green -= 15;
        if (!c.green) phase++;
        break;
      case 4:
        c.red += 15;
        if (c.red == MAX_COLOR) phase++;
        break;
      case 5:
        c.blue -= 15;
        if (!c.blue) phase++;
        break;
    }
    matrix_mult(transform, edges);
  }

  save_ppm_ascii(s, "image.ppm");

  return 0;
}
/*
cos  -sin  0  0
sin  cos   0  0
0    0     1  0
0    0     0  1

1    0     0  x
0    1     0  y
0    0     1  0
0    0     0  1

cos  -sin  0  -xcos+ysin
sin  cos   0  -xsin-ycos
0    0     1  0
0    0     0  1

cos  -sin  0  -xcos+ysin+x
sin  cos   0  -xsin-ycos+y
0    0     1  0
0    0     0  1
*/
