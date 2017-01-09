// Copyright (c) 2016 LEGOAnimal22

#ifndef PTABLE_ELEMENTS_H
#define PTABLE_ELEMENTS_H

#include <electron.h>

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
typedef char element_name[20];

typedef struct {
  element_name name;
  element_symbol symbol;
  unsigned int atomic_number;
  electron_config configuration;
} element;

extern int search_element_symbols(element_symbol search_for);
extern int search_element_names(element_name search_for);
extern element create_element(unsigned int atomic_number);

#endif
