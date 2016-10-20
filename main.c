// Copyright (c) 2016 LEGOAnimal22

#include <stdio.h>
#include <inttypes.h>
#include "electron.h"
#include "elements.h"

int main() {
  printf("Periodic Table by LEGOAnimal22\n");

  electron_config carbon = create_electron_config(CARBON);
  printf("%d,\t%d,\t%d,\t%d\n", carbon.atomic_number, carbon.highest_energy_level, carbon.valence_electrons, carbon.charge);

  return 1;
}
