#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#include"mpfr.h"
#include<pthread.h>

unsigned long PRECISION = 100;
mpfr_t PI, one;
mpfr_t t1, t2, t3, t4, t5, t6, t7;

time_t t_start, t_end;

int main (int argc, char **argv) {

    PRECISION *= 3.35;
    mpfr_set_default_prec(PRECISION);
    mpfr_inits(t1, t2, t3, t4, t5, t6, t7, PI, one, NULL);
    mpfr_set_ui(PI, 0, MPFR_RNDN);
    mpfr_set_ui(one, 1, MPFR_RNDN);
    return (0);
}

void calc(mpfr_t* t, char* x_str, int op, int coeff) {
    mpfr_t x;
    mpfr_set_default_prec(PRECISION);
    mpfr_init_set_str(x, x_str, 10, MPFR_RNDN);

    mpfr_atan2(*t, one, x, MPFR_RNDN);
    mpfr_mul_ui(*t, *t, coeff, MPFR_RNDN);

    if (op == 1) {
      mpfr_add(PI, PI, *t, MPFR_RNDN);
    } else {
      mpfr_sub(PI, PI, *t, MPFR_RNDN);
    }

    mpfr_clears(*t, x, NULL);
    mpfr_free_cache();
}
