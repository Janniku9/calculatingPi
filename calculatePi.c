#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#include"gmp.h"
#include"mpfr.h"
#include<pthread.h>

#include"calculatePi.h"

unsigned long PRECISION = 10000000;
mpfr_t PI, one;
mpfr_t t1, t2, t3, t4, t5, t6, t7;
int id[] = {0, 1, 2, 3, 4, 5, 6};

time_t t_start, t_end;

pthread_mutex_t lock;

int main (int argc, char **argv) {

    mpfr_set_default_prec(PRECISION*3.35);
    mpfr_inits(t1, t2, t3, t4, t5, t6, t7, PI, one, NULL);
    mpfr_set_ui(PI, 0, MPFR_RNDN);
    mpfr_set_ui(one, 1, MPFR_RNDN);

    pthread_mutex_init(&lock, NULL);

    pthread_t threads[7];

    t_start = time(NULL);

    for (int i = 0; i < 7; i++) {
      pthread_create(&threads[i], NULL, calculate_correct_Term, (void*)&id[i]);
    }

    for(int i=0; i<7; i++) {
      pthread_join(threads[i], NULL);
    }

    t_end = time(NULL);

    mpfr_mul_ui(PI, PI, 4, MPFR_RNDN);

    char *pi_str = malloc(PRECISION+1);
    if(pi_str == NULL) {
        printf("Not enough memory to store PI");
        return 1;
    }

    mpfr_sprintf(pi_str, "%.*R*f", PRECISION, MPFR_RNDN, PI);

    printf("Finished after : %ld seconds\n", (t_end - t_start));

    mpfr_clears(PI, one, NULL);
    mpfr_free_cache();

    FILE *fp = fopen("pi.txt", "w");
    if (fp != NULL)
    {
        fputs(pi_str, fp);
        fclose(fp);
    }

    return (0);
}

void calc(mpfr_t* t, char* x_str, int op, int coeff) {
    mpfr_t x;
    mpfr_set_default_prec(PRECISION * 3.35);
    mpfr_init_set_str(x, x_str, 10, MPFR_RNDN);

    mpfr_atan2(*t, one, x, MPFR_RNDN);
    mpfr_mul_ui(*t, *t, coeff, MPFR_RNDN);

    pthread_mutex_lock(&lock);
    if (op == 1) {
      mpfr_add(PI, PI, *t, MPFR_RNDN);
    } else {
      mpfr_sub(PI, PI, *t, MPFR_RNDN);
    }
    pthread_mutex_unlock(&lock);

    mpfr_clears(*t, x, NULL);
    mpfr_free_cache();
    pthread_exit(NULL);
}

void* calculate_correct_Term (void* id) {
  char x_str[22];

  switch (*(int *)id) {
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
