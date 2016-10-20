// Copyright (c) 2016 LEGOAnimal22

#include <stdio.h>
#include <inttypes.h>
#include "electron.h"

int main() {
  printf("Periodic Table by LEGOAnimal22\n");

  electron_config carbon = create_electron_config(6);
  printf("%d, %d, %d, %d\n", carbon.atomic_number, carbon.highest_energy_level, carbon.valence_electrons, carbon.charge);

  electron_config gold = create_electron_config(79);
  printf("%d, %d, %d, %d\n", gold.atomic_number, gold.highest_energy_level, gold.valence_electrons, gold.charge);

  electron_config radon = create_electron_config(86);
  printf("%d, %d, %d, %d\n", radon.atomic_number, radon.highest_energy_level, radon.valence_electrons, radon.charge);

  // (((atomic_number - 54) > 2) ? 2 : (atomic_number - 54)) + ((atomic_number > 80) ? (atomic_number - 80) : 0)
  unsigned int x = 86;
  printf("%d\n", (((x - 54) > 2) ? 2 : (x - 54)));
  printf("%d\n", ((x > 80) ? (x - 80) : 0));
  printf("%d\n", (((x - 54) > 2) ? 2 : (x - 54)) + ((x > 80) ? (x - 80) : 0));

  return 1;
}
