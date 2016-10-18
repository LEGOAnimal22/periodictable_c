#include <inttypes.h>
#include <string.h>
#include "electron.h"

// filling order: 1s, 2s, 2p, 3s, 3p, 4s, 3d, 4p, 5s, 4d, 5p, 6s, 4f, 5d, 6p, 7s, 5f, 6d, 7p
sublevel sub_1s, sub_2s, sub_3s, sub_4s, sub_5s, sub_6s, sub_7s;
sublevel sub_2p, sub_3p, sub_4p, sub_5p, sub_6p, sub_7p;
sublevel sub_3d, sub_4d, sub_5d, sub_6d, sub_7d;
sublevel sub_4f, sub_5f, sub_6f, sub_7f;

sublevel create_sublevel(unsigned int sub_type) {
  unsigned int max_elec = 0;
  unsigned int orb;
  switch (sub_type) {
    case 0:
      orb = ORBITALS_SUB_S;
      break;
    case 1:
      orb = ORBITALS_SUB_P;
      break;
    case 2:
      orb = ORBITALS_SUB_D;
      break;
    case 3:
      orb = ORBITALS_SUB_F;
      break;
    default:
      break;
  }
  max_elec = orb * ELECTRONS_PER_ORBITAL;

  sublevel sub = {0, sub_type, max_elec, orb};
  return sub;
}

int initialize_sublevels() {
  sub_1s = create_sublevel(SUBLEVEL_S);
  sub_2s = create_sublevel(SUBLEVEL_S);
  sub_3s = create_sublevel(SUBLEVEL_S);
  sub_4s = create_sublevel(SUBLEVEL_S);
  sub_5s = create_sublevel(SUBLEVEL_S);
  sub_6s = create_sublevel(SUBLEVEL_S);
  sub_7s = create_sublevel(SUBLEVEL_S);

  sub_2p = create_sublevel(SUBLEVEL_P);
  sub_3p = create_sublevel(SUBLEVEL_P);
  sub_4p = create_sublevel(SUBLEVEL_P);
  sub_5p = create_sublevel(SUBLEVEL_P);
  sub_6p = create_sublevel(SUBLEVEL_P);
  sub_7p = create_sublevel(SUBLEVEL_P);

  sub_3d = create_sublevel(SUBLEVEL_D);
  sub_4d = create_sublevel(SUBLEVEL_D);
  sub_5d = create_sublevel(SUBLEVEL_D);
  sub_6d = create_sublevel(SUBLEVEL_D);
  sub_7d = create_sublevel(SUBLEVEL_D);

  sub_4f = create_sublevel(SUBLEVEL_F);
  sub_5f = create_sublevel(SUBLEVEL_F);
  sub_6f = create_sublevel(SUBLEVEL_F);
  sub_7f = create_sublevel(SUBLEVEL_F);

  return 1;
}

// create a new electron_config object using the atomic number of an element
electron_config create_electron_config(uint32_t atomic_number) {
  electron_config new_elec = {"", 0, 0, 0};

  fill_levels(&new_elec, atomic_number);
  find_valence_electrons(&new_elec);
  configure_electron_string(&new_elec);
  reset_sublevels();

  return new_elec;
}

// fill sublevels until atomic_number reaches 0, then find highest energy level
int fill_levels(electron_config *elec, uint32_t atomic_number) {
  unsigned int current_sublevel = 0;
  uint32_t x = atomic_number;

  while (!(x == 0)) {
    switch (current_sublevel) {
      case 0:
        add_to_sublevel(&sub_1s, &x); break;
      case 1:
        add_to_sublevel(&sub_2s, &x); break;
      case 2:
        add_to_sublevel(&sub_2p, &x); break;
      case 3:
        add_to_sublevel(&sub_3s, &x); break;
      case 4:
        add_to_sublevel(&sub_3p, &x); break;
      case 5:
        add_to_sublevel(&sub_4s, &x); break;
      case 6:
        add_to_sublevel(&sub_3d, &x); break;
      case 7:
        add_to_sublevel(&sub_4p, &x); break;
      case 8:
        add_to_sublevel(&sub_5s, &x); break;
      case 9:
        add_to_sublevel(&sub_4d, &x); break;
      case 10:
        add_to_sublevel(&sub_5p, &x); break;
      case 11:
        add_to_sublevel(&sub_6s, &x); break;
      case 12:
        add_to_sublevel(&sub_4f, &x); break;
      case 13:
        add_to_sublevel(&sub_5d, &x); break;
      case 14:
        add_to_sublevel(&sub_6p, &x); break;
      case 15:
        add_to_sublevel(&sub_7s, &x); break;
      case 16:
        add_to_sublevel(&sub_5f, &x); break;
      case 17:
        add_to_sublevel(&sub_6d, &x); break;
      case 18:
        add_to_sublevel(&sub_7p, &x); break;
    }
    current_sublevel++;
  }

  current_sublevel--;

  switch (current_sublevel) {
    case 0:
      elec->highest_energy_level = 1;
    case 1 ... 2:
      elec->highest_energy_level = 2;
    case 3 ... 4:
      elec->highest_energy_level = 3;
    case 5 ... 7:
      elec->highest_energy_level = 4;
    case 8 ... 10:
      elec->highest_energy_level = 5;
    case 11 ... 14:
      elec->highest_energy_level = 6;
    case 15 ... 18:
      elec->highest_energy_level = 7;
  }

  return 1;
}

// add electrons to a given sublevel
// (until electrons = max_electrons or atomic_number = 0)
int add_to_sublevel(sublevel *sublvl, uint32_t *atomic_number) {
  unsigned int i;

  if ((unsigned int)(&atomic_number) >= sublvl->max_electrons) {
    for (i = 0; i < sublvl->max_electrons; i++) {
      sublvl->electrons++;
    }
    *atomic_number -= sublvl->max_electrons;
  }
  else if ((unsigned int)(&atomic_number) < sublvl->max_electrons) {
    for (i = 0; i < (unsigned int)(&atomic_number); i++) {
      sublvl->electrons++;
    }
    *atomic_number = 0;
  }

  return 1;
}

// set electrons in all sublevels to 0
int reset_sublevels() {
  sub_1s.electrons = sub_2s.electrons = sub_3s.electrons = sub_4s.electrons = sub_5s.electrons = sub_6s.electrons = sub_7s.electrons = 0;
  sub_2p.electrons = sub_3p.electrons = sub_4p.electrons = sub_5p.electrons = sub_6p.electrons = sub_7p.electrons = 0;
  sub_3d.electrons = sub_4d.electrons = sub_5d.electrons = sub_6d.electrons = sub_7d.electrons = 0;
  sub_4f.electrons = sub_5f.electrons = sub_6f.electrons = sub_7f.electrons = 0;

  return 1;
}

// configure valence electrons (in s and p sublevels of highest energy level)
// and determine charge from valence electrons
int find_valence_electrons(electron_config *elec) {
  switch (elec->highest_energy_level) {
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
  }

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

// return a superscript for a given number (range: 1 - 14)
char * get_superscripts(unsigned int num) {
  char out[3] = "^";

  if (num < 10) {
    strcat(out, " ");
    switch (num) {
      case 1:
        strcat(out, SUPERSCRIPT_1); break;
      case 2:
        strcat(out, SUPERSCRIPT_2); break;
      case 3:
        strcat(out, SUPERSCRIPT_3); break;
      case 4:
        strcat(out, SUPERSCRIPT_4); break;
      case 5:
        strcat(out, SUPERSCRIPT_5); break;
      case 6:
        strcat(out, SUPERSCRIPT_6); break;
      case 7:
        strcat(out, SUPERSCRIPT_7); break;
      case 8:
        strcat(out, SUPERSCRIPT_8); break;
      case 9:
        strcat(out, SUPERSCRIPT_9); break;
    }
  }
  else {
    strcat(out, SUPERSCRIPT_1);
    switch (num - 10) {
      case 0:
        strcat(out, SUPERSCRIPT_0); break;
      case 1:
        strcat(out, SUPERSCRIPT_1); break;
      case 2:
        strcat(out, SUPERSCRIPT_2); break;
      case 3:
        strcat(out, SUPERSCRIPT_3); break;
      case 4:
        strcat(out, SUPERSCRIPT_4); break;
    }
  }

  return (char *)out;
}

// write the amount of electrons in the used sublevels as a string
int configure_electron_string(electron_config *elec) {
  if (sub_1s.electrons != 0) {
    strcat(elec->config_string, "(1s");
    strcat(elec->config_string, get_superscripts(sub_1s.electrons));
    strcat(elec->config_string, ")");
  }
  if (sub_2s.electrons != 0) {
    strcat(elec->config_string, "(2s");
    strcat(elec->config_string, get_superscripts(sub_2s.electrons));
    strcat(elec->config_string, ")");
  }
  if (sub_2p.electrons != 0) {
    strcat(elec->config_string, "(2p");
    strcat(elec->config_string,  get_superscripts(sub_2p.electrons));
    strcat(elec->config_string,  ")");
  }
  if (sub_3s.electrons != 0) {
    strcat(elec->config_string, "(3s");
    strcat(elec->config_string, get_superscripts(sub_3s.electrons));
    strcat(elec->config_string, ")");
  }
  if (sub_3p.electrons != 0) {
    strcat(elec->config_string, "(3p");
    strcat(elec->config_string, get_superscripts(sub_3p.electrons));
    strcat(elec->config_string, ")");
  }
  if (sub_4s.electrons != 0) {
    strcat(elec->config_string, "(4s");
    strcat(elec->config_string, get_superscripts(sub_4s.electrons));
    strcat(elec->config_string, ")");
  }
  if (sub_3d.electrons != 0) {
    strcat(elec->config_string, "(3d");
    strcat(elec->config_string, get_superscripts(sub_3d.electrons));
    strcat(elec->config_string, ")");
  }
  if (sub_4p.electrons != 0) {
    strcat(elec->config_string, "(4p");
    strcat(elec->config_string, get_superscripts(sub_4p.electrons));
    strcat(elec->config_string, ")");
  }
  if (sub_5s.electrons != 0) {
    strcat(elec->config_string, "(5s");
    strcat(elec->config_string, get_superscripts(sub_5s.electrons));
    strcat(elec->config_string, ")");
  }
  if (sub_4d.electrons != 0) {
    strcat(elec->config_string, "(4d");
    strcat(elec->config_string, get_superscripts(sub_4d.electrons));
    strcat(elec->config_string, ")");
  }
  if (sub_5p.electrons != 0) {
    strcat(elec->config_string, "(5p");
    strcat(elec->config_string, get_superscripts(sub_5p.electrons));
    strcat(elec->config_string, ")");
  }
  if (sub_6s.electrons != 0) {
    strcat(elec->config_string, "(6s");
    strcat(elec->config_string, get_superscripts(sub_6s.electrons));
    strcat(elec->config_string, ")");
  }
  if (sub_4f.electrons != 0) {
    strcat(elec->config_string, "(4f");
    strcat(elec->config_string, get_superscripts(sub_4f.electrons));
    strcat(elec->config_string, ")");
  }
  if (sub_5d.electrons != 0) {
    strcat(elec->config_string, "(5d");
    strcat(elec->config_string, get_superscripts(sub_5d.electrons));
    strcat(elec->config_string, ")");
  }
  if (sub_6p.electrons != 0) {
    strcat(elec->config_string, "(6p");
    strcat(elec->config_string, get_superscripts(sub_6p.electrons));
    strcat(elec->config_string, ")");
  }
  if (sub_7s.electrons != 0) {
    strcat(elec->config_string, "(7s");
    strcat(elec->config_string, get_superscripts(sub_7s.electrons));
    strcat(elec->config_string, ")");
  }
  if (sub_5f.electrons != 0) {
    strcat(elec->config_string, "(5f");
    strcat(elec->config_string, get_superscripts(sub_5f.electrons));
    strcat(elec->config_string, ")");
  }
  if (sub_6d.electrons != 0) {
    strcat(elec->config_string, "(6d");
    strcat(elec->config_string, get_superscripts(sub_6d.electrons));
    strcat(elec->config_string, ")");
  }
  if (sub_7p.electrons != 0) {
    strcat(elec->config_string, "(7p");
    strcat(elec->config_string, get_superscripts(sub_7p.electrons));
    strcat(elec->config_string, ")");
  }

  return 1;
}
