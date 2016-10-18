#include <stdio.h>
#include <inttypes.h>
#include "electron.h"

int main() {
  printf("Periodic Table\n");

  electron_config element = create_electron_config(27);
  printf("%d\n", element.highest_energy_level);

  return 1;
}
