// extern is always used for header files

struct rational {
    int numerator;
    int denominator;
}

extern const struct rational PI;

// function declaration
void print_rational(const struct rational *f);