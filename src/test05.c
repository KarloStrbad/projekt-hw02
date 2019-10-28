#include <cmplx.h>
#include <stdio.h>
#include <math.h>

typedef float cmplx_t[2];

int main(){
	double mag, phs;
	mag = 5;
	phs = M_PI/4;
	printf("\nrealni dio = %.2f \n", cmplx_real(mag, phs));
	return 0;
}
