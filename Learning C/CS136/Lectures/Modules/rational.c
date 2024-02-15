#include <rational.h>

const struct rational PI = {22, 7}

void print_rational(const struct rational *f) {
    printf("%d\%d", f->numerator, f->denominator);
}