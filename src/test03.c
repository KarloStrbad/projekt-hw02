#include <cmplx.h>
#include <stdio.h>
#include <math.h>

typedef float cmplx_t[2];

int main(){
	cmplx_t a;
	a[0] = 3;
	a[1] = 4;
	printf("\n|a| = %.2f \n", cmplx_mag(a));
	return 0;
}
