#include <inttypes.h>

#define MAX_CONFIG_LN 1000

#define ELECTRONS_PER_ORBITAL 2

#define SUPERSCRIPT_0 "⁰"
#define SUPERSCRIPT_1 "¹"
#define SUPERSCRIPT_2 "²"
#define SUPERSCRIPT_3 "³"
#define SUPERSCRIPT_4 "⁴"
#define SUPERSCRIPT_5 "⁵"
#define SUPERSCRIPT_6 "⁶"
#define SUPERSCRIPT_7 "⁷"
#define SUPERSCRIPT_8 "⁸"
#define SUPERSCRIPT_9 "⁹"

enum SUBLEVEL_types {
  SUBLEVEL_S = 0, SUBLEVEL_P = 1, SUBLEVEL_D = 2, SUBLEVEL_F = 3
};

enum SUBLEVEL_orbitals {
  ORBITALS_SUB_S = 1, ORBITALS_SUB_P = 3, ORBITALS_SUB_D = 5, ORBITALS_SUB_F = 7
};

typedef struct ELECTRON_sublevel {
  unsigned int electrons;
  unsigned int sublevel_type;
  unsigned int max_electrons;
  unsigned int orbitals;
} sublevel;

typedef struct ELECTRON_configuration {
  char config_string[MAX_CONFIG_LN];
  unsigned int highest_energy_level;
  unsigned int valence_electrons;
  int charge;
} electron_config;

extern sublevel sub_1s;
extern sublevel sub_2s;
extern sublevel sub_3s;
extern sublevel sub_4s;
extern sublevel sub_5s;
extern sublevel sub_6s;
extern sublevel sub_7s;

extern sublevel sub_2p;
extern sublevel sub_3p;
extern sublevel sub_4p;
extern sublevel sub_5p;
extern sublevel sub_6p;
extern sublevel sub_7p;

extern sublevel sub_3d;
extern sublevel sub_4d;
extern sublevel sub_5d;
extern sublevel sub_6d;
extern sublevel sub_7d;

extern sublevel sub_4f;
extern sublevel sub_5f;
extern sublevel sub_6f;
extern sublevel sub_7f;

sublevel create_sublevel(unsigned int sub_type);
int initialize_sublevels();

extern electron_config create_electron_config(uint32_t atomic_number);
extern int fill_levels(electron_config *elec, uint32_t atomic_number);
extern int add_to_sublevel(sublevel *sublvl, uint32_t *atomic_number);
extern int reset_sublevels();

extern int find_valence_electrons(electron_config *elec);
extern char get_superscripts(unsigned int num)[3];
extern int configure_electron_string(electron_config *elec);
