// Copyright (c) 2016 LEGOAnimal22

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

#include <electron.h>
#include <elements.h>

void printHelp() {
	printf("Acceptable uses:\n");
	printf("\t-a [atomic number]\tPrint information for the element with the provided atomic number.\n");
	printf("\t-n [name]\tPrint information for the element with the provided name(lower-case).\n");
	printf("\t-s [symbol]\tPrint information for the element with the provided symbol(first letter upper-case, remaining letters lower-case).\n");
}

int main(int argc, char *argv[]) {
  printf("Periodic Table by LEGOAnimal22\n");

  if (argc == 1) {
	  printHelp();
	  return 0;
  } else if (argc == 3) {
	  if (strcmp(argv[1], "-a") == 0) {

		  int atm_num = atoi(argv[2]);
			element e_atmnum = create_element(atm_num);
			printf("%s (%s): #%d; config: %d (highest energy level), %d valence electrons, charge of %d\n", e_atmnum.name, e_atmnum.symbol, e_atmnum.atomic_number, e_atmnum.configuration.highest_energy_level, e_atmnum.configuration.valence_electrons, e_atmnum.configuration.charge);
			return 1;

	  } else if (strcmp(argv[1], "-n") == 0) {

		  int atm_num = search_element_names(argv[2]);
			if (atm_num != -1) {
				element e_atmnum = create_element(atm_num);
				printf("%s (%s): #%d; config: %d (highest energy level), %d valence electrons, charge of %d\n", e_atmnum.name, e_atmnum.symbol, e_atmnum.atomic_number, e_atmnum.configuration.highest_energy_level, e_atmnum.configuration.valence_electrons, e_atmnum.configuration.charge);
				return 1;
			} else {
				printf("Invalid element name!\n");
				printHelp();
				return 0;
			}

	  } else if (strcmp(argv[1], "-s") == 0) {

		  int atm_num = search_element_symbols(argv[2]);
			if (atm_num != -1) {
				element e_atmnum = create_element(atm_num);
				printf("%s (%s): #%d; config: %d (highest energy level), %d valence electrons, charge of %d\n", e_atmnum.name, e_atmnum.symbol, e_atmnum.atomic_number, e_atmnum.configuration.highest_energy_level, e_atmnum.configuration.valence_electrons, e_atmnum.configuration.charge);
				return 1;
			} else {
				printf("Invalid element symbol!\n");
				printHelp();
				return 0;
			}

	  } else {
		  printHelp();
		  return 0;
	  }
  } else {
	  printf("Incorrect number of arguments!\n");
	  printHelp();
	  return 0;
  }

  /*

  electron_config carbon = create_electron_config(CARBON);
  printf("%d,\t%d,\t%d,\t%d\n", carbon.atomic_number, carbon.highest_energy_level, carbon.valence_electrons, carbon.charge);

  element e_tungsten = create_element(TUNGSTEN);
  printf("%s (%s): #%d; config: %d (highest energy level), %d valence electrons, charge of %d\n", e_tungsten.name, e_tungsten.symbol, e_tungsten.atomic_number, e_tungsten.configuration.highest_energy_level, e_tungsten.configuration.valence_electrons, e_tungsten.configuration.charge);

  */

  return 1;
}
