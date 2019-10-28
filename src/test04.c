#include <cmplx.h>
#include <stdio.h>
#include <math.h>

typedef float cmplx_t[2];

int main(){
	cmplx_t a;
	a[0] = 1;
	a[1] = 5;
	printf("\nfaza = %.2f \n", cmplx_phs(a));
	return 0;
}
