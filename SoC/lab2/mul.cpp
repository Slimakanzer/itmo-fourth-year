#include "mul.h"

void mul(
	stream<mdata_t>& a,
	stream<mdata_t>& b,
	stream<mdata_t>& c,
	msize_t n
	) 
{
#pragma HLS INTERFACE axis register both port=b
#pragma HLS INTERFACE axis register both port=c
#pragma HLS INTERFACE axis register both port=n
#pragma HLS INTERFACE axis register both port=a
	mdata_t a_cache[N_MAX][N_MAX], b_cache[N_MAX][N_MAX];
#pragma HLS ARRAY_PARTITION variable=b_cache complete dim=2
#pragma HLS ARRAY_PARTITION variable=a_cache complete dim=2

    Row_cache: for (msize_t i = 0; i < N_MAX; i++) {
		if (i == n) break;
		Col_cache: for (msize_t j = 0; j < N_MAX; j++) {
#pragma HLS PIPELINE
			if (j == n) break;
            a_cache[i][j] = a.read();
            b_cache[i][j] = b.read();
		}
	}

    Row: for (msize_t i = 0; i < N_MAX; i++) {
		if (i == n) break;
		Col: for (msize_t j = 0; j < N_MAX; j++) {
#pragma HLS PIPELINE
			if (j == n) break;

            mdata_t tmp = 0;
		    Product: for (msize_t k = 0; k < N_MAX; k++) {
#pragma HLS UNROLL
		    	if (k == n) break;
		    	tmp += a_cache[i][k] * b_cache[k][j];
		    }
            c.write(tmp);
		}
	}
}
