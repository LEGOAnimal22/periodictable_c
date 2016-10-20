// Copyright (c) 2016 LEGOAnimal22

#include "electron.h"
#include "elements.h"

element create_element(unsigned int atomic_number) {
  element_name e_name; e_name = element_names[atomic_number - 1];
  element_symbol e_symbol; e_symbol = element_symbols[atomic_number - 1];
  electron_config e_cnfg = create_electron_config(atomic_number);

  element new_element = {e_name, e_symbol, atomic_number, e_cnfg};

  return new_element;
}
