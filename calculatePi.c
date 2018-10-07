#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#include"mpfr.h"
#include<pthread.h>

unsigned long PRECISION = 100;
mpfr_t PI, one;

time_t t_start, t_end;

int main (int argc, char **argv) {

    PRECISION *= 3.35;
    mpfr_set_default_prec(PRECISION);
    mpfr_inits(PI, one, NULL);
    mpfr_set_ui(PI, 0, MPFR_RNDN);
    mpfr_set_ui(one, 1, MPFR_RNDN);
    return (0);
}



}
