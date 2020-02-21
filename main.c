#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {
  printf("Creating matrix...\n");

  struct matrix* edges = new_matrix(4, 4);

  print_matrix(edges);

  printf("\nConverting to identity matrix...\n");
  ident(edges);
  print_matrix(edges);

  printf("\nAdding point...\n");
  add_point(edges, 4, 2, 7);
  print_matrix(edges);

}
