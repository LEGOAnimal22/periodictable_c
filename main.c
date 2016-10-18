#include <stdio.h>
#include <inttypes.h>
#include "electron.h"

int main() {
  printf("Periodic Table");
  initialize_sublevels();

  electron_config helium = create_electron_config(2);
  printf("%d\n", helium.valence_electrons);
  printf("%d\n", sub_1s.electrons);

  return 1;
}
