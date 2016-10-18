#include <stdio.h>
#include <inttypes.h>
#include "electron.h"

int main() {
  printf("Periodic Table\n");
  initialize_sublevels();

  electron_config element = create_electron_config(24);
  printf("%d\n", element.charge);

  return 1;
}
