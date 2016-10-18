#include <stdio.h>
#include <inttypes.h>
#include "electron.h"

int main() {
  printf("Periodic Table\n");
  initialize_sublevels();

  electron_config helium = create_electron_config(2);
  printf("%d\n", helium.valence_electrons);
  printf("%d %d\n", sub_1s.electrons, sub_1s.max_electrons);

  return 1;
}
