#include <iostream>
#include <string.h>
#include "mul.h"

void mat_rand(mdata_t *mat, stream<mdata_t>& str, int n) {
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
    	mdata_t val = rand();
        mat[i*N_MAX+j] = val;
        str << val;
      }
    }
}

void mul_test(
  mdata_t *a,
  mdata_t *b,
  mdata_t *c,
  size_t n) {
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
	mdata_t a[N_MAX_SQUARED];
	mdata_t b[N_MAX_SQUARED];
	mdata_t c_gold[N_MAX_SQUARED];
	int errcnt = 0;

	for (int k = 0; k < 100; k++) {
		stream<mdata_t> a_str;
		stream<mdata_t> b_str;
		stream<mdata_t> c_str;
		n = ((msize_t)rand()) % (N_MAX - N_MIN) + N_MIN; // n = randrange(5..10) ;
		mat_rand(a, a_str, n);
		mat_rand(b, b_str, n);
		mul_test(a, b, c_gold, n);
		mul(a_str, b_str, c_str, n);

	    for (int i = 0; i < n; i++){
	      for (int j = 0; j < n; j++){
	        mdata_t res = c_str.read();
	        mdata_t res_gold = c_gold[i*N_MAX+j];
	        if (res != res_gold) {
	        	errcnt++;
	        	fprintf(stdout, "Test %i failed.\n", k);
	        }
	      }
	    }
	}

	if (errcnt) {
		return 1;
	}
	else {
		fprintf(stdout, "Completed successfully\n");
		return 0;
	}
}
