// Copyright (c) 2016 LEGOAnimal22

#include <string.h>

#include <electron.h>

// filling order: 1s, 2s, 2p, 3s, 3p, 4s, 3d, 4p, 5s, 4d, 5p, 6s, 4f, 5d, 6p, 7s, 5f, 6d, 7p
//                 2   2   6   2   6   2  10   6   2  10   6   2  14  10   6   2  14  10   6
static unsigned int sublevel_max_electrons[19] = {2, 2, 6, 2, 6, 2, 10, 6, 2, 10, 6, 2, 14, 10, 6, 2, 14, 10, 6};

// create a new electron_config object using the atomic number of an element
electron_config create_electron_config(unsigned int atomic_number) {
  unsigned int he_lev = find_highest_energy_level(atomic_number);
  unsigned int val_elec = find_valence_electrons(atomic_number, he_lev);
  int chrg = find_config_charge(val_elec);

  electron_config new_elec = {atomic_number, he_lev, val_elec, chrg};

  return new_elec;
}

// fill sublevels until atomic_number reaches 0, then find highest energy level
unsigned int find_highest_energy_level(unsigned int atomic_number) {
  unsigned int current_sublevel = 0, x = atomic_number, ret = 0;

  while (!(x == 0)) {
    add_to_sublevel(sublevel_max_electrons[current_sublevel++], &x);
  }

  current_sublevel--;

  switch (current_sublevel) {
    case 0:
      ret = 1;
      break;
    case 1 ... 2:
      ret = 2;
      break;
    case 3 ... 4:
      ret = 3;
      break;
    case 5 ... 7:
      ret = 4;
      break;
    case 8 ... 10:
      ret = 5;
      break;
    case 11 ... 14:
      ret = 6;
      break;
    case 15 ... 18:
      ret = 7;
      break;
  }
  return ret;
}

// add electrons to a given sublevel
// (until electrons = max_electrons or atomic_number = 0)
int add_to_sublevel(unsigned int level_max, unsigned int *atomic_number) {
  unsigned int i, atm = *atomic_number;

  if (atm >= level_max) { atm -= level_max; }
  else { atm = 0; } // or "if (atm < level_max)"

  *atomic_number = atm;

  return 1;
}

// configure valence electrons (in s and p sublevels of highest energy level)
// and determine charge from valence electrons
unsigned int find_valence_electrons(unsigned int atomic_number, unsigned int highest_energy_level) {
  unsigned int ret = 0;
  switch (highest_energy_level) {
    case 1:
      ret = atomic_number;
      break;
    case 2:
      ret = (atomic_number - 2);
      break;
    case 3:
      ret = (atomic_number - 10);
      break;
    case 4:
      ret = (((atomic_number - 18) > 2) ? 2 : (atomic_number - 18)) + ((atomic_number > 30) ? (atomic_number - 30) : 0);
      break;
    case 5:
      ret = (((atomic_number - 36) > 2) ? 2 : (atomic_number - 36)) + ((atomic_number > 48) ? (atomic_number - 48) : 0);
      break;
    case 6:
      ret = (((atomic_number - 54) > 2) ? 2 : (atomic_number - 54)) + ((atomic_number > 80) ? (atomic_number - 80) : 0);
      break;
    case 7:
      ret = (((atomic_number - 86) > 2) ? 2 : (atomic_number - 86)) + ((atomic_number > 112) ? (atomic_number - 112) : 0);
      break;
  }
  return ret;
}

int find_config_charge(unsigned int valence) {
  int diff = 8 - valence, ret = 0;
  if (diff == 0) {
    ret = 0;
  }
  else if (diff < 4) {
    ret = (int)(-1 * diff);
  }
  else if (diff == 4) {
    ret = 4;
  }
  else if (diff > 4) {
    ret = (int)valence;
  }
  return ret;
}
