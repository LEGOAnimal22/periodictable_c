#include <stdio.h>
#include <inttypes.h>
#include "electron.h"

int main() {
  printf("Periodic Table\n");

  electron_config element = create_electron_config(27);
  printf("%d, %d, %d, %d\n", element.atomic_number, element.highest_energy_level, element.valence_electrons, element.charge);

  unsigned int atomic_number = 27;
  unsigned int valence = (((atomic_number - 18) > 2) ? (2 + (((atomic_number - 30) > 0) ? (atomic_number - 30) : 0)) : (atomic_number - 18));
  printf("%d\n", valence);
  
  return 1;
}
