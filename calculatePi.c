#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#include"mpfr.h"
#include<pthread.h>

#include"calculatePi.h"

unsigned long PRECISION = 100;
mpfr_t PI, one;
mpfr_t t1, t2, t3, t4, t5, t6, t7;

time_t t_start, t_end;

int main (int argc, char **argv) {

    mpfr_set_default_prec(PRECISION*3.35);
    mpfr_inits(t1, t2, t3, t4, t5, t6, t7, PI, one, NULL);
    mpfr_set_ui(PI, 0, MPFR_RNDN);
    mpfr_set_ui(one, 1, MPFR_RNDN);

    t_start = time(NULL);

    for (size_t i = 0; i < 7; i++) {
      calculate_correct_Term (i);
    }

    t_end = time(NULL);

    mpfr_mul_ui(PI, PI, 4, MPFR_RNDN);

    char *pi_str = malloc(PRECISION+1);
    if(pi_str == NULL) {
        printf("Not enough memory to store PI");
        return 1;
    }

    mpfr_sprintf(pi_str, "%.*R*f", PRECISION, MPFR_RNDN, PI);

    printf("Finished after : %sms\n", (t_end - t_start));
    printf("%s\n", pi_str);

    return (0);
}

void calc(mpfr_t* t, char* x_str, int op, int coeff) {
    mpfr_t x;
    mpfr_set_default_prec(PRECISION * 3.35);
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

void calculate_correct_Term (int id) {
  char x_str[22];

  switch (id) {
    case 0:
          sprintf(x_str, "239");
          calc(&t1, x_str, 1, 183);
          break;
    case 1:
          sprintf(x_str, "1023");
          calc(&t2, x_str, 1, 32);
          break;
    case 2:
          sprintf(x_str, "5832");
          calc(&t3, x_str, 2, 68);
          break;
    case 3:
          sprintf(x_str, "113021");
          calc(&t4, x_str, 1, 12);
          break;
    case 4:
          sprintf(x_str, "6826318");
          calc(&t5, x_str, 2, 100);
          break;
    case 5:
          sprintf(x_str, "33366019650");
          calc(&t6, x_str, 2, 12);
          break;
    case 6:
          sprintf(x_str, "43599522992503626068");
          calc(&t7, x_str, 1, 12);
          break;
   default:
          break;
  }
}
