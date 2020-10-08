#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mul.h"

data_t a[N_MAX_SQARED];
data_t b[N_MAX_SQARED];
data_t c[N_MAX_SQARED];
data_t c_gold[N_MAX_SQARED];

void mat_rand(data_t *mat, int n) {
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        mat[i*n+j] = rand();
      }
    }
}

void mul_test(
  data_t *a,
  data_t *b,
  data_t *c,
  msize_t n) {
    for (int i = 0; i < n; i++) {
      for (int j =0; j < n; j++) {
        int sum = 0;
        for (int k = 0; k < n; k++){
          sum += a[i*N_MAX+k] * b[k*N_MAX+j];
        }
        c[i*N_MAX+j] = sum;
      }
    }
  }

int main () {
  unsigned int n;
  for (int k = 0; k < 100; k++) {
    n = ((msize_t)rand()) % 5 + 5; // n = randrange(5..10) ;
    /*mat_rand(a, n);
    mat_rand(b, n);
	*/
    mul_test(a, b, c_gold, n);
    mul(a, b, c, n);

    if (memcmp(c, c_gold, n*n*sizeof(data_t))) {
        fprintf(stdout, "Test %i failed.\n", k);
    }
  }

  fprintf(stdout, "**************\nTest completed\n");
  return 0;
}
