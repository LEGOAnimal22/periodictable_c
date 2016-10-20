// Copyright (c) 2016 LEGOAnimal22

#include <stdio.h>
#include <inttypes.h>
#include "electron.h"
#include "elements.h"

int main() {
  printf("Periodic Table by LEGOAnimal22\n");

  electron_config carbon = create_electron_config(CARBON);
  printf("%d,\t%d,\t%d,\t%d\n", carbon.atomic_number, carbon.highest_energy_level, carbon.valence_electrons, carbon.charge);

  element e_tungsten = create_element(TUNGSTEN);
  printf("%s (%s): #%d; config: %d (highest energy level), %d valence electrons, charge of %d\n", e_tungsten.name, e_tungsten.symbol, e_tungsten.atomic_number, e_tungsten.configuration.highest_energy_level, e_tungsten.configuration.valence_electrons, e_tungsten.charge);
  return 1;
}
