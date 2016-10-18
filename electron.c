#include <string.h>
#include "electron.h"

// filling order: 1s, 2s, 2p, 3s, 3p, 4s, 3d, 4p, 5s, 4d, 5p, 6s, 4f, 5d, 6p, 7s, 5f, 6d, 7p
//                 2   2   6   2   6   2  10   6   2  10   6   2  14  10   6   2  14  10   6
static unsigned int sublevel_max_electrons[19] = {2, 2, 6, 2, 6, 2, 10, 6, 2, 10, 6, 2, 14, 10, 6, 2, 14, 10, 6};

// create a new electron_config object using the atomic number of an element
electron_config create_electron_config(unsigned int atomic_number) {
  electron_config new_elec = {atomic_number, find_highest_energy_level(atomic_number), 0, 0, ""};

  // find_valence_electrons(&new_elec);
  // configure_electron_string(&new_elec);

  return new_elec;
}

// fill sublevels until atomic_number reaches 0, then find highest energy level
unsigned int find_highest_energy_level(unsigned int atomic_number) {
  unsigned int current_sublevel = 0, x = atomic_number;

  while (!(x == 0)) {
    add_to_sublevel(sublevel_max_electrons[current_sublevel++], &x);
  }

  current_sublevel--;

  switch (current_sublevel) {
    case 0:
      return 1;
    case 1 ... 2:
      return 2;
    case 3 ... 4:
      return 3;
    case 5 ... 7:
      return 4;
    case 8 ... 10:
      return 5;
    case 11 ... 14:
      return 6;
    case 15 ... 18:
      return 7;
  }
}

// add electrons to a given sublevel
// (until electrons = max_electrons or atomic_number = 0)
int add_to_sublevel(unsigned int level_max, unsigned int *atomic_number) {
  unsigned int i, atm = *atomic_number;

  if (atm >= level_max) { atm -= level_max; }
  else if (atm < level_max) { atm = 0; }

  *atomic_number = atm;

  return 1;
}

// configure valence electrons (in s and p sublevels of highest energy level)
// and determine charge from valence electrons
int find_valence_electrons(electron_config *elec) {
  /* switch (elec->highest_energy_level) {
    case 1:
      elec->valence_electrons = sub_1s.electrons;
    case 2:
      elec->valence_electrons = sub_2s.electrons + sub_2p.electrons;
    case 3:
      elec->valence_electrons = sub_3s.electrons + sub_3p.electrons;
    case 4:
      elec->valence_electrons = sub_4s.electrons + sub_4p.electrons;
    case 5:
      elec->valence_electrons = sub_5s.electrons + sub_5p.electrons;
    case 6:
      elec->valence_electrons = sub_6s.electrons + sub_6p.electrons;
    case 7:
      elec->valence_electrons = sub_7s.electrons + sub_7p.electrons;
  } */

  int diff = 8 - elec->valence_electrons;
  if (diff == 0) {
    elec->charge = 0;
  }
  else if (diff < 4) {
    elec->charge = (int)(-1 * diff);
  }
  else if (diff == 4) {
    elec->charge = 4;
  }
  else if (diff > 4) {
    elec->charge = elec->valence_electrons;
  }

  return 1;
}

// write the amount of electrons in the used sublevels as a string
int configure_electron_string(electron_config *elec) {
  return 1;
}
