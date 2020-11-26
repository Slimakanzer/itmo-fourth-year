#ifndef MUL_H_
#define MUL_H_

#define N_MIN 0
#define N_MAX 10
#define N_MAX_SQUARED 100
#include <hls_stream.h>

using namespace hls;

typedef int mdata_t;
typedef unsigned int msize_t;

void mul(
		stream<mdata_t>& a,
		stream<mdata_t>& b,
		stream<mdata_t>& c,
		msize_t n
		);

#endif
