#include <stdio.h>
#include <inttypes.h>
#include "electron.h"

int main() {
  initialize_sublevels();

  electron_config helium = create_electron_config(2);
  printf("%d\n", helium.valence_electrons);

  return 1;
}
