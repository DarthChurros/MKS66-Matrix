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

}
