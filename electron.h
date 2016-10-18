#define MAX_CONFIG_LN 1000

typedef struct {
  unsigned int atomic_number, highest_energy_level, valence_electrons;
  int charge;
  char config_string[MAX_CONFIG_LN];
} electron_config;

extern electron_config create_electron_config(unsigned int atomic_number);
extern unsigned int find_highest_energy_level(unsigned int atomic_number);
extern int add_to_sublevel(unsigned int level_max, unsigned int *atomic_number);
extern int find_valence_electrons(electron_config *elec);
extern int configure_electron_string(electron_config *elec);
