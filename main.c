#include <stdio.h>
#include <inttypes.h>
#include "electron.h"

int main() {
  printf("Periodic Table\n");

  electron_config element = create_electron_config(27);
  printf("%d, %d, %d, %d\n", element.atomic_number, element.highest_energy_level, element.valence_electrons, element.charge);
  printf("%d\n", (((27 - 18) > 2) ? (((27 - 30) > 0) ? (2 + (27 - 30)) : 2) : 0));

  return 1;
}
