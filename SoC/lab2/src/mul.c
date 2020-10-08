#include "mul.h"
/*
void mul (
  data_t a[N_MAX_SQARED],
  data_t b[N_MAX_SQARED],
  data_t c[N_MAX_SQARED],
  msize_t n) {
#pragma HLS INTERFACE s_axilite port=n
#pragma HLS INTERFACE s_axilite port=a
#pragma HLS INTERFACE s_axilite port=c
#pragma HLS INTERFACE s_axilite port=b

	if (n < 5 || n > 10) return;

	data_t b_copy[N_MAX_SQARED];
	data_t tmp = 0;

	Row: for (uint i = 0; i < n; i++) {
		if (i == n) return;
		Col: for (uint j = 0; j < n; j++) {
#pragma HLS PIPELINE
			  if (j == n) return;
		      tmp=0;

		      if (i == 0) {
		    	  Cache_Col: for(int k = 0; k < n; k++) {
		    		  if (k == n) return;
		    		  b_copy[k*n+j] = b[k*n+j];
		    	  }
		      }

		      Product: for(int k = 0; k < n; k++) {
		    	  if (i == n) return;
		    	  tmp += a[i*n+j] * b_copy[k*n+j];
		      }

		      c[i*n+j] = tmp;
		}
	}
}
*/

void mul (
  data_t a[N_MAX_SQARED],
  data_t b[N_MAX_SQARED],
  data_t c[N_MAX_SQARED],
  msize_t n) {
#pragma HLS INTERFACE s_axilite port=n
#pragma HLS INTERFACE s_axilite port=a
#pragma HLS INTERFACE s_axilite port=c
#pragma HLS INTERFACE s_axilite port=b

	Row: for (msize_t i = 0; i < N_MAX; i++) {
		if (i == n) return;
		Col: for (msize_t j = 0; j < N_MAX; j++) {
#pragma HLS PIPELINE
			  if (j == n) break;
			  data_t tmp = 0;
		      Product: for (msize_t k = 0; k < N_MAX; k++) {
		    	  if (k == n) break;
		    	  tmp += a[i*N_MAX+k] * b[k*N_MAX+j];
		      }

		      c[i*N_MAX+j] = tmp;
		}
	}
}
