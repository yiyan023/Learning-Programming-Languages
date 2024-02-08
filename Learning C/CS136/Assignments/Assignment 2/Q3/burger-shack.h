// You should complete this interface

struct burger_shack {
  int pickles;
  int buns;
  int cheese;
  int patties;
};

// in your burger_shack, you should define this constant
extern const struct burger_shack empty_shack;

// you should complete this interface

void add_pickles(struct burger_shack *shack, int jars);

void add_buns(struct burger_shack *shack, int crates);

void add_cheese(struct burger_shack *shack, int blocks);

void add_patties(struct burger_shack *shack, int boxes);

void order(struct burger_shack *shack, int burgers);

void check_inventory(const struct burger_shack *shack);
