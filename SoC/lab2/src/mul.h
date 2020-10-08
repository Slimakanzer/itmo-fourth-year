#ifndef MUL_H_
#define MUL_H_
#define N_MIN 5
#define N_MAX 10
#define N_MAX_SQARED 100
#include <stdint.h>

typedef int	data_t;
typedef uint8_t msize_t;

void mul (
    data_t a[N_MAX_SQARED],
	data_t b[N_MAX_SQARED],
	data_t c[N_MAX_SQARED],
	msize_t n
  );

#endif
