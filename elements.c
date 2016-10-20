// Copyright (c) 2016 LEGOAnimal22

#include "electron.h"
#include "elements.h"

element create_element(unsigned int atomic_number) {
  electron_config e_cnfg = create_electron_config(atomic_number);

  element new_element = {element_names[atomic_number - 1], element_symbols[atomic_number - 1], atomic_number, e_cnfg};

  return new_element;
}
