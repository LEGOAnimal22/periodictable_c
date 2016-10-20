// Copyright (c) 2016 LEGOAnimal22

#ifndef PTABLE_ELEMENTS_H
#define PTABLE_ELEMENTS_H

#include "electron.h"

enum {
  HYDROGEN = 1,
  HELIUM,
  LITHIUM,
  BERYLLIUM,
  BORON,
  CARBON,
  NITROGEN,
  OXYGEN,
  FLUORINE,

  NEON,               // 10
  SODIUM,
  MAGNESIUM,
  ALUMINUM,
  SILICON,
  PHOSPHORUS,
  SULFUR,
  CHLORINE,
  ARGON,
  POTASSIUM,

  CALCIUM,            // 20
  SCANDIUM,
  TITANIUM,
  VANADIUM,
  CHROMIUM,
  MANGANESE,
  IRON,
  COBALT,
  NICKEL,
  COPPER,

  ZINC,               // 30
  GALLIUM,
  GERMANIUM,
  ARSENIC,
  SELENIUM,
  BROMINE,
  KRYPTON,
  RUBIDIUM,
  STRONTIUM,
  YTTRIUM,

  ZIRCONIUM,          // 40
  NIOBIUM,
  MOLYBDENUM,
  TECHNETIUM,
  RUTHENIUM,
  RHODIUM,
  PALLADIUM,
  SILVER,
  CADMIUM,
  INDIUM,

  TIN,                // 50
  ANTIMONY,
  TELLURIUM,
  IODINE,
  XENON,
  CAESIUM,
  BARIUM,
  LANTHANUM,
  CERIUM,
  PRASEODYMIUM,

  NEODYMIUM,         // 60
  PROMETHIUM,
  SAMARIUM,
  EUROPIUM,
  GALODIUM,
  TERBIUM,
  DYSPROSIUM,
  HOLMIUM,
  ERBIUM,
  THULIUM,

  YTTERBIUM,         // 70
  LUTETIUM,
  HAFNIUM,
  TANTALUM,
  TUNGSTEN,
  RHENIUM,
  OSMIUM,
  IRIDIUM,
  PLATINUM,
  GOLD,

  MERCURY,           // 80
  THALLIUM,
  LEAD,
  BISMUTH,
  POLONIUM,
  ASTATINE,
  RADON,
  FRANCIUM,
  RADIUM,
  ACTINIUM,

  THORIUM,           // 90
  PROTACTINIUM,
  URANIUM,
  NEPTUNIUM,
  PLUTONIUM,
  AMERICIUM,
  CURIUM,
  BERKELIUM,
  CALIFORNIUM,
  EINSTEINIUM,

  FERMIUM,          // 100
  MENDELEVIUM,
  NOBELIUM,
  LAWERENCIUM,
  RUTHERFORIUM,
  DUBNIUM,
  SEABORGIUM,
  BOHRIUM,
  HASSIUM,
  MEITNERIUM,

  DARMSTADTIUM,     // 110
  ROENTGENIUM,
  COPERNICIUM,
  UNUNTRIUM,
  FLEROVIUM,
  UNUNPENTIUM,
  LIVERMORIUM,
  UNUNSEPTIUM,
  UNUNOCTIUM
};

typedef char element_symbol[3];
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

typedef char element_name[20];
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

typedef struct {
  element_name name;
  element_symbol symbol;
  unsigned int atomic_number;
  electron_config configuration;
} element;

extern element create_element(unsigned int atomic_number);

#endif
