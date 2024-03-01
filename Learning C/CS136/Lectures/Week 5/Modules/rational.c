#include <rational.h>

const struct rational PI = {22, 7}

// neither this or the header can have int main()
void print_rational(const struct rational *f) {
    printf("%d\%d", f->numerator, f->denominator);
}