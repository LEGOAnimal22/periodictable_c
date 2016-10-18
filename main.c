#include <stdio.h>
#include <inttypes.h>
#include "electron.h"

int main() {
  printf("Periodic Table\n");
  initialize_sublevels();

  electron_config helium = create_electron_config(2);
  printf("%d\n", helium.valence_electrons);
  printf("%d %d\n", sub_1s.electrons, sub_1s.max_electrons);

  uint32_t x = 4;
  add_to_sublevel(&sub_1s, &x);
  printf("%d %d\n", sub_1s.electrons, x);

  return 1;
}
