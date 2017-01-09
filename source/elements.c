// Copyright (c) 2016 LEGOAnimal22

#include <string.h>

#include <electron.h>
#include <elements.h>

element_symbol element_symbols[118] = {
  "H",
  "He",
  "Li",
  "Be",
  "B",
  "C",
  "N",
  "O",
  "F",

  "Ne", // 10
  "Na",
  "Mg",
  "Al",
  "Si",
  "P",
  "S",
  "Cl",
  "Ar",
  "K",

  "Ca", // 20
  "Sc",
  "Ti",
  "V",
  "Cr",
  "Mn",
  "Fe",
  "Co",
  "Ni",
  "Cu",

  "Zn", // 30
  "Ga",
  "Ge",
  "As",
  "Se",
  "Br",
  "Kr",
  "Rb",
  "Sr",
  "Y",

  "Zr", // 40
  "Nb",
  "Mo",
  "Tc",
  "Ru",
  "Rh",
  "Pd",
  "Ag",
  "Cd",
  "In",

  "Sn", // 50
  "Sb",
  "Te",
  "I",
  "Xe",
  "Cs",
  "Ba",
  "La",
  "Ce",
  "Pr",

  "Nd", // 60
  "Pm",
  "Sm",
  "Eu",
  "Gd",
  "Tb",
  "Dy",
  "Ho",
  "Er",
  "Tm",

  "Yb", // 70
  "Lu",
  "Hf",
  "Ta",
  "W",
  "Re",
  "Os",
  "Ir",
  "Pt",
  "Au",

  "Hg", // 80
  "Tl",
  "Pb",
  "Bi",
  "Po",
  "At",
  "Rn",
  "Fr",
  "Ra",
  "Ac",

  "Th", // 90
  "Pa",
  "U",
  "Np",
  "Pu",
  "Am",
  "Cm",
  "Bk",
  "Cf",
  "Es",

  "Fm", // 100
  "Md",
  "No",
  "Lr",
  "Rf",
  "Db",
  "Sg",
  "Bh",
  "Hs",
  "Mt",

  "Ds", // 110
  "Rg",
  "Cn",
  "Uut",
  "Fl",
  "Uup",
  "Lv",
  "Uus",
  "Uuo"
};

int search_element_symbols(element_symbol search_for) {
  int i;
  for (i = 0; i < 118; i++) {
    if (strcmp(element_symbols[i], search_for) == 0) {
      return i + 1;
    }
  }
  return -1;
}

element_name element_names[118] = {
  "hydrogen",
  "helium",
  "lithium",
  "beryllium",
  "boron",
  "carbon",
  "nitrogen",
  "oxygen",
  "fluorine",

  "neon",               // 10
  "sodium",
  "magnesium",
  "aluminum",
  "silicon",
  "phosphorus",
  "sulfur",
  "chlorine",
  "argon",
  "potassium",

  "calcium",           // 20
  "scandium",
  "titanium",
  "vanadium",
  "chromium",
  "manganese",
  "iron",
  "cobalt",
  "nickel",
  "copper",

  "zinc",             // 30
  "gallium",
  "germanium",
  "arsenic",
  "selenium",
  "bromine",
  "krypton",
  "rubidium",
  "strontium",
  "yttrium",

  "zirconium",        // 40
  "niobium",
  "molybdenum",
  "technetium",
  "ruthenium",
  "rhodium",
  "palladium",
  "silver",
  "cadmium",
  "indium",

  "tin",              // 50
  "antimony",
  "tellurium",
  "iodine",
  "xenon",
  "cesium",
  "barium",
  "lanthanum",
  "cerium",
  "praseodymium",

  "neodymium",        // 60
  "promethium",
  "samarium",
  "europium",
  "gadolinium",
  "terbium",
  "dysprosium",
  "holmium",
  "erbium",
  "thulium",

  "ytterbium",        // 70
  "lutetium",
  "hafnium",
  "tantalum",
  "tungsten",
  "rhenium",
  "osmium",
  "iridium",
  "platinum",
  "gold",

  "mercury",          // 80
  "thallium",
  "lead",
  "bismuth",
  "polonium",
  "astatine",
  "radon",
  "francium",
  "radium",
  "actinium",

  "thorium",          // 90
  "protactinium",
  "uranium",
  "neptunium",
  "plutonium",
  "americium",
  "curium",
  "berkelium",
  "californium",
  "einstienium",

  "fermium",          // 100
  "mendelevium",
  "nobelium",
  "lawrencium",
  "rutherfordium",
  "dubnium",
  "seaborgium",
  "bohrium",
  "hassium",
  "meitnerium",

  "darmstadtium",     // 110
  "roentgenium",
  "copernicium",
  "ununtrium",
  "flerovium",
  "ununpentium",
  "livermorium",
  "ununseptium",
  "ununoctium"
};

int search_element_names(element_name search_for) {
  int i;
  for (i = 0; i < 118; i++) {
    if (strcmp(element_names[i], search_for) == 0) {
      return i + 1;
    }
  }
  return -1;
}

element create_element(unsigned int atomic_number) {
  electron_config e_cnfg = create_electron_config(atomic_number);

  element new_element = {"", "", atomic_number, e_cnfg};
  strcat(new_element.name, element_names[atomic_number - 1]);
  strcat(new_element.symbol, element_symbols[atomic_number - 1]);

  return new_element;
}
