// Copyright (c) 2016 LEGOAnimal22

#ifndef PTABLE_ELEMENT_H
#define PTABLE_ELEMENT_H

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
  NEON,
  SODIUM,
  MAGNESIUM,
  ALUMINUM,
  SILICON,
  PHOSPHORUS,
  SULFUR,
  CHLORINE,
  ARGON,
  POTASSIUM,
  CALCIUM,
  SCANDIUM,
  TITANIUM,
  VANADIUM,
  CHROMIUM,
  MANGANESE,
  IRON,
  COBALT,
  NICKEL,
  COPPER,
  ZINC,
  GALLIUM,
  GERMANIUM,
  ARSENIC,
  SELENIUM,
  BROMINE,
  KRYPTON,
  RUBIDIUM,
  STRONTIUM,
  YTTRIUM,
  ZIRCONIUM,
  NIOBIUM,
  MOLYBDENUM,
  TECHNETIUM,
  RUTHENIUM,
  RHODIUM,
  PALLADIUM,
  SILVER,
  CADMIUM,
  INDIUM,
  TIN,
  ANTIMONY,
  TELLURIUM,
  IODINE,
  XENON,
  CAESIUM,
  BARIUM,
  LANTHANUM,
  CERIUM,
  PRASEODYMIUM,
  NEODYMIUM,
  PROMETHIUM,
  SAMARIUM,
  EUROPIUM,
  GALODIUM,
  TERBIUM,
  DYSPROSIUM,
  HOLMIUM,
  ERBIUM,
  THULIUM,
  YTTERBIUM,
  LUTETIUM,
  HAFNIUM,
  TANTALUM,
  TUNGSTEN,
  RHENIUM,
  OSMIUM,
  IRIDIUM,
  PLATINUM,
  GOLD,
  MERCURY,
  THALLIUM,
  LEAD,
  BISMUTH,
  POLONIUM,
  ASTATINE,
  RADON,
  FRANCIUM,
  RADIUM,
  ACTINIUM,
  THORIUM,
  PROTACTINIUM,
  URANIUM,
  NEPTUNIUM,
  PLUTONIUM,
  AMERICIUM,
  CURIUM,
  BERKELIUM,
  CALIFORNIUM,
  EINSTEINIUM,
  FERMIUM,
  MENDELEVIUM,
  NOBELIUM,
  LAWERENCIUM,
  RUTHERFORIUM,
  DUBNIUM,
  SEABORGIUM,
  BOHRIUM,
  HASSIUM,
  MEITNERIUM,
  DARMSTADTIUM,
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
element_symbol element_symbols[10] = {
  "H",
  "He",
  "Li",
  "Be",
  "B",
  "C",
  "N",
  "O",
  "F",
  "Ne"
};

#endif
