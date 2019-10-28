#include <cmplx.h>
#include <stdio.h>

typedef float cmplx_t[2];

int main(){
	cmplx_t a, b, c;
	a[0] = 3;
	a[1] = 1;
	b[0] = 4;
	b[1] = 2;
	cmplx_div(a, b, c);
	printf("\nc = %.2f + j*%.2f \n", c[0], c[1]);
	return 0;
}
	
