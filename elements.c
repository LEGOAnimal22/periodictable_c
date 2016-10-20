// Copyright (c) 2016 LEGOAnimal22

#include "electron.h"
#include "elements.h"

element create_element(unsigned int atomic_number) {
  char e_name[20] = element_names[atomic_number - 1];
  char e_symbol[3] = element_symbols[atomic_number - 1];
  electron_config e_cnfg = create_electron_config(atomic_number);

  element new_element = {e_name, e_symbol, atomic_number, e_cnfg};

  return new_element;
}
