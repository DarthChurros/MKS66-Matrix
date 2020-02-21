#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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


}
