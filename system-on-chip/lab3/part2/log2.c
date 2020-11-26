#include "log2.h"

#define DIG 23
#define FRAC_BITS DIG - 1
unsigned ONE = 1 << (DIG - 1);
unsigned TWO = (1 << (DIG - 1)) << 1;
unsigned GE_TWO_MASK = (-1 << (DIG - 1)) << 1;

void mylog2(float x, float *y)
{
#pragma HLS INTERFACE s_axilite port=return
#pragma HLS INTERFACE s_axilite port=y
#pragma HLS INTERFACE s_axilite port=x
	int res_hi = 0;
	unsigned res_lo = 0;
	unsigned long long val = (unsigned)(ONE * x);

	while (val < ONE)
	{
#pragma HLS LOOP_TRIPCOUNT min=0 max=8
		val <<= 1;
		res_hi -= 1;
	}
	while (val & GE_TWO_MASK)
	{
#pragma HLS LOOP_TRIPCOUNT min=0 max=24
		val >>= 1;
		res_hi += 1;
	}

	for (int i = 0; i < FRAC_BITS; i++)
	{
#pragma HLS PIPELINE II=2
		res_lo <<= 1;
		val = (val * val) >> (DIG - 1);
		if (val >= TWO)
		{
			val >>= 1;
			res_lo += 1;
		}
	}

	*y = ((float)res_lo) / ONE + (float)res_hi;
}
