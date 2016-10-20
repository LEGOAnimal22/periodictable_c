// Copyright (c) 2016 LEGOAnimal22

#include <string.h>
#include "electron.h"
#include "elements.h"

element create_element(unsigned int atomic_number) {
  electron_config e_cnfg = create_electron_config(atomic_number);

  element new_element = {"", "", atomic_number, e_cnfg};
  strcat(new_element.name, element_names[atomic_number - 1]);
  strcat(new_element.symbol, element_symbols[atomic_number - 1]);

  return new_element;
}
